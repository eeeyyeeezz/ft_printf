/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/12 19:39:16 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/libft.h"
// #include "includes/libft_printf.h"
#include <printf.h>
#include <unistd.h>
#include <stdlib.h>

typedef		struct s_arg
{
	int		len;
	int		count;
	int		width;
	int		precision;
	char	dot;
	char	flag;
	char	star;
	char	type;
}					t_arg;

#pragma region libft
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

void		ft_putnbr(int nb)
{
	int *ptr;

	ptr = 0;
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

size_t		ft_strlen(const char *s)
{
	int a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a] != 0)
		a++;
	return (a);
}

int		ft_atoi(const char *str)		// атой без обработки отрицательных значений
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

static int			aabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int			ft_strlen_atoi(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	int		len;
	char	*itoa;

	len = ft_strlen_atoi(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (itoa == NULL)
		return (NULL);
	itoa[len] = '\0';
	if (n < 0)
		itoa[0] = '-';
	if (n == 0)
		itoa[0] = '0';
	while (n != 0)
	{
		--len;
		itoa[len] = aabs(n % 10) + 48;
		n = n / 10;
	}
	return (itoa);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_istype(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

#pragma endregion libft

#pragma region PARSER
void		ft_parser_width(const char *arr, t_arg *s_struct)
{
	int jump;

	jump = 1;
	while (arr[jump] == '0' || arr[jump] == '-')
		jump++;
	s_struct->width = ft_atoi((char *)&arr[jump]);
}

void		ft_parser_flags(const char *arr, t_arg *s_struct)
{
	int flag;
	int a;

	flag = 0;
	a = 1;
	if (arr[1] == '0' || arr[1] == '-')
	{
		while (arr[a] == '0' || arr[a] == '-')
		{
			if (arr[a] == '-')
				flag = 1;
			s_struct->flag = '0';
			a++;
		}
	}
	if (flag == 1)
		s_struct->flag = '-';
}

void		ft_parser_count(const char *arr, t_arg *s_struct)
{
	while (!(ft_istype(arr[s_struct->count])))
		s_struct->count++;
}

void		ft_parser_type(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i])))
		i++;
	s_struct->type = arr[i];
}

void		ft_parser_precision(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i])))
		i++;
	while (ft_isdigit(arr[i - 1]))
		i--;
	if (arr[i - 1] == '.')
		s_struct->precision = ft_atoi((char *)&arr[i]);
}

void		ft_parser(const char *arr, t_arg *s_struct)
{
	ft_parser_flags(arr, s_struct);
	ft_parser_width(arr, s_struct);
	ft_parser_precision(arr, s_struct);
	ft_parser_type(arr, s_struct);
	ft_parser_count(arr, s_struct);
	printf("type [%c] flag [%c] width [%d] precision [%d] count [%d] || ", s_struct->type, s_struct->flag, s_struct->width, s_struct->precision, s_struct->count);
}
#pragma endregion PARSER

#pragma region INT_MANAGE
void			manage_int_width_minus(int num, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag == '-')
	{
		ft_putnbr(num);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void			manage_int_zero(int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width != precision && width > precision && s_struct->flag == '0')
	{
		if (num < 0 && s_struct->flag == '0')
		{
			ft_putchar('-');
			width -= 1;
			num *= -1;
		}
		while (width - ft_strlen_atoi(num) > 0)
		{
			ft_putchar('0');
			width--;
		}
		ft_putnbr(num);
		s_struct->flag = 'Z';
	}
}

void			manage_int_width(int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag != 'Z')
	{
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		ft_putnbr(num);
		s_struct->flag = 'Z';
	}
}

void		manage_int_precesion(int num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > ft_strlen_atoi(num) && width < precision) || width == precision)
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision - ft_strlen_atoi(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_putnbr(num);
		s_struct->flag = 'Z';
	}
}

void			manage_int_width_plus_precision(int num, int width, int precision, t_arg *s_struct)
{
	if (width > precision && s_struct->flag != 'Z')
	{
		while (width > precision)
		{
			ft_putchar(' ');
			width--;
		}
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision > ft_strlen_atoi(num))
		{
			ft_putchar('0');
			precision--;
		}
		ft_putnbr(num);
		s_struct->flag = 'Z';
	}
}

void			manage_int_minus(int num, int width)
{
	ft_putnbr(num);
	while (width - ft_strlen_atoi(num) > 0)
	{
		ft_putchar(' ');
		width--;
	}
}

#pragma endregion INT_MANAGE

void 				manage_int(va_list *argptr, t_arg *s_struct)
{
	int		num;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(*argptr, int);
	manage_int_width_minus(num, width, precision, s_struct);
	manage_int_zero(num, width, s_struct);
	manage_int_width(num, width, s_struct);
	manage_int_precesion(num, precision, s_struct);
	manage_int_width_plus_precision(num, width, precision, s_struct);
	if (s_struct->flag == '-')
		manage_int_minus(num, width);
	if (s_struct->flag == '!')
		ft_putnbr(num);
}


void			manage_fuction(const char *procent, va_list *argptr, t_arg *s_struct)
{
	int i;

	i = -1;
	while (procent[++i])
	{
		if (procent[i] == 'd' || procent[i] == 'i')
		{
			manage_int(argptr, s_struct);
			break ;
		}
	}
}

int				ft_printf(const char *arr, ...)
{
	int		i;
	va_list	argptr;
	t_arg 	pars;

	i = -1;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			pars.count = 0;
			pars.flag = '!';
			pars.width = 0;
			pars.precision = 0;
			ft_parser((char *)&arr[i], &pars);
			i += pars.count;
			manage_fuction((char *)&arr[i], &argptr, &pars);
		}
		else
		{
			pars.len++;
			ft_putchar(arr[i]);
		}
	}
	va_end(argptr);
	return (pars.len);
}
