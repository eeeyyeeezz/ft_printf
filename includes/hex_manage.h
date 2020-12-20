/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:21:15 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 17:24:32 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_MANAGE_H
# define HEX_MANAGE_H
# include "ft_libft.h"

char		hex_word(long num, t_arg *s_struct);
void		ft_puthex(long num, t_arg *s_struct);
void		manage_hex_zero_flag_width_precision(long num, int width, int precision, t_arg *s_struct);
void		manage_hex_min_flag_width_precision(long num, int width, int precision, t_arg *s_struct);
void		manage_hex_width_plus_precision_flags(long num, int width, int precision, t_arg *s_struct);
void		manage_hex_width_plus_precision(long num, int width, int precision, t_arg *s_struct);
void		manage_hex_width_minus(long num, int width, int precision, t_arg *s_struct);
void		manage_hex_zero(long num, int width, t_arg *s_struct);
void		manage_hex_width(long num, int width, t_arg *s_struct);
void		manage_hex_precesion(long num, int precision, t_arg *s_struct);

#endif
