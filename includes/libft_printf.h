/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:25:43 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/01 19:37:29 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stdarg.h>
# include <printf.h>
# include <unistd.h>

int				ft_printf(const char *arr, ...);
int				manage_int(const char *arr, va_list *argptr);
char			manage_char(va_list *argptr);
char			*manage_str(va_list *argptr);

#endif
