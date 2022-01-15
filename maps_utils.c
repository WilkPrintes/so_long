/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:29:33 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/14 23:24:56 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	full_line(int len_init, char *line)
{
	while (len_init > 0)
	{
		if (line[len_init - 1] != '1')
			return (-1);
		len_init--;
	}
}

int	validations(char **map, int count, int len_init)
{
	int		*components;
	char	*line;
	char	*temp;

	line = ft_strdup(map[count - 1]);
	if (full_line(len_init, line) == -1)
		return (1);
	components = find_contents(map, count);
	if (components == NULL)
		return (5);
	if (components[0] != 1 || components[1] != 1 || components[2] != 1)
		return (2);
	if (components[3] == -1)
		return (3);
	if (find_wall(map, count) != 1)
		return (1);
	return (0);
}

int	*find_contents(char **map, int count)
{
	int		*counter;
	int		index;
	char	*temp;

	while (count > 0)
	{
		temp = ft_strdup(map[count - 1]);
		while (temp[index] != '\0' && temp[index] != '\n')
		{
			if (temp[index] == 'P')
				counter[0] = 1;
			else if (temp[index] == 'E')
				counter[1] = 1;
			else if (temp[index] == 'C')
				counter[2] = 1;
			else if (temp[index] != '1' && temp[index] != '0')
				counter[3] = -1;
			index++;
		}
		index = 0;
		count--;
	}
	return (counter);
}

int	find_wall(char **map, int count)
{
	int		*counter;
	int		index;
	char	*temp;
	int		i_temp;

	index = 0;
	i_temp = 0;
	while (count > 0)
	{
		temp = ft_strdup(map[count - 1]);
		while (temp[index] != '\0' && temp[index] != '\n')
			index++;
		if (i_temp == 0)
			i_temp = index;
		if (i_temp != index)
			return (0);
		i_temp = index;
		index = 0;
		count--;
	}
	return (1);
}

char	**errors(char **map, char *line, int type)
{
	free(map);
	free(line);
	printf("Error\n");
	if (type == 1)
		printf("O mapa não está fechado\n");
	if (type == 2)
		printf("O mapa não contem todos os elementos\n");
	if (type == 3)
		printf("O mapa contem elementos inválidos\n");
	if (type == 4)
		printf("Caminho de mapa inválido\n");
	if (type == 5)
		printf("Linha maior/menor encontrada\n");
	return (NULL);
}
