/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/24 12:33:55 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	fd = fd + 1;
	return NULL;
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *buffer = get_buffer(fd);
	printf("%s", get_line(buffer));
	printf("%s", get_line(buffer));
	printf("%s", get_line(buffer));
}
