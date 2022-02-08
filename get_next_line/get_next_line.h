/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:27:05 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/08 22:22:41 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*n_strjoin(char const *s1, char const *s2);
ssize_t	n_strlen(const char *s);
char	*n_strdup(const char *src);
char	*n_substr(char const *s, unsigned int start, size_t len);
size_t	find_n(char *buffer);

#endif