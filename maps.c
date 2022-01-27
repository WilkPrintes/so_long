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
int		full_line(char *line);
void	free_matriz(t_data *data);
int		walls(char **map, int lines);
int	*find_contents(char **map, int lines, int columns);
int	validations(char **map, int count, int len_init);

int	get_map(char *path, t_data *data)
{
	int		fd;
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		errors(4);
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		exit(3);
	}
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
	if (full_line(data->map[0]) == 1)
	{
		errors(1);
		free_matriz(data);
	}
	if (full_line(data->map[data->lines - 1]) == 1)
	{
		errors(1);
		free_matriz(data);
	}
	if (walls(data->map, data->lines) == 1)
	{
		errors(1);
		free_matriz(data);
	}
	i = validations(data->map, data->lines, data->columns);
	if (i != 0)
	{
		errors(i);
		free_matriz(data);
	}
		
}

int	full_line(char *line)
{
	int len;

	len = ft_strlen(line) - 1;
	while (len >= 0)
	{
		if (line[len] != '1')
			return (1);
		len--;
	}
}

int walls(char **map, int lines)
{
	int index;
	int line;

	index = ft_strlen(map[0]) - 1;
	line = 0;
	while(line != lines)
	{
		if (map[line][0] != '1')
			return (1);
		if (map[line][index] != '1')
			return (1);
		line++;
	}
}

int	*find_contents(char **map, int lines, int columns)
{
	int		*counter;
	int		line;
	int		column;
	char	*temp;

	line = 0;
	column = 0;
	counter = malloc(sizeof(int) * 4);
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	while (line != lines)
	{
		temp = ft_strdup(map[line]);
		while (column != columns)
		{
			if (temp[column] == 'P')
				counter[0] = 1;
			else if (temp[column] == 'E')
				counter[1] = 1;
			else if (temp[column] == 'C')
				counter[2] = 1;
			else if (temp[column] != '1' && temp[column] != '0')
				counter[3] = -1;
			column++;
		}
		free(temp);
		column = 0;
		line++;
	}
	return (counter);
}

int	validations(char **map, int count, int len_init)
{
	int		*components;

	components = find_contents(map, count, len_init);
	if (components == NULL)
	{
		free(components);
		return (5);
	}

	if (components[0] != 1 || components[1] != 1 || components[2] != 1)
	{
		free(components);
		return (2);
	}	
	if (components[3] == -1)
	{
		free(components);
		return (3);
	}
	free(components);
	return (0);
}

int	errors(int type)
{
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
	return (0);
}

void free_matriz(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	mlx_destroy_display(data->ptr);
	free(data->map);
	free(data->ptr);
	exit(3);
}