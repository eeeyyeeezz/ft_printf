/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:41:24 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 21:50:51 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNS_MANAGE_H
# define UNS_MANAGE_H

void			manage_uns_width_minus(unsigned int num, int width,
				int precision, t_arg *s_struct);
void			manage_uns_zero(unsigned int num, int width, t_arg *s_struct);
void			manage_uns_width(unsigned int num, int width, t_arg *s_struct);
void			manage_uns_precesion(unsigned int num,
				int precision, t_arg *s_struct);
void			manage_uns_zero_flag_width_precision(unsigned int num,
				int width, int precision, t_arg *s_struct);
void			manage_uns_min_flag_width_precision(unsigned int num, int width,
				int precision, t_arg *s_struct);
void			manage_uns_width_plus_precision_flags(unsigned int num,
				int width, int precision, t_arg *s_struct);
void			manage_uns_width_plus_precision(unsigned int num, int width,
				int precision, t_arg *s_struct);

#endif
