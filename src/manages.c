/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manages.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:52:03 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/02 16:01:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_printf.h"

int				manage_int(const char *arr, va_list *argptr)
{
	int		i;
	int		num;

	(void)arr;
	i = 0;
	num = va_arg(*argptr, int);
	ft_putnbr_fd(num, 1);
	return (num);
}
