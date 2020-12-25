/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:38:41 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 20:10:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include <printf.h>

static	void		ft_parser_type(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i]) && arr[i] != '\0'))
	{
		s_struct->count++;
		if (arr[++i] == '%')
		{
			s_struct->type = '%';
			break ;
		}
		else
			s_struct->type = arr[i];
	}
}

static	void		ft_parser_precision(const char *arr,
		t_arg *s_struct, va_list argptr)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i])))
		i++;
	while (ft_isdigit(arr[i - 1]))
		i--;
	if (arr[i - 1] == '.')
		s_struct->precision = ft_atoi((char *)&arr[i]);
	if (s_struct->precision == 0 && arr[i - 1] == '*' && arr[i - 2] == '.'
	&& s_struct->zero_flag == 1)
		s_struct->precision = va_arg(argptr, int);
}

void				ft_parser(const char *arr, t_arg *s_struct, va_list argptr)
{
	s_struct->len = 0;
	s_struct->zero_flag = 0;
	s_struct->precision = 0;
	s_struct->count = 0;
	s_struct->width = 0;
	s_struct->flag = '!';
	ft_parser_type(arr, s_struct);
	ft_parser_width(arr, s_struct, argptr);
	ft_parser_is_zero_zero(arr, s_struct);
	ft_parser_flags(arr, s_struct);
	ft_parser_precision(arr, s_struct, argptr);
}
