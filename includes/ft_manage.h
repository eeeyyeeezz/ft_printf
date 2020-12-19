/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:04:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 23:18:08 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_H
# define MANAGE_H
# include "int_manage.h"

void		manage_int(va_list *argptr, t_arg *s_struct);
void		manage_string(va_list *argptr, t_arg *s_struct);

#endif
