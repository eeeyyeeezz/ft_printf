/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:49 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 17:13:47 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void 				manage_int(va_list *argptr, t_arg *s_struct)
{
	int		num;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(*argptr, int);
	manage_int_width_plus_precision_flags(num, width, precision, s_struct);
	manage_int_width_plus_precision(num, width, precision, s_struct);
	manage_int_width_minus(num, width, precision, s_struct);
	manage_int_zero(num, width, s_struct);
	manage_int_width(num, width, s_struct);
	manage_int_precesion(num, precision, s_struct);
}
