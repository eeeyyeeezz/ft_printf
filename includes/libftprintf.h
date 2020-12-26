/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:41:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 21:15:05 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "ft_libft.h"
# include "ft_parser.h"
# include "int_manage.h"
# include "ptr_manage.h"
# include "uns_manage.h"
# include "hex_manage.h"
# include "arr_manage.h"
# include "ft_manage.h"
# include <printf.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *arr, ...);
void			manage_fuction(va_list argptr, t_arg *s_struct);
int				malloc_count(long num);
void			manage_all_int(int num, int width, int precision, t_arg *s_struct);
void			manage_int_put(int num, int width, int precision, t_arg *s_struct);
void			manage_all_uns(unsigned int num, int width, int precision, t_arg *s_struct);
void			manage_uns_put(unsigned int num, int width, int precision, t_arg *s_struct);
void			manage_uns_neg(unsigned int num, int precision, t_arg *s_struct);
void			manage_uns_plus(unsigned int num, int precision, t_arg *s_struct);
void			manage_all_hex(unsigned int hex, int width, int precision, t_arg *s_struct);
void			manage_hex_put(unsigned int hex, int width, int precision, t_arg *s_struct);

#endif
