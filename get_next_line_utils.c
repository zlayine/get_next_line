/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:20:41 by zlayine           #+#    #+#             */
/*   Updated: 2019/12/08 15:35:52 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	j;
	int		i;

	j = 0;
	if (!s || start > ft_strlen(s))
		return ("");
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	i = start;
	while (j < len)
	{
		r[j] = s[start];
		start++;
		j++;
	}
	r[j] = '\0';
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	char	r;
	int		i;

	r = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == r)
			return ((char *)(s + i));
		i++;
	}
	if (r == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	while (s1[i])
		r[j++] = s1[i++];
	i = 0;
	while (s2[i])
		r[j++] = s2[i++];
	r[j] = '\0';
	return (r);
}

char	*ft_strdup(const char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
