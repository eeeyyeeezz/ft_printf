/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/01 19:36:39 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/libft_printf.h"

typedef struct	s_args
{
	int index;
	char c_char;
}				t_args;

void			manage_fuction(const char *procent, va_list *argptr)
{
	// int j_jump;
	int i;

	// j_jump = 0;
	i = 0;
	// сделай тут обработку флагов до d, c, s, etc.
	if (procent[i + 1] == 'd') 					// Функция обработки %d (int)
		manage_int((char *)&procent[i], &*argptr);
	else if (procent[i + 1] == 'c')
		manage_char(&*argptr);
	else if (procent[i + 1] == 's')
		manage_str(&*argptr);
}

int				ft_printf(const char *arr, ...)
{
	va_list argptr;
	int		i;
	// int		jump;
	int		len;

	// jump = 0;
	i = -1;
	len = 0;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			manage_fuction((char *)&arr[i], &argptr/*, int jump*/);
			i += 2;   // подсчет флаги не флаги и в плюс
		}
		write(1, &arr[i], 1);
	}
	va_end(argptr);
	return (len);
}
