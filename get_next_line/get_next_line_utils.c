/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:04:17 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 01:43:05 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gft_strjoin(const char *str1, const char *str2)
{
	size_t	len;
	size_t	index;
	char	*result;

	len = gft_strlen(str1) + gft_strlen(str2);
	if (len == 0)
		return (NULL);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str1 && *str1)
	{
		result[index] = *str1;
		index += 1;
		str1++;
	}
	while (str2 && *str2)
	{
		result[index] = *str2;
		index += 1;
		str2++;
	}
	result[index] = '\0';
	return (result);
}

ssize_t	gft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*gft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	len = gft_strlen(str) + 1;
	s = malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

char	*gft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = gft_strlen(s);
	if (start > srclen)
		return (gft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	find_n(char *buffer)
{
	size_t	counter;

	counter = 0;
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	return (counter);
}
