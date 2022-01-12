/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/12 20:33:36 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char **get_map(void)
{
    int fd;
    int count;
    char *line;
    char **map;
    
    fd = open("./maps/map1.ber", O_RDONLY);
    map = malloc(sizeof(char));
    line = get_next_line(fd);
    count = 0;
    while(line != NULL) 
    {
        map[count] = ft_strdup(line);
        line = get_next_line(fd);
        count++;
    }
    free(line);
    return (map);
}