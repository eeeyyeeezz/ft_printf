/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:52:25 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 19:32:12 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

void		ft_putstr(const char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_istype(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
