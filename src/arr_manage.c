/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:59:45 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:37:13 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			manage_all_str(const char *arr, int width,
	int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen(arr);
	if (precision < 0)
	{
		s_struct->zero_flag = 0;
		s_struct->precision = 0;
	}
	if (precision < ft_strlen(arr) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
	if ((s_struct->zero_flag == 0 || precision < 0) &&
	s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen(arr);
}

void			manage_null_str(const char *arr, int width,
				int precision, t_arg *s_struct)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	arr = "(null)";
	s_struct->f_len = ft_strlen(arr);
	if (precision < ft_strlen(arr) &&
	s_struct->zero_flag == 1 && precision >= 0)
		s_struct->f_len = precision;
	while (s_struct->flag == '-' && precision-- > 0 && arr[i] != '\0')
	{
		ft_putchar(arr[i++], s_struct);
		flag = 1;
	}
	if (s_struct->flag == '-' && s_struct->f_len != 0 && flag == 0)
		ft_putstr(arr, s_struct);
	while (width-- > s_struct->f_len)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag != '-' &&
	s_struct->zero_flag == 0 && s_struct->f_len != 0)
		ft_putstr(arr, s_struct);
}

void			manage_str_put(const char *arr, int width,
				int precision, t_arg *s_struct)
{
	int i;

	i = 0;
	if (precision < ft_strlen(arr) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
	while (s_struct->flag == '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag == '-' && s_struct->zero_flag == 0)
		ft_putstr(arr, s_struct);
	while (width-- > s_struct->f_len)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag != '-' && s_struct->zero_flag == 0)
		ft_putstr(arr, s_struct);
}

void			manage_chr(va_list argptr, t_arg *s_struct)
{
	char	letter;

	letter = va_arg(argptr, int);
	if (s_struct->width > 0 && s_struct->flag == '!')
	{
		while (--s_struct->width)
			ft_putchar(' ', s_struct);
		ft_putchar(letter, s_struct);
	}
	else if (s_struct->width > 0 && s_struct->flag == '-')
	{
		ft_putchar(letter, s_struct);
		while (--s_struct->width)
			ft_putchar(' ', s_struct);
	}
	else
		ft_putchar(letter, s_struct);
}

void			manage_prc(t_arg *s_struct)
{
	if (s_struct->width > 0 && s_struct->flag == '!')
	{
		while (--s_struct->width)
			ft_putchar(' ', s_struct);
		ft_putchar('%', s_struct);
		s_struct->flag = 'Z';
	}
	if (s_struct->width > 0 && s_struct->flag == '0')
	{
		while (--s_struct->width)
			ft_putchar('0', s_struct);
		ft_putchar('%', s_struct);
		s_struct->flag = 'Z';
	}
	else if (s_struct->width > 0 && s_struct->flag == '-')
	{
		ft_putchar('%', s_struct);
		while (--s_struct->width)
			ft_putchar(' ', s_struct);
		s_struct->flag = 'Z';
	}
	else if (s_struct->flag != 'Z')
		ft_putchar('%', s_struct);
}
