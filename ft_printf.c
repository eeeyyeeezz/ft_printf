/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/04 18:38:18 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/libft.h"
// #include "includes/libft_printf.h"
#include <printf.h>
#include <unistd.h>

typedef		struct s_arg
{
	int		count;
	int		width;
	int		accuracy;
	char	dot;
	char	flag;

}					t_arg;

/*
libft on
*/

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	while (*s)
		write(fd, &*s++, 1);
}

void		ft_putnbr_fd(int nb, int fd)
{
	int *ptr;

	ptr = 0;
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb / 10 > 0)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

size_t		ft_strlen(const char *s)
{
	int a;

	a = 0;
	while (s[a] != 0)
		a++;
	return (a);
}

/*
Parsers
*/

void		ft_parser(const char *arr, t_arg *j)  // делай функции на обработку всех флагов записывать в стракт результаты
{
	j->count = 0;

	if (*arr + 1 == '%')
	{
		ft_putchar('%');
		j->count++;
		// break ;
	}
	else if (*arr + 1 == '-')
	{
		j->flag = '-';
		j->count++;
		// break ;
	}
	else if (*arr + 1 == '.')
	{
		j->flag = '.';
		j->count++;
		// break ;
	}
}

/*
Obrabotka
*/

int				manage_int(const char *arr, va_list *argptr)
{
	int		i;
	int		num;

	(void)arr;
	i = 0;
	num = va_arg(*argptr, int);
	ft_putnbr_fd(num, 1);
	return (num);
}


void			manage_fuction(const char *procent, va_list *argptr, t_arg *j)				// Функция обработки %d (int)
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
			ft_parser(arr, &pars);
			i += pars.count;
			manage_fuction((char *)&arr[i], &argptr, &pars);
			i += pars.count;
		}
		else
			ft_putchar(arr[i]);
	}
	return (0);
}
