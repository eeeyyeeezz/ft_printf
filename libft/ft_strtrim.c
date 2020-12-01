/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:26:41 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/05 16:46:42 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_char(char const *str, char const c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	i_end;

	i = 0;
	if (str == NULL)
		return (NULL);
	i_end = ft_strlen(str) - 1;
	while (check_char(set, str[i]))
		i++;
	while (check_char(set, str[i_end]))
		if (i_end > 0)
			i_end--;
		else
			break ;
	if (i == ft_strlen(str))
		return (ft_substr("", 0, 1));
	return (ft_substr(str, i, i_end - i + 1));
}
