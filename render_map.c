/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:08:25 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/13 12:08:32 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_data *data)
{
	int	line;
	int	count;

	line = 0;
	count = 0;
	while (line <= data->lines)
	{
		count = 0;
		while (count <= data->columns)
		{
			if (data->map[line][count] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img1, 32 * count, 32 * line);
			else if (data->map[line][count] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img0, 32 * count, 32 * line);
			else if (data->map[line][count] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgc, 32 * count, 32 * line);
				data->collection++;
			}
			else if (data->map[line][count] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imge, 32 * count, 32 * line);
			else if (data->map[line][count] == 'P')
			{
				data->p_line = line;
				data->p_column = count;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgp, 32 * count, 32 * line);
			}
			count++;
		}
		line++;
	}
}
