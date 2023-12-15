/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:14:07 by cesar             #+#    #+#             */
/*   Updated: 2023/12/15 17:51:58 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strndup(char const *src, size_t n)
{
	size_t		i;
	char		*dest;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	char			*out;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = 0;
	return (out);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		out_len;
	char		*out;

	i = 0;
	out_len = ft_strlen(s);
	out = malloc(sizeof(char) * out_len + 1);
	if (!out || !s)
		return (NULL);
	while (i < out_len && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
