/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:54:07 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 22:30:54 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_strlen_atoi(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

void		ft_putnbr(int nb, t_arg *s_struct)
{
	int *ptr;

	ptr = 0;
	if (nb == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		return ;
	if (nb < 0 && nb != -2147483648)
	{
		s_struct->r_r += write(1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr("-2147483648", s_struct);
	else if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10, s_struct);
		s_struct->r_r += ft_putchar(nb % 10 + 48);
	}
	else
		s_struct->r_r += ft_putchar(nb + 48);
}

int			ft_strlen(const char *s)
{
	int a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a] != 0)
		a++;
	return (a);
}

int			ft_atoi(const char *str)
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

void		ft_putuns(unsigned int nb, t_arg *s_struct)
{
	int *ptr;

	ptr = 0;
	if (nb == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		return ;
	else if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10, s_struct);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}
