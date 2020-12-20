/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:17:16 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 17:17:33 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			malloc_count(long num)
{
	int count;

	count = 1;
	while(num >= 16)
	{
		count++;
		num = num / 16;
	}
	return (count);
}
