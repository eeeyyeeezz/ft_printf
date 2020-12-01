/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:56:32 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/11 12:29:28 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		memory_len(char const *s, char c)
{
	int j;
	int n;
	int i;

	j = 0;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (j == 1 && s[i] == c)
			j = 0;
		if (j == 0 && s[i] != c)
		{
			j = 1;
			n++;
		}
		i++;
	}
	return (n);
}

char			**ft_split(char const *s, char c)
{
	int		arr[3];
	char	**temp;

	arr[0] = 0;
	arr[2] = -1;
	if (!s)
		return (NULL);
	if (!(temp = malloc(sizeof(char *) * (memory_len(s, c) + 1))))
		return (NULL);
	while (++arr[2] < memory_len(s, c))
	{
		while (s[arr[0]] == c && s[arr[0]])
			arr[0]++;
		arr[1] = arr[0];
		while (s[arr[0]] != c && s[arr[0]])
			arr[0]++;
		temp[arr[2]] = ft_substr(s, arr[1], arr[0] - arr[1]);
		arr[0]++;
	}
	temp[arr[2]] = NULL;
	return (temp);
}
