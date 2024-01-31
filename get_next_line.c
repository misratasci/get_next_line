/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:30:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/31 20:01:09 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> //sil bunları

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	while (count_nls(saved) == 0)
	{	
		saved = ft_strjoin(saved, get_next_buffer(fd));
		if (!saved)
			return (NULL);
	}
	next_line = get_line(saved);
	//printf("önceki %s\n", saved);
	saved = get_after_line(saved);
	//printf("sonraki %s\n", saved);
	return (next_line);
}

// int main()
// {
// 	int fd = open("get_next_line.c", O_RDONLY);
// 	int i = 0;

// 	while (i++ < 40)
// 	{

// 		printf("%s", get_next_line(fd));
// 	}
// }
