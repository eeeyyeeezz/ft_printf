/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manage_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:18:35 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 15:20:51 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			manage_arr_min_flag_width_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if ((width > 0 && precision > 0 && s_struct->flag == '-') ||
	(width > 0 && precision == 0 && s_struct->zero_flag == 1 && s_struct->flag == '-'))
	{
		while (precision-- > 0 && ft_strlen(arr) > precision && arr[i] != '\0')
		{
			ft_putchar(arr[i++]);
			count++;
		}
		if (precision >= ft_strlen(arr))
		{
			ft_putstr(arr);
			count = ft_strlen(arr);
		}
		while (width-- - count > 0)
			ft_putchar(' ');
		s_struct->flag = 'Z';
	}
}

void			manage_arr_width_plus_precision_flag(const char *arr, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if ((width > 0 && precision > 0 && s_struct->flag == '-') ||
	(width > 0 && precision == 0 && s_struct->zero_flag == 1 && s_struct->flag == '-'))
		manage_arr_min_flag_width_precision(arr, width, precision, s_struct);
	else if (width == 0 && precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '!')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}


void			manage_arr_width_plus_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int i;

	i = 0;
	if ((width > 0 && precision > 0 && s_struct->flag == '!') ||
	(width > 0 && precision == 0 && s_struct->zero_flag == 1 && s_struct->flag == '!'))
	{
		if (precision < ft_strlen(arr))
			width += ft_strlen(arr) - precision;
		while (width-- - ft_strlen(arr) > 0)
			ft_putchar(' ');
		while (precision-- > 0 && ft_strlen(arr) > precision && arr[i] != '\0')
			ft_putchar(arr[i++]);
		if (precision >= ft_strlen(arr))
			ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}

void 				manage_chr(va_list argptr, t_arg *s_struct)
{
	char	letter;

	letter = va_arg(argptr, int);
	if (s_struct->width > 0 && s_struct->flag == '!')
	{
		while(--s_struct->width)
			ft_putchar(' ');
	ft_putchar(letter);
	}
	else if (s_struct->width > 0 && s_struct->flag == '-')
	{
		ft_putchar(letter);
		while(--s_struct->width)
			ft_putchar(' ');
	}
	else
		ft_putchar(letter);
}

void 				manage_prc(t_arg *s_struct)
{
	char	letter;

	letter = '%';
	if (s_struct->width > 0 && s_struct->flag == '!')
	{
		while(--s_struct->width)
			ft_putchar(' ');
	ft_putchar(letter);
	}
	else if (s_struct->width > 0 && s_struct->flag == '-')
	{
		ft_putchar(letter);
		while(--s_struct->width)
			ft_putchar(' ');
	}
	else
		ft_putchar(letter);
}
