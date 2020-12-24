/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:04:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 21:47:45 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MANAGE_H
# define FT_MANAGE_H

void		manage_int(va_list argptr, t_arg *s_struct);
void		manage_str(va_list argptr, t_arg *s_struct);
void		manage_hex(va_list argptr, t_arg *s_struct);
void		manage_uns(va_list argptr, t_arg *s_struct);
void		manage_ptr(va_list argptr, t_arg *s_struct);

#endif
