/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/29 13:44:56 by mitasci          ###   ########.fr       */
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
	
	if (!continue_buffer)
	{
		buffer = get_next_buffer(fd);
		continue_buffer = 1;
	}
	next_line = get_line(buffer, 0);
	if (buffer_line_count++ < count_nls(buffer))
		return (next_line);
	else
	{
		buffer_line_count = 0;
		buffer = get_next_buffer(fd);
		return (ft_strjoin(next_line, get_line(buffer, 1)));
	}
	return NULL;
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
