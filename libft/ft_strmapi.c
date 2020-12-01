/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:56:56 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/05 17:52:36 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;

	i = -1;
	if (s == NULL)
		return (NULL);
	temp = malloc(ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	while (s[++i])
		temp[i] = f(i, s[i]);
	temp[i] = '\0';
	return (temp);
}
