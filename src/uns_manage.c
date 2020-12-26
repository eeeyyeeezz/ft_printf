/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:13:13 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:44:33 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int			ft_strlen_uns(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

void				manage_uns_plus(unsigned int num,
					int precision, t_arg *s_struct)
{
	s_struct->null_put = precision - ft_strlen_uns(num);
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	if (precision > ft_strlen_uns(num) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
}

void				manage_all_uns(unsigned int num, int width,
					int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen_uns(num);
	if (precision > s_struct->f_len && num >= 0)
		manage_uns_plus(num, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) &&
	s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen_uns(num);
}

void				manage_uns_put(unsigned int num, int width,
					int precision, t_arg *s_struct)
{
	if (num == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putuns(num, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0
	&& s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_putuns(num, s_struct);
}
