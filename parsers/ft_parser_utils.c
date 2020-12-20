/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:43:48 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 20:47:50 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

void		ft_parser_procent(const char *arr, t_arg *s_struct)
{
	if (arr[1] == '%')
		s_struct->type = '%';
}

void		ft_parser_is_zero_zero(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (arr[i] && !(ft_istype(arr[i])))
	{
		if (arr[i] == '.')
			s_struct->zero_flag = 1;
		i++;
	}
}

void		ft_parser_width(const char *arr, t_arg *s_struct, va_list *argptr)
{
	int jump;

	jump = 1;
	while (arr[jump] == '0' || arr[jump] == '-')
		jump++;
	s_struct->width = ft_atoi((char *)&arr[jump]);
	if (s_struct->width == 0 && arr[jump] == '*')
	{
		s_struct->width = va_arg(*argptr, int);
		if (s_struct->width < 0)
			s_struct->width *= -1;
	}
}

void		ft_parser_flags(const char *arr, t_arg *s_struct)
{
	int flag;
	int a;

	flag = 0;
	a = 1;
	if (arr[1] == '0' || arr[1] == '-')
	{
		while (arr[a] == '0' || arr[a] == '-')
		{
			if (arr[a] == '-')
				flag = 1;
			s_struct->flag = '0';
			a++;
		}
	}
	if (flag == 1)
		s_struct->flag = '-';
}

void		ft_parser_count(const char *arr, t_arg *s_struct)
{
	while (!(ft_istype(arr[s_struct->count])))
		s_struct->count++;
}
