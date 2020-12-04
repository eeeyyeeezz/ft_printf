/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:25:43 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/03 16:17:31 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stdarg.h>
# include <printf.h>
# include <unistd.h>

typedef		struct s_arg
{
	int		count;
	char	dot;
	char	flag;
}					t_arg;

int				ft_printf(const char *arr, ...);
int				ft_parser(const char *arr);
int				manage_int(const char *arr, va_list *argptr);
void			manage_fuction(const char *procent, va_list *argptr, struct s_arg);

#endif
