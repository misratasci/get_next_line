/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/02/06 15:59:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*next_line;
	char		*next_buffer;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
	
	while (1)
	{	
		next_buffer = get_next_buffer(fd);
		saved = ft_strjoin(saved, next_buffer);
		if (!saved)
		{
			free(next_buffer);
			return (NULL);
		}
		if (!next_buffer || count_nls(next_buffer) != 0)
			break ;
	}
	next_line = get_until_nl(saved);
	//printf("önceki %s\n", saved);
	saved = get_after_line(saved);
	//printf("sonraki %s\n", saved);
	return (next_line);
}
/*
int main()
{
	int fd = open("a.txt", O_RDONLY);
	int i = 0;

	while (i++ < 1)
	{
		printf("%s", get_next_line(fd));
	}
}
*/