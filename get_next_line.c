/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/30 17:15:20 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;
	static int		continue_buffer;
	static int		buffer_line_count;

	if (!continue_buffer++)
		buffer = get_next_buffer(fd);
	if (!buffer)
		return (NULL);
	next_line = get_line(buffer, 0);
	if (buffer_line_count++ < count_nls(buffer) && buffer[0] != '\n')
		return (next_line);
	else
	{
		while (count_nls(next_line) == 0)
		{
			buffer_line_count = 0;
			free(buffer);
			buffer = get_next_buffer(fd);
			if (!buffer)
				break ;
			next_line = ft_strjoin(next_line, get_line(buffer, 1));
		}
		return (next_line);
	}
	return (NULL);
}

int main()
{
	//int fd = open("a.txt", O_RDONLY);
	int i = 0;
	while (i++ < 5)
		printf("%s", get_next_line(0));
}
