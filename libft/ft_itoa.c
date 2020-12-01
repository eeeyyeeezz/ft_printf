/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:08 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/06 18:34:14 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			aabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int			ft_strlen_atoi(int n)
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

char				*ft_itoa(int n)
{
	int		len;
	char	*itoa;

	len = ft_strlen_atoi(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (itoa == NULL)
		return (NULL);
	itoa[len] = '\0';
	if (n < 0)
		itoa[0] = '-';
	if (n == 0)
		itoa[0] = '0';
	while (n != 0)
	{
		--len;
		itoa[len] = aabs(n % 10) + 48;
		n = n / 10;
	}
	return (itoa);
}
