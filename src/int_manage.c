/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:11:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/27 16:59:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		manage_int_neg(int num, int precision, t_arg *s_struct)
{
	s_struct->f_len -= 1;
	s_struct->null_put = precision - ft_strlen_atoi(num) + 1;
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	s_struct->f_len = precision + 1;
}

static void		manage_int_plus(int num, int precision, t_arg *s_struct)
{
	s_struct->null_put = precision - ft_strlen_atoi(num);
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	if (precision > ft_strlen_atoi(num) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
}

void			manage_all_int(int num, int width,
				int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen_atoi(num);
	if (precision > s_struct->f_len && num >= 0)
		manage_int_plus(num, precision, s_struct);
	if (precision > s_struct->f_len - 1 && num < 0)
		manage_int_neg(num, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) &&
	s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen_atoi(num);
}

void			manage_int_put(int num, int width,
				int precision, t_arg *s_struct)
{
	if (s_struct->flag == '-' && num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
	}
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putnbr(num, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 &&
	s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	if (s_struct->flag != '-' && num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
	}
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_putnbr(num, s_struct);
}
