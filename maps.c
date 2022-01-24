/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 00:27:22 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		*find_contents(char **map, int count);
char	**errors(char **map, char *line, int type);
int		full_line(int len_init, char *line);
int		validations(char **map, int count, int len_init);

char	**get_map(char *path)
{
	int		fd;
	int		count;
	int		len_init;
	char	*line;
	char	**map;

	map = malloc(sizeof(char));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errors(map, ft_strdup(""), 4));
	printf("Open ok\n");
	line = get_next_line(fd);
	printf("primeira linha\n");
	len_init = ft_strlen(line) - 1;
	if (full_line(len_init, line) == -1)
		return (errors(map, line, 1));
	printf("Full line ok\n");
	count = 0;
	while (line != NULL)
	{
		printf("Linha: %d\n", count);
		if (line[0] != '1' || line[len_init - 1] != '1')
			return (errors(map, line, 1));
		printf("Verificação de paredes ok\n");
		map[count] = ft_strdup(line);
		printf("Dup finalizado\n");
		line = get_next_line(fd);
		count++;
	}
	printf("Tudo no map\n");
	if (validations(map, count, len_init) != 0)
		return (errors(map, line, validations(map, count, len_init)));
	free(line);
	printf("Free line\n");
	printf("=====get_map ok=====\n");
	return (map);
}

int full_line(int len_init, char *line)
{
	printf("=====full_line=====\n");
	while (len_init > 0)
	{
		if (line[len_init - 1] != '1')
			return (-1);
		len_init--;
	}
	printf("=====full_line ok=====\n");
}

int validations(char **map, int count, int len_init)
{
	int		*components;
	char	*line;
	char	*temp;

	printf("=====validations=====\n");
	line = ft_strdup(map[count - 1]);
	printf("Var line Iniciada\n");
	if (full_line(len_init, line) == -1)
		return (1);
	printf("Full line ok, iniciando find_contents");
	components = find_contents(map, count);
	if (components == NULL)
		return(5);
	if (components[0] != 1 || components[1] != 1 || components[2] != 1)
		return (2);
	if (components[3] == -1)
		return (3);
	printf("=====validations ok=====\n");
	return (0);
}
int	*find_contents(char **map, int count)
{
	int		*counter;
	int		index;
	char	*temp;
	int		i_temp;

	printf("=====find_contends=====\n");
	index = 0;
	i_temp = 0;
	counter = malloc (sizeof (int ) * 4);
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;	
	while (count > 0)
	{
		printf("linha: %d\n", count);
		temp = ft_strdup(map[count - 1]);
		while (temp[index] != '\0' && temp[index] != '\n')
		{
			printf("Coluna %d\n", index);
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
		printf("validação de linha maior\n");
		if (i_temp == 0)
			i_temp = index;
		if (i_temp != index)
			return(NULL);
		printf("validação ok");
		i_temp = index;
		index = 0;
		count--;
	}
	printf("=====find_contends ok=====\n");
	return (counter);
}

char	**errors(char **map, char *line, int type)
{
	printf("=====errors=====\n");
	free(map);
	free(line);
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
	return (NULL);
}
