/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:41:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 20:36:43 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "ft_libft.h"
# include "ft_parser.h"
# include "int_manage.h"
# include "ft_manage.h"
# include <printf.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *arr, ...);

#endif
