/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:24:37 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 18:27:23 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_MANAGE_H
# define ARR_MANAGE_H

void			manage_str_put(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_all_str(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_null_str(const char *arr, int width, int precision, t_arg *s_struct);

void			mg_arr_min_flag_width_precision(const char *arr, int width,
				int precision, t_arg *s_struct);
void			mg_arr_width_plus_precision_flag(const char *arr, int width,
				int precision, t_arg *s_struct);
void			mg_arr_width_plus_precision(const char *arr, int width,
				int precision, t_arg *s_struct);
void			mg_arr_width_minus(const char *arr, int width,
				int precision, t_arg *s_struct);
void			mg_arr_width(const char *arr, int width, t_arg *s_struct);
void			mg_arr_precesion(const char *arr,
				int precision, t_arg *s_struct);
void			manage_chr(va_list argptr, t_arg *s_struct);
void			manage_prc(t_arg *s_struct);

#endif
