/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:24:37 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 23:26:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_MANAGE_H
# define ARR_MANAGE_H

void			manage_arr_min_flag_width_precision(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_arr_width_plus_precision_flag(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_arr_width_plus_precision(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_arr_width_minus(const char *arr, int width, int precision, t_arg *s_struct);
void			manage_arr_width(const char *arr, int width, t_arg *s_struct);
void			manage_arr_precesion(const char *arr, int precision, t_arg *s_struct);

#endif