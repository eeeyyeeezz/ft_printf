/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manage_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:14:40 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 17:32:22 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			hex_word(long num, t_arg *s_struct)
{
	char letter;

	letter = 0;
	if (num >= 0 && num <= 9)
		return (num + 48);
	else if (num == 10)
		letter = s_struct->type == 'x' ? 'a' : 'A';
	else if (num == 11)
		letter = s_struct->type == 'x' ? 'b' : 'B';
	else if (num == 12)
		letter = s_struct->type == 'x' ? 'c' : 'C';
	else if (num == 13)
		letter = s_struct->type == 'x' ? 'd' : 'D';
	else if (num == 14)
		letter = s_struct->type == 'x' ? 'e' : 'E';
	else if (num == 15)
		letter = s_struct->type == 'x' ? 'f' : 'F';
	return (letter);
}

void			ft_puthex(long num, t_arg *s_struct)
{
	int		i;
	int		a;
	char	tmp;
	char	*str;

	i = 0;
	a = 0;
	tmp = 0;
	if (num == 0 && s_struct->precision == 0 && s_struct->zero_flag == 1)
		return ;
	if (!(str = malloc(malloc_count(num))))
		return ;
	if (num == 0)
		ft_putchar('0', s_struct);
	while (num > 0)
	{
		str[i++] = hex_word((num % 16), s_struct);
		num = num / 16;
	}
	i -= 1;
	while (i >= 0)
		ft_putchar(str[i--], s_struct);
	free(str);
	str = NULL;
}

void			mg_hex_zero_flag_width_precision(long num, int width,
int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
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
	ft_puthex(num, s_struct);
	s_struct->flag = 'Z';
}

void			mg_hex_min_flag_width_precision(long num, int width,
int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
		width -= 1;
	}
	while (precision-- > malloc_count(num))
		ft_putchar('0', s_struct);
	ft_puthex(num, s_struct);
	if (true_precision > malloc_count(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ', s_struct);
	while (width-- - malloc_count(num) > 0 &&
	true_precision < malloc_count(num))
		ft_putchar(' ', s_struct);
	s_struct->flag = 'Z';
}

void			mg_hex_width_plus_precision_flags(long num, int width,
int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		mg_hex_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		mg_hex_min_flag_width_precision(num, width, precision, s_struct);
}
