/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:30:31 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/09 16:42:10 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*init_var(int *line, int *column);

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

	counter = init_var(&line, &column);
	while (line != lines)
	{
		temp = ft_strdup(map[line++]);
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
	}
	return (counter);
}

int	*init_var(int *line, int *column)
{
	int	*result;

	*line = 0;
	*column = 0;
	result = malloc(sizeof(int) * 4);
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	return (result);
}

int	walls(char **map, int lines)
{
	int	index;
	int	line;

	index = ft_strlen(map[0]);
	line = 0;
	while (line < lines)
	{
		if (map[line] == NULL || ft_strlen(map[line]) != index)
			return (5);
		if (map[line][0] != '1')
			return (1);
		if (map[line][index - 1] != '1')
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
