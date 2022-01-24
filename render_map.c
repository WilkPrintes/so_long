/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:08:25 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/22 00:36:23 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_data *data, int count, int line);

void	render_map(t_data *data)
{
	int	line;
	int	count;

	printf("=====render_map=====\n");
	line = 0;
	count = 0;
	while (line <= data->lines)
	{
		printf("linha: %d\n", line);
		count = 0;
		while (count <= data->columns)
		{
			printf("colunas %d\n", count);
			put_image_to_window(data, count, line);
			count++;
		}
		line++;
	}
	printf("=====render_map ok=====\n");
}

void	put_image_to_window(t_data *data, int count, int line)
{
	int	x;
	int	y;

	x = 32 * count;
	y = 32 * line;
	data->p_collection = 0;
	printf("=====put_image_to_window=====\n");
	if (data->map[line][count] == '1')
		mlx_put_image_to_window(data->ptr, data->win, data->img1, x, y);
	else if (data->map[line][count] == '0')
		mlx_put_image_to_window(data->ptr, data->win, data->img0, x, y);
	else if (data->map[line][count] == 'C')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->imgc, x, y);
		data->collection++;
	}
	else if (data->map[line][count] == 'E')
		mlx_put_image_to_window(data->ptr, data->win, data->imge, x, y);
	else if (data->map[line][count] == 'P')
	{
		data->p_line = line;
		data->p_column = count;
		mlx_put_image_to_window(data->ptr, data->win, data->imgp, x, y);
	}
	printf("=====put_image_to_window ok=====\n");
}
