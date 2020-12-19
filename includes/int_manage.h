/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:00:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 19:59:22 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_MANAGE_H
# define INT_MANAGE_H

void			manage_int_width_minus(int num, int width, int precision, t_arg *s_struct);
void			manage_int_zero(int num, int width, t_arg *s_struct);
void			manage_int_width(int num, int width, t_arg *s_struct);
void			manage_int_precesion(int num, int precision, t_arg *s_struct);
void			manage_int_zero_flag_width_precision(int num, int width, int precision, t_arg *s_struct);
void			manage_int_min_flag_width_precision(int num, int width, int precision, t_arg *s_struct);
void			manage_int_width_plus_precision_flags(int num, int width, int precision, t_arg *s_struct);
void			manage_int_width_plus_precision(int num, int width, int precision, t_arg *s_struct);

#endif
