/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 12:25:48 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		errors(int type);

int	get_map(char *path, t_data *data)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errors(4));
	data->lines = 0;
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(temp, line);
		free(line);
		data->lines++;
	}
	data->map = ft_split(temp, '\n');
	data->columns = ft_strlen(data->map[0]);
	free(temp);
	free(line);
}

int	errors(int type)
{
	printf("=====errors=====\n");
	printf("Error\n");
	if (type == 1)
		printf("The map is not closed\n");
	if (type == 2)
		printf("The map does not contain all the elements\n");
	if (type == 3)
		printf("The map contains invalid elements\n");
	if (type == 4)
		printf("Invalid map path\n");
	if (type == 5)
		printf("Major/smallest line found\n");
	printf("=====errors ok=====\n");
	return (0);
}
