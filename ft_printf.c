/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/09 19:07:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/libft.h"
// #include "includes/libft_printf.h"
#include <printf.h>
#include <unistd.h>
#include <stdlib.h>

typedef		struct s_arg
{
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

static int			ft_strlen_atoi_fixed(int n)		// изменил на то что если int n = 0 то вернуть 0 надеюсь итоа не умрет от этого иначе другую функцию делать
{
	int len;

	len = 0;
	if (n == 0)
		return (0);
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

	len = ft_strlen_atoi_fixed(n);
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
	if (c >= '1' && c <= '9')
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

/*
Parsers
*/

void		ft_parser(const char *arr, t_arg *j)  // обработка всех флагов и запись в стракт результаты
{
	int	count_jump;
	int jump;
	int	flag;
	int i;

	j->count = 0;
	i = 0;
	count_jump = 0;
	flag = 0;
	jump = 0;
	if (arr[1] == '0' || arr[1] == '-')			// сделать if вхождение если arr[1] == flag тогда заходить в while
	{
		i += 1;
		while (arr[i] == '0' || arr[i] == '-')				// если минус среди нолей счетчик смэрть		|| сделать ft_strchr поиск минуса?
		{
			if (arr[i] == '-')
				flag = 1;
			j->flag = '0';
			count_jump++;
			jump++;
			i++;
			// printf("fuck me! ");
		}
	}
	if (flag == 1)
		j->flag = '-';
	while (!(ft_istype(arr[i])))
		i++;
	j->type = arr[i];
	while (ft_isdigit(arr[i - 1]))
		i--;
	if (arr[i - 1] == '.')
			j->precision = ft_atoi((char *)&arr[i]);
	while (arr[i - 2] == '.')
	{
		count_jump++;			// tak ? ili kak?
		i--;
	}
	if (arr[1] != '0' && arr[1] != '-')				// обработка ширины
		j->width = ft_atoi((char *)&arr[jump + 1]);
	else
		j->width = ft_atoi((char *)&arr[jump]);
	j->count += (count_jump + 2) + ft_strlen_atoi_fixed(j->precision) + ft_strlen_atoi_fixed(j->width);		// тут добавил + 2 в начале мб неправильно || походу правильно хз зачем правда
	printf("type [%c] flag [%c] width [%d] precision [%d] count [%d] || ", j->type, j->flag, j->width, j->precision, j->count);
}

/*
Obrabotka
*/

void			manage_int_minus(int num, int width)
{
	ft_putnbr(num);
	while (width - ft_strlen_atoi_fixed(num) > 0)
	{
		ft_putchar(' ');
		width--;
	}
}

void			manage_int_zero(int num, int width, t_arg *s_struct)
{
	if (num < 0 && s_struct->flag == '0')
	{
		ft_putchar('-');
		num *= -1;
	}
	while (width - ft_strlen_atoi_fixed(num) > 0)
	{
		ft_putchar('0');
		width--;
	}
	ft_putnbr(num);
}

void			manage_int_width(int num, int width, t_arg *s_struct)
{
	while (width - ft_strlen_atoi_fixed(num))
	{
		ft_putchar(' ');
		width--;
	}
	s_struct->flag = '!';
}

void			manage_int_width_minus(int num, int width, t_arg *s_struct)
{
	ft_putnbr(num);
	while (width - ft_strlen_atoi_fixed(num))
	{
		ft_putchar(' ');
		width--;
	}
	s_struct->flag = 'Z';
}

int				manage_int(va_list *argptr, t_arg *s_struct)
{
	int		num;
	int		width;

	width = s_struct->width;
	num = va_arg(*argptr, int);
	if (width > ft_strlen_atoi_fixed(num) && s_struct->flag == '-')
		manage_int_width_minus(num, width, s_struct);
	else if (width > ft_strlen_atoi_fixed(num))
		manage_int_width(num, width, s_struct);
	if (s_struct->flag == '-')
		manage_int_minus(num, width);
	else if (s_struct->flag == '0')
		manage_int_zero(num, width, s_struct);
	if (s_struct->flag == '!')
		ft_putnbr(num);
	return (num);
}


void			manage_fuction(const char *procent, va_list *argptr, t_arg *j)
{
	int i;

	i = -1;
	while (procent[++i])
	{
		if (procent[i] == 'd' || procent[i] == 'i')
		{
			manage_int(argptr, j);
			break ;
		}
	}
	j->count = j->count + i;		// zachem?
}

/*
printf
*/

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
			pars.flag = '!';
			pars.width = 0;
			pars.precision = 0;
			ft_parser((char *)&arr[i], &pars);
			i += pars.count;
			manage_fuction((char *)&arr[i], &argptr, &pars);
		}
		else
			ft_putchar(arr[i]);
	}
	return (0);
}
