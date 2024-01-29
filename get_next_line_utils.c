/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:58 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/29 13:43:01 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_buffer(int fd)
{
	void			*buffer;
	static size_t	l;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	l += read(fd, buffer, BUFFER_SIZE);
	l = l + 1; //bu l yi sonradan kullanırsın diye koydun kullanmazsan sil l'siz yaz
	return (buffer);
}

int	get_nl_index(char *s)
{
	static int	i;

	while (s[i])
	{
		if (s[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

int	count_nls(char *b)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (b[i])
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

	s = (char *)malloc((ind + 1 - start) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (start < ind)
	{
		s[i] = b[start];
		start++;
		i++;
	}
	return (s);
}

char	*get_line(char *b, int new_buffer)
{
	static int	prev_ind;
	int			nl_ind;
	char		*s;
	
	if (new_buffer)
		prev_ind = 0;
	nl_ind = get_nl_index(b);
	if (nl_ind == -1)
		nl_ind = BUFFER_SIZE;
	s = write_until_ind(b, prev_ind, nl_ind);
	prev_ind = nl_ind;
	return (s);
}

static size_t	strlength(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(strlength(s1) + strlength(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < strlength(s1))
	{
		str[i] = s1[i];
		i += 1;
	}
	i = 0;
	while (i < strlength(s2))
	{
		str[strlength(s1) + i] = s2[i];
		i += 1;
	}
	str[strlength(s1) + i] = 0;
	return (str);
}