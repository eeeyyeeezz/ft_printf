/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:09 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/21 16:38:22 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdarg.h>
# include "ft_libft.h"

void		ft_parser_is_zero_zero(const char *arr, t_arg *s_struct);
void		ft_parser_width(const char *arr, t_arg *s_struct, va_list argptr);
void		ft_parser_flags(const char *arr, t_arg *s_struct);
void		ft_parser_count(const char *arr, t_arg *s_struct);
void		ft_parser(const char *arr, t_arg *s_struct, va_list argptr);

#endif
