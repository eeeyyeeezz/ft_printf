/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manage_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:19:01 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 23:20:19 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			manage_arr_width_minus(const char *arr, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen(arr) && width > precision && s_struct->flag == '-')
	{
		ft_putstr(arr);
		while (width - ft_strlen(arr))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void			manage_arr_width(const char *arr, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen(arr) && width > precision && s_struct->flag != 'Z')
	{
		while (width-- - ft_strlen(arr) && s_struct->flag != '0')
			ft_putchar(' ');
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
	if (s_struct->zero_flag == 1 && s_struct->precision == 0)
		s_struct->flag = 'Z';
	else if ((width == ft_strlen(arr) && width < ft_strlen(arr)) && s_struct->flag != 'Z')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}

void		manage_arr_precesion(const char *arr, int precision, t_arg *s_struct)
{
	int i;
	int width;

	i = 0;
	width = s_struct->width;
	if ((precision < ft_strlen(arr) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		while (precision-- > 0 && arr[i] != '\0')
			ft_putchar(arr[i++]);
		s_struct->flag = 'Z';
	}
	else if ((precision >= ft_strlen(arr) || precision < ft_strlen(arr)) && s_struct->flag != 'Z')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}
