/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 18:08:34 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd)
{
	size_t			buff_size;
	void			*buffer;
	static size_t	l;

	buff_size = BUFFER_SIZE;
	buffer = (char *)malloc(buff_size * sizeof(char));
	l = read(fd, buffer, buff_size);
	return (buffer);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("a.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
