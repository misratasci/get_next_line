/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/31 18:48:29 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	//char		*next_line;

	//saved = ft_strjoin(saved, get_next_buffer(fd));
	return (saved);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	int i = 0;
	while (i++ < 5)
	{

		printf("%s", get_next_line(fd));
	}
}
