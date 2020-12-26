/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:15:08 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:54:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char		ptr_word(long num)
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

static void		ft_putptr(long num, t_arg *s_struct)
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
	s_struct->r_r += write(1, "0x", 2);
	if (num == 0)
		ft_putchar('0', s_struct);
	while (num > 0)
	{
		str[i++] = ptr_word((num % 16));
		num = num / 16;
	}
	i -= 1;
	while (i >= 0)
		ft_putchar(str[i--], s_struct);
}

static void		manage_ptr_plus(long ptr, int precision, t_arg *s_struct)
{
	s_struct->null_put = precision - malloc_count(ptr);
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	if (precision > malloc_count(ptr) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
}

void			manage_all_ptr(long ptr, int width,
				int precision, t_arg *s_struct)
{
	s_struct->f_len = malloc_count(ptr);
	if (precision > s_struct->f_len && ptr >= 0)
		manage_ptr_plus(ptr, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) &&
	s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - malloc_count(ptr);
}

void			manage_ptr_put(long ptr, int width,
				int precision, t_arg *s_struct)
{
	width -= 2;
	if (ptr == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putptr(ptr, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 &&
	s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_putptr(ptr, s_struct);
}
