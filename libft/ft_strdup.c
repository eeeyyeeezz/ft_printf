/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:17:36 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 12:56:55 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char *dup_str;
	char *p;

	dup_str = malloc(ft_strlen(str) + 1);
	p = dup_str;
	if (dup_str == NULL)
		return (NULL);
	while (*str)
		*(p++) = *(str++);
	*p = '\0';
	return (dup_str);
}
