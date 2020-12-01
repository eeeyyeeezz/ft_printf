/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manages.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:52:03 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/01 18:58:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libft_printf.h"

int				manage_int(const char *arr, va_list *argptr)
{
	int		i;
	int		num;

	(void)arr;
	i = 0;
	num = va_arg(*argptr, int);
	ft_putnbr_fd(num, 1);
	return (num);
}

char			manage_char(va_list *argptr)
{
	char c_char;
	int count;

	count = 0;
	c_char = va_arg(*argptr, int);
	ft_putchar_fd(c_char, 1);
	return (c_char);
}

char		*manage_str(va_list *argptr)
{
	char *arr;

	arr = va_arg(*argptr, char*);
	ft_putstr_fd(arr, 1);
	return (arr);
}
