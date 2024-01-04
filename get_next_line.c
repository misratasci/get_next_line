/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/04 13:54:18 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"


char	*get_next_line(int fd)
{
	void			*buffer;
	static size_t	l;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	l = read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("a.txt", O_RDONLY);
	printf("1. %s\n", get_next_line(fd));
	printf("2. %s\n", get_next_line(fd));
	printf("3. %s\n", get_next_line(fd));
}
