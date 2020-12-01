/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:42:00 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 16:27:30 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb / 10 > 0)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}
