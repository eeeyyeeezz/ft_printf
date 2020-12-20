/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:04:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 20:39:44 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_H
# define MANAGE_H

void		manage_int(va_list *argptr, t_arg *s_struct);
void		manage_str(va_list *argptr, t_arg *s_struct);
void		manage_hex(va_list *argptr, t_arg *s_struct);
void		manage_uns(va_list *argptr, t_arg *s_struct);

#endif
