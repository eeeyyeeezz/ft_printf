/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:14:15 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:55:26 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char			hex_word(long num, t_arg *s_struct)
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

static void			ft_puthex(long num, t_arg *s_struct)
{
	int		i;
	int		a;
	char	tmp;
	char	str[malloc_count(num) + 1];

	i = 0;
	a = 0;
	tmp = 0;
	if (num == 0 && s_struct->precision == 0 && s_struct->zero_flag == 1)
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
}

static void			manage_hex_plus(unsigned int hex,
					int precision, t_arg *s_struct)
{
	s_struct->null_put = precision - malloc_count(hex);
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	if (precision > malloc_count(hex) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
}

void				manage_all_hex(unsigned int hex, int width,
					int precision, t_arg *s_struct)
{
	s_struct->f_len = malloc_count(hex);
	if (precision > s_struct->f_len && hex >= 0)
		manage_hex_plus(hex, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) &&
	s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - malloc_count(hex);
}

void				manage_hex_put(unsigned int hex, int width,
					int precision, t_arg *s_struct)
{
	if (hex == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_puthex(hex, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 &&
	s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_puthex(hex, s_struct);
}
