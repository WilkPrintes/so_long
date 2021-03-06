/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/11 02:22:11 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		errors(int type, t_data *data);
int		full_line(char *line);
int		len_lines(t_data *data);
int		validation(t_data *data);

int	get_map(char *path, t_data *data)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		errors(4, data);
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
	empty_file(data, temp, line);
	data->map = ft_split(temp, '\n');
	data->columns = ft_strlen(data->map[0]);
	free(temp);
	free(line);
	validation(data);
}

int	validation(t_data *data)
{
	int	i;

	i = 0;
	if (walls(data->map, data->lines) == 5)
		errors(5, data);
	if (walls(data->map, data->lines) == 1)
		errors(1, data);
	if (full_line(data->map[0]) == 1)
		errors(1, data);
	if (full_line(data->map[data->lines - 1]) == 1)
		errors(1, data);
	if (len_lines(data) == 1)
		errors(5, data);
	i = validations(data->map, data->lines, data->columns);
	if (i != 0)
		errors(i, data);
	return (0);
}

int	len_lines(t_data *data)
{
	int	line;
	int	len;

	line = 1;
	len = ft_strlen(data->map[0]);
	while (line < data->lines)
	{
		if (len != ft_strlen(data->map[line]))
			return (1);
		line++;
	}
	return (0);
}

int	full_line(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	while (len >= 0)
	{
		if (line[len] != '1')
			return (1);
		len--;
	}
	return (0);
}

int	errors(int type, t_data *data)
{
	ft_printf("Error\n");
	if (type == 1)
		ft_printf("The map is not closed\n");
	if (type == 2)
		ft_printf("The map does not contain all the elements\n");
	if (type == 3)
		ft_printf("The map contains invalid elements\n");
	if (type == 4)
	{
		ft_printf("Invalid map path\n");
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		exit(3);
	}
	if (type == 5)
		ft_printf("Difference in line size\n");
	if (type == 6)
		ft_printf("More than one player found\n");
	free_matrix(data);
	return (0);
}
