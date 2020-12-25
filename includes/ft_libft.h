/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:03:03 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 19:19:03 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

typedef	struct		s_arg
{
	int		len;
	int		count;
	int		width;
	int		precision;
	int		zero_flag;
	int		r_r;
	char	flag;
	char	type;
}					t_arg;

void				ft_putchar(char c, t_arg *s_struct);
void				ft_putstr(const char *s, t_arg *s_struct);
void				ft_putnbr(int nb, t_arg *s_struct);
void				ft_putuns(unsigned int nb, t_arg *s_struct);
int					ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_strlen_atoi(int n);
int					ft_strlen_minus(int n);
int					ft_isdigit(int c);
int					ft_istype(int c);

#endif
