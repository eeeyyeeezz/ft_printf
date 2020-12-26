/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:52:25 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 18:40:15 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			ft_putchar(char c, t_arg *s_struct)
{
	write(1, &c, 1);
	s_struct->r_r++;
}

void		ft_putstr(const char *s, t_arg *s_struct)
{
	if (s == NULL)
		return ;
	while (*s)
		s_struct->r_r += write(1, &*s++, 1);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_istype(int c)
{
	if ((c >= 'a' && c <= 'z') || c == 'X')
		return (1);
	else
		return (0);
}

int			ft_strlen_minus(int n)
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
