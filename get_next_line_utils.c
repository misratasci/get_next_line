/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:58 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/24 13:11:55 by mitasci          ###   ########.fr       */
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
	l = l + 1;
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

char	*get_line(char *b)
{
	static int	prev_ind;
	int			nl_ind;
	char		*s;
	
	nl_ind = get_nl_index(b);
	if (nl_ind == -1)
		nl_ind = BUFFER_SIZE;
	s = write_until_ind(b, prev_ind, nl_ind);
	prev_ind = nl_ind;
	return (s);
}