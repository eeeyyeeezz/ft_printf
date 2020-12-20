/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_manage_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:43:36 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 18:44:37 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			manage_uns_width_minus(unsigned int num, int width, int precision, t_arg *s_struct)
{
	if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag == '-')
	{
		ft_putuns(num, s_struct);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void			manage_uns_zero(unsigned int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width != precision && width > precision && s_struct->flag == '0')
	{
		while (width - ft_strlen_atoi(num) > 0)
		{
			ft_putchar('0');
			width--;
		}
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			manage_uns_width(unsigned int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag != 'Z')
	{
		if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
		while (width - ft_strlen_atoi(num) && s_struct->flag != '0')
		{
			ft_putchar(' ');
			width--;
		}
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen_atoi(num) && width < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void		manage_uns_precesion(unsigned int num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > ft_strlen_atoi(num) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		while (precision - ft_strlen_atoi(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((precision == ft_strlen_atoi(num) || precision < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
}
