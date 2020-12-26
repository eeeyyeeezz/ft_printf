/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:22:49 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void			manage_fuction(va_list argptr, t_arg *s_struct)
{
	if (s_struct->type == 'd' || s_struct->type == 'i')
		manage_int(argptr, s_struct);
	if (s_struct->type == 'u')
		manage_uns(argptr, s_struct);
	if (s_struct->type == 'c')
		manage_chr(argptr, s_struct);
	if (s_struct->type == 's')
		manage_str(argptr, s_struct);
	if (s_struct->type == 'x' || s_struct->type == 'X')
		manage_hex(argptr, s_struct);
	if (s_struct->type == 'p')
		manage_ptr(argptr, s_struct);
	if (s_struct->type == '%')
		manage_prc(s_struct);
}

int				ft_printf(const char *arr, ...)
{
	int				i;
	static va_list	argptr;
	t_arg			s_struct;

	i = -1;
	s_struct.r_r = 0;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			ft_parser((char *)&arr[i], &s_struct, argptr);
			i += s_struct.count;
			manage_fuction(argptr, &s_struct);
		}
		else
			ft_putchar(arr[i], &s_struct);
	}
	va_end(argptr);
	return (s_struct.r_r);
}
