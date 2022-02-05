/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:08:25 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 02:56:42 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_data *data, int count, int line);

void	render_map(t_data *data)
{
	int	line;
	int	count;

	line = 0;
	count = 0;
	data->p_collection = 0;
	data->collection = 0;
	while (line <= data->lines - 1)
	{
		count = 0;
		while (count <= data->columns - 1)
		{
			put_image_to_window(data, count, line);
			count++;
		}
		line++;
	}
}

void	put_image_to_window(t_data *data, int count, int line)
{
	int	x;
	int	y;

	x = 32 * count;
	y = 32 * line;
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
}
