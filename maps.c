/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/13 18:40:48 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_contents(char **map, int count);
char **errors(char **map, char *line, int type);

char	**get_map(void)
{
	int		fd;
	int		count;
	int		len_init;
	char	*line;
	char	**map;
	int		*components;
	
	fd = open("./maps/map5.ber", O_RDONLY);
	map = malloc(sizeof(char));
	line = get_next_line(fd);
	len_init = ft_strlen(line) - 1;
	while (len_init > 0)
	{
		if (line[len_init - 1] != '1')
			return (errors(map, line, 1));
		len_init--;
	}
	len_init = ft_strlen(line) - 1;
	count = 0;
	while (line != NULL)
	{
		if (line[0] != '1' || line[len_init - 1] != '1')
			return (errors(map, line, 1));
		map[count] = ft_strdup(line);
		line = get_next_line(fd);
		count++;
	}
	while (len_init > 0)
	{
		if (map[count - 1][len_init - 1] != '1')
			return (errors(map, line, 1));
		len_init--;
	}
	components = find_contents(map, count);
	if (components[0] == 0 || components[1] == 0 || components[2] == 0)
		return (errors(map, line, 2));
	free(line);
	return (map);
}

int	*find_contents(char **map, int count)
{
	int	*counter;
	int index;
	char *temp;

	index = 0;
	counter = malloc(sizeof(int) * 3);
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	while(count > 0)
	{
		temp = ft_strdup(map[count - 1]);
		while (temp[index] != '\0' && temp[index] != '\n')
		{
			if (temp[index] == 'P')
				counter[0]++;
			if (temp[index] == 'E')
				counter[1]++;
			if (temp[index] == 'C')
				counter[2]++;
			index++;
		}
		index = 0;
		count--;
	}
	return (counter);
}

char **errors(char **map, char *line, int type)
{
	free(map);
	free(line);
	perror("Error\n");
	if (type == 1)
		printf("O mapa não está fechado\n");
	if (type == 2)
		printf("O mapa não contem todos os elementos\n");
	return (NULL);
}