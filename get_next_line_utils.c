/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:58 by mitasci           #+#    #+#             */
/*   Updated: 2024/02/06 16:15:27 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_buffer(int fd)
{
	char	*buffer;
	int		l;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	l = read(fd, buffer, BUFFER_SIZE);
	if (l == 0 || l == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[l] = '\0';
	return (buffer);
}

int	get_line_length(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

int	count_nls(char *b)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (b[i] && b)
	{
		if (b[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*write_until_ind(char *b, int start, int ind)
{
	char	*s;
	int		i;

	if (start >= ind)
		return (NULL);
	s = (char *)malloc((ind + 2 - start) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (start < ind)
	{
		s[i] = b[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_until_nl(char *b)
{
	int			nl_ind;
	char		*s;

	nl_ind = get_line_length(b);
	s = write_until_ind(b, 0, nl_ind);
	return (s);
}

static int	strlength(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

char	*get_after_line(char *b)
{
	int			nl_ind;
	char		*s;

	nl_ind = get_line_length(b);
	s = write_until_ind(b, nl_ind, strlength(b));
	free(b);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	str = (char *)malloc(strlength(s1) + strlength(s2) + 1);
	if (!str)
		return (NULL);
	if (!s1 && !s2)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (++i < strlength(s1))
		str[i] = s1[i];
	i = -1;
	while (++i < strlength(s2))
		str[strlength(s1) + i] = s2[i];
	str[strlength(s1) + i] = 0;
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
