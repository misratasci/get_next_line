/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/24 13:47:58 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;
	static int		buffer_count;
	
	if (buffer_count == 0)
	{
		buffer = get_next_buffer(fd);
		buffer_count++;
	}
	next_line = get_line(buffer);
	if (next_line)
		return (next_line);
	else
	{
		buffer = get_next_buffer(fd);
		buffer_count++;
		return (ft_strjoin(next_line, get_line(buffer)));
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
}
