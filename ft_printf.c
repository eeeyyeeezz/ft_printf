/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 16:15:37 by gmorra           ###   ########.fr       */
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
	int		zero_flag;
	char	flag;
	char	type;
}					t_arg;

#pragma region libft
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

void		ft_putstr(const char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

void		ft_putnbr(int nb, t_arg *s_struct)
{
	int *ptr;

	ptr = 0;
	if (nb == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		return ;
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10, s_struct);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

int			ft_strlen(const char *s)
{
	int a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a] != 0)
		a++;
	return (a);
}

int			ft_atoi(const char *str)
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
static	void		ft_parser_procent(const char *arr, t_arg *s_struct)
{
	if (arr[1] == '%')
		s_struct->type = '%';
}

static	void		ft_parser_is_zero_zero(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (arr[i] && !(ft_istype(arr[i])))
	{
		if (arr[i] == '.')
			s_struct->zero_flag = 1;
		i++;
	}
}

static	void		ft_parser_width(const char *arr, t_arg *s_struct, va_list *argptr)
{
	int jump;

	jump = 1;
	while (arr[jump] == '0' || arr[jump] == '-')
		jump++;
	s_struct->width = ft_atoi((char *)&arr[jump]);
	if (s_struct->width == 0 && arr[jump] == '*')
		s_struct->width = va_arg(*argptr, int);
}

static	void		ft_parser_flags(const char *arr, t_arg *s_struct)
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

static	void		ft_parser_count(const char *arr, t_arg *s_struct)
{
	while (!(ft_istype(arr[s_struct->count])))
		s_struct->count++;
}

static	void		ft_parser_type(const char *arr, t_arg *s_struct)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i])))
		i++;
	s_struct->type = arr[i];
}

static	void		ft_parser_precision(const char *arr, t_arg *s_struct, va_list *argptr)
{
	int i;

	i = 0;
	while (!(ft_istype(arr[i])))
		i++;
	while (ft_isdigit(arr[i - 1]))
		i--;
	if (arr[i - 1] == '.')
		s_struct->precision = ft_atoi((char *)&arr[i]);
	if (s_struct->precision == 0 && arr[i - 1] == '*')
		s_struct->precision = va_arg(*argptr, int);
}

void		ft_parser(const char *arr, t_arg *s_struct, va_list *argptr)
{
	s_struct->precision = 0;
	s_struct->count = 0;
	s_struct->width = 0;
	s_struct->flag = '!';

	ft_parser_procent(arr, s_struct);
	if (s_struct->type != '%')
	{
		ft_parser_flags(arr, s_struct);
		ft_parser_width(arr, s_struct, argptr);
		ft_parser_precision(arr, s_struct, argptr);
		ft_parser_type(arr, s_struct);
		ft_parser_count(arr, s_struct);
		ft_parser_is_zero_zero(arr, s_struct);
	}
}
#pragma endregion PARSER

#pragma region INT_MANAGE
static	void			manage_int_zero_flag_width_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > ft_strlen_atoi(num) && num < 0 && s_struct->flag == '0')
		width -= 1;
	if (precision > ft_strlen_atoi(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ');
		s_struct->flag = 'A';
	}
	while (width-- > ft_strlen_atoi(num) && s_struct->flag == '0')
		ft_putchar(' ');
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0');
	ft_putnbr(num, s_struct);
	s_struct->flag = 'Z';
}

static	void			manage_int_min_flag_width_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0');
	ft_putnbr(num, s_struct);
	if (true_precision > ft_strlen_atoi(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ');
	while (width-- - ft_strlen_atoi(num) > 0 && true_precision < ft_strlen_atoi(num))
		ft_putchar(' ');
	s_struct->flag = 'Z';
}

static	void			manage_int_width_plus_precision_flags(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		manage_int_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		manage_int_min_flag_width_precision(num, width, precision, s_struct);
}

static	void			manage_int_width_plus_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > precision && precision > 0 && s_struct->flag == '!')
	{
		if (precision > ft_strlen_atoi(num) && num < 0)
			width -= 1;
		if (precision > ft_strlen_atoi(num))
		{
			while (width-- > precision)
				ft_putchar(' ');
			s_struct->flag = 'A';
		}
		while (width-- > ft_strlen_atoi(num) && s_struct->flag != 'A')
			ft_putchar(' ');
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-');
		}
		while (true_precision-- > ft_strlen_atoi(num))
			ft_putchar('0');
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

static	void			manage_int_width_minus(int num, int width, int precision, t_arg *s_struct)
{
	if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag == '-')
	{
		ft_putnbr(num, s_struct);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_int_zero(int num, int width, t_arg *s_struct)
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
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

static	void			manage_int_width(int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag != 'Z')
	{
		if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
		while (width - ft_strlen_atoi(num) && s_struct->flag != '0')
		{
			ft_putchar(' ');
			width--;
		}
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen_atoi(num) && width < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

static	void		manage_int_precesion(int num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > ft_strlen_atoi(num) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
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
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((precision == ft_strlen_atoi(num) || precision < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void 				manage_int(va_list *argptr, t_arg *s_struct)
{
	int		num;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(*argptr, int);
	manage_int_width_plus_precision_flags(num, width, precision, s_struct);
	manage_int_width_plus_precision(num, width, precision, s_struct);
	manage_int_width_minus(num, width, precision, s_struct);
	manage_int_zero(num, width, s_struct);
	manage_int_width(num, width, s_struct);
	manage_int_precesion(num, precision, s_struct);
}
#pragma endregion INT_MANAGE

#pragma region STR_MANAGE
static	void			manage_str_zero_flag_width_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > ft_strlen(arr) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ');
		s_struct->flag = 'A';
	}
	while (width-- > ft_strlen(arr) && s_struct->flag == '0')
		ft_putchar(' ');
	while (precision-- > ft_strlen(arr))
		ft_putchar('0');
	ft_putstr(arr);
	s_struct->flag = 'Z';
}

static	void			manage_str_min_flag_width_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	while (precision-- > ft_strlen(arr))
		ft_putchar('0');
	ft_putstr(arr);
	if (true_precision > ft_strlen(arr))
		while (width-- - true_precision > 0)
			ft_putchar(' ');
	while (width-- - ft_strlen(arr) > 0 && true_precision < ft_strlen(arr))
		ft_putchar(' ');
	s_struct->flag = 'Z';
}

static	void			manage_str_width_plus_precision_flags(const char *arr, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		manage_str_zero_flag_width_precision(arr, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		manage_str_min_flag_width_precision(arr, width, precision, s_struct);
}


static	void			manage_str_width_minus(char *str, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen(str) && width > precision && s_struct->flag == '-')
	{
		ft_putstr(str);
		while (width - ft_strlen(str))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void				manage_str_width(char *str, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen(str) && width > precision && s_struct->flag != 'Z')
	{
		while (width - ft_strlen(str))
		{
			ft_putchar(' ');
			width--;
		}
		ft_putstr(str);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen(str) || width < ft_strlen(str)) && s_struct->flag != 'Z')
	{
		ft_putstr(str);
		s_struct->flag = 'Z';
	}
}

static	void		manage_str_precesion(char *str, int precision, t_arg *s_struct)
{
	int i;
	int width;

	i = 0;
	width = s_struct->width;
	if ((precision < ft_strlen(str) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		while (precision > 0)
		{
			ft_putchar(str[i]);
			i++;
			precision--;
		}
		s_struct->flag = 'Z';
	}
	else if ((precision == ft_strlen(str) || precision < ft_strlen(str)) && s_struct->flag != 'Z')
	{
		ft_putstr(str);
		s_struct->flag = 'Z';
	}
}

void 				manage_string(va_list *argptr, t_arg *s_struct)
{
	char	*str;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	str = va_arg(*argptr, char*);
	manage_str_width_plus_precision_flags(str, width, precision, s_struct);
	manage_str_width_minus(str, width, precision, s_struct);
	manage_str_width(str, width, s_struct);
	manage_str_precesion(str, precision, s_struct);
}

#pragma endregion STR_MANAGE

#pragma region HEX_MANAGE
static	char		hex_word(long num)
{
	if (num >= 0 && num <= 9)
		return (num + 48);
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	return (num);
}

static	int			malloc_count(long num)
{
	int count;

	count = 1;
	while(num >= 16)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static	void		ft_puthex(long num)
{
	int i;
	int a;
	char tmp;
	char *str;

	i = 0;
	a = 0;
	tmp = 0;
	str = malloc(malloc_count(num));
	while (num > 0)
	{
		str[i] = hex_word((num % 16));
		num = num / 16;
		i++;
	}
	i -= 1;
	while (i >= 0)
		write(1, &str[i--], 1);
	free(str);
	str = NULL;
}

static	void			manage_hex_width_plus_precision_flags(long num, int width, int precision, int o_precesion, t_arg *s_struct)
{
	if (num < 0)
		width -= 1;
	if (width > 0 && precision > 0 && s_struct->flag != '!')
	{
		while (width > precision && s_struct->flag != '-')
		{
			ft_putchar(' ');
			width--;
		}
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision > malloc_count(num))
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		while (width - o_precesion > 0 && s_struct->flag == '-')
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width_plus_precision(long num, int width, int precision, t_arg *s_struct)
{
	if (num < 0)
		width -= 1;
	if (width > 0 && precision > 0 && s_struct->flag == '!')
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
		while (precision > malloc_count(num))
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width_minus(long num, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag == '-')
	{
		ft_puthex(num);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_zero(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (precision > ft_strlen_atoi(num) && width != precision && precision > width && s_struct->flag == '0')
	{
		if (num < 0 && s_struct->flag == '0')
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision - malloc_count(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width(long num, int width, t_arg *s_struct)
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
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen_atoi(num) || width < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void		manage_hex_precesion(long num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > ft_strlen_atoi(num) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision - malloc_count(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
	else if ((precision == ft_strlen_atoi(num) || precision < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}



void		manage_hex(va_list *argptr, t_arg *s_struct)
{
	long	hex;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	hex = va_arg(*argptr, unsigned int);
	if (width > 0 && precision > 0 && s_struct->flag != '!')
		manage_hex_width_plus_precision_flags(hex, width, precision, precision, s_struct);
	manage_hex_width_plus_precision(hex, width, precision, s_struct);
	manage_hex_width_minus(hex, width, precision, s_struct);
	manage_hex_zero(hex, width, s_struct);
	manage_hex_width(hex, width, s_struct);
	manage_hex_precesion(hex, precision, s_struct);
}

#pragma endregion HEX_MANAGE

#pragma region PTR_MANAGE
void 				manage_pointers(va_list *argptr, t_arg *s_struct)
{
	unsigned long	ptr;
	int				width;
	int				precision;

	precision = s_struct->precision;
	width = s_struct->width;
	ptr = (unsigned long)va_arg(*argptr, void*);
}

#pragma endregion PTR_MANAGE

void			manage_fuction(const char *procent, va_list *argptr, t_arg *s_struct)
{
	int i;

	i = -1;
	(void)procent;
	if (s_struct->type == 'd' || s_struct->type == 'i')
		manage_int(argptr, s_struct);
	if (s_struct->type == 's')
		manage_string(argptr, s_struct);
	if (s_struct->type == 'x')
		manage_hex(argptr, s_struct);
	if (s_struct->type == 'p')
		manage_pointers(argptr, s_struct);
}

int				ft_printf(const char *arr, ...)
{
	int		i;
	va_list	argptr;
	t_arg 	s_struct;

	i = -1;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			ft_parser((char *)&arr[i], &s_struct, &argptr);
			i += s_struct.count;
			manage_fuction((char *)&arr[i], &argptr, &s_struct);
		}
		else
		{
			s_struct.len++;
			ft_putchar(arr[i]);
		}
	}
	va_end(argptr);
	return (s_struct.len);
}
