/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/07 17:46:38 by gmorra           ###   ########.fr       */
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
#pragma endregion libf

/*
Parsers
*/

void		ft_parser(const char *arr, t_arg *j)  // делай функции на обработку всех флагов записывать в стракт результаты
{
	int	precision_place;
	int	if_precision;
	int jump;
	int i;

	j->count = 0;
	if_precision = 0;
	precision_place = 0;				// начальное значение где аргумент
	i = 0;
	jump = 0;
	// if (arr[i + 1] == '%')			// печать процента
	// {
	// 	while (arr[i++] == '%')
	// 		ft_putchar('%');
	// 	return ;
	// }
	while (arr[i + 1] == '0' && j->flag != '-')
	{
		j->flag = '0';
		jump++;
		i++;
		// write(1, " !it! ", 20);
	}
	while (arr[i + 1] == '-' || arr[i] == '-')
	{
		j->flag = '-';
		jump++;
		i++;
	}
	// while (arr[precision_place] != '.')			// поиск точности
	// {
	// 	if (arr[precision_place] == '.')
	// 	{
	// 		j->precision = ft_atoi((char *)&arr[precision_place]);
	// 		break ;
	// 	}
	// 	if_precision++;
	// 	precision_place++;			// или --
	// }
	if (arr[1] != '0' && arr[1] != '-')
		j->width = ft_atoi((char *)&arr[jump + 1]);
	else
		j->width = ft_atoi((char *)&arr[jump]);
	j->count += i + if_precision + ft_strlen_atoi(j->width);		// обрботать если есть точность прыжок правильно с учетом
	printf("flag [%c] width (%d) precision [%d] ", j->flag, j->width, j->precision);
}

/*
Obrabotka
*/

int				manage_int(const char *arr, va_list *argptr)			// Функция обработки %d (int)
{
	int		i;
	int		num;

	(void)arr;
	i = 0;
	num = va_arg(*argptr, int);
	ft_putnbr(num);
	return (num);
}


void			manage_fuction(const char *procent, va_list *argptr, t_arg *j)				// функция обработки типа аргумента
{
	int i;

	i = -1;
	while (procent[++i])
	{
		if (procent[i] == 'd' || procent[i] == 'i')
		{
			manage_int((char *)&procent[i], &*argptr);
			break ;
		}
	}
	j->count = j->count + i;
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
			ft_parser((char *)&arr[i], &pars);
			i += pars.count;
			manage_fuction((char *)&arr[i], &argptr, &pars);
			pars.flag = '!'; // обнуление флага
			// i += pars.count;
		}
		else
			ft_putchar(arr[i]);
	}
	return (0);
}
