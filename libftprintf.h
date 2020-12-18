/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:28:14 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/17 14:42:17 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

typedef		struct s_arg
{
	int		len;
	int		count;
	int		width;
	int		precision;
	char	flag;
	char	type;
}					t_arg;

void		ft_putchar(char c);
int			ft_toupper(int c);
void		ft_putstr(char *s);
void		ft_putnbr(int nb);
int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
int			ft_istype(int c);
void		ft_parser(const char *arr, t_arg *s_struct, va_list *argptr);
void 		manage_int(va_list *argptr, t_arg *s_struct);
void 		manage_string(va_list *argptr, t_arg *s_struct);
void		manage_hex(va_list *argptr, t_arg *s_struct);
void 		manage_pointers(va_list *argptr, t_arg *s_struct);
void		manage_fuction(const char *procent, va_list *argptr, t_arg *s_struct);
int			ft_printf(const char *arr, ...);


#endif
