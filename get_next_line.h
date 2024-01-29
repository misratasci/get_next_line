/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:31:10 by mitasci           #+#    #+#             */
/*   Updated: 2024/01/29 13:43:12 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 35
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //sil

char	*get_next_line(int fd);
int		get_nl_index(char *s);
char	*write_until_ind(char *b, int start, int ind);
char	*get_line(char *b, int new_buffer);
char	*get_next_buffer(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		count_nls(char *b);

#endif