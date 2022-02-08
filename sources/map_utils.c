/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:30:31 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/08 18:04:45 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matriz(t_data *data)
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

int	validations(char **map, int count, int len_init)
{
	int		*components;

	components = find_contents(map, count, len_init);
	if (components[1] != 1 || components[2] != 1)
	{
		free(components);
		return (2);
	}
	if (components[0] != 1)
	{
		free(components);
		return (6);
	}
	if (components[3] == -1)
	{
		free(components);
		return (3);
	}
	free(components);
	return (0);
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
				counter[0]++;
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

int	walls(char **map, int lines)
{
	int	index;
	int	line;

	index = ft_strlen(map[0]) - 1;
	line = 0;
	while (line != lines)
	{
		if (map[line][0] != '1')
			return (1);
		if (map[line][index] != '1')
			return (1);
		line++;
	}
	return (0);
}

void	empty_file(t_data *data, char *temp, char *line)
{
	if (data->lines == 0)
	{
		free(temp);
		free(line);
		printf("Error\n");
		printf("The map does not contain all the elements\n");
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		exit(3);
	}
}
