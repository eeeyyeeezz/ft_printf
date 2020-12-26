/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manage_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:54:53 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 21:52:36 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			ptr_word(long num)
{
	char letter;

	letter = '\0';
	if (num >= 0 && num <= 9)
		return (num + 48);
	else if (num == 10)
		letter = 'a';
	else if (num == 11)
		letter = 'b';
	else if (num == 12)
		letter = 'c';
	else if (num == 13)
		letter = 'd';
	else if (num == 14)
		letter = 'e';
	else if (num == 15)
		letter = 'f';
	return (letter);
}

void			mg_ptr_zero_flag_width_precision(long num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	width -= 2;
	if (precision > malloc_count(num) && num < 0 && s_struct->flag == '0')
		width -= 1;
	if (precision > malloc_count(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ', s_struct);
		s_struct->flag = 'A';
	}
	while (width-- > malloc_count(num) && s_struct->flag == '0')
		ft_putchar(' ', s_struct);
	if (num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
		width -= 1;
	}
	while (precision-- > malloc_count(num))
		ft_putchar('0', s_struct);
	ft_putptr(num, s_struct);
	s_struct->flag = 'Z';
}

void			mg_ptr_min_flag_width_precision(long num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	width -= 2;
	if (num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
		width -= 1;
	}
	while (precision-- > malloc_count(num))
		ft_putchar('0', s_struct);
	ft_putptr(num, s_struct);
	if (true_precision > malloc_count(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ', s_struct);
	while (width-- - malloc_count(num) > 0 &&
	true_precision < malloc_count(num))
		ft_putchar(' ', s_struct);
	s_struct->flag = 'Z';
}

void			mg_ptr_width_plus_precision_flags(long num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		mg_hex_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		mg_hex_min_flag_width_precision(num, width, precision, s_struct);
}
