/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:56:39 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 21:49:46 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTR_MANAGE_H
# define PTR_MANAGE_H

char		ptr_word(long num);
void		ft_putptr(long num, t_arg *s_struct);
void		mg_ptr_zero_flag_width_precision(long num, int width,
			int precision, t_arg *s_struct);
void		mg_ptr_min_flag_width_precision(long num, int width,
			int precision, t_arg *s_struct);
void		mg_ptr_width_plus_precision_flags(long num, int width,
			int precision, t_arg *s_struct);
void		mg_ptr_width_plus_precision(long num, int width,
			int precision, t_arg *s_struct);
void		mg_ptr_width_minus(long num, int width,
			int precision, t_arg *s_struct);
void		mg_ptr_zero(long num, int width, t_arg *s_struct);
void		mg_ptr_width(long num, int width, t_arg *s_struct);
void		mg_ptr_precesion(long num, int precision, t_arg *s_struct);

#endif
