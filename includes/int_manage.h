/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:00:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 20:24:38 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_MANAGE_H
# define INT_MANAGE_H


void			manage_all_int(int num, int width, int precision, t_arg *s_struct);
void			manage_int_put(int num, int width, int precision, t_arg *s_struct);
void			manage_all_uns(unsigned int num, int width, int precision, t_arg *s_struct);
void			manage_uns_put(unsigned int num, int width, int precision, t_arg *s_struct);
void			manage_uns_neg(unsigned int num, int precision, t_arg *s_struct);
void			manage_uns_plus(unsigned int num, int precision, t_arg *s_struct);
void			manage_all_hex(unsigned int hex, int width, int precision, t_arg *s_struct);
void			manage_hex_put(unsigned int hex, int width, int precision, t_arg *s_struct);

void			mg_int_width_minus(int num, int width,
				int precision, t_arg *s_struct);
void			mg_int_zero(int num, int width, t_arg *s_struct);
void			mg_int_width(int num, int width, t_arg *s_struct);
void			mg_int_precesion(int num, int precision, t_arg *s_struct);
void			mg_int_zero_flag_width_precision(int num, int width,
				int precision, t_arg *s_struct);
void			mg_int_min_flag_width_precision(int num, int width,
				int precision, t_arg *s_struct);
void			mg_int_width_plus_precision_flags(int num, int width,
				int precision, t_arg *s_struct);
void			mg_int_width_plus_precision(int num, int width,
				int precision, t_arg *s_struct);

#endif
