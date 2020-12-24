/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:41:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/24 20:57:35 by gmorra           ###   ########.fr       */
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

#endif
