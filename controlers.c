/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:38:57 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/13 16:05:42 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_d(t_data *data)
{
	if (data->map[data->p_line][data->p_column + 1] != '1')
	{
		if (data->map[data->p_line][data->p_column + 1] == 'C')
		{
			data->p_collection++;
			data->map[data->p_line][data->p_column + 1] = '0';
		}
		if (data->map[data->p_line][data->p_column + 1] == 'E')
		{
			if (data->p_collection == data->collection)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img0, 32 * data->p_column, 32 * data->p_line);
				data->p_column++;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgp, 32 * data->p_column, 32 * data->p_line);
				close_window(data);
			}
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_column++;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->imgp, 32 * data->p_column, 32 * data->p_line);
		}
	}
}

void	key_a(t_data *data)
{
	if (data->map[data->p_line][data->p_column - 1] != '1')
	{
		if (data->map[data->p_line][data->p_column - 1] == 'C')
		{
			data->p_collection++;
			data->map[data->p_line][data->p_column - 1] = '0';
		}
		if (data->map[data->p_line][data->p_column - 1] == 'E')
		{
			if (data->p_collection == data->collection)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img0, 32 * data->p_column, 32 * data->p_line);
				data->p_column--;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgp_l, 32 * data->p_column, 32 * data->p_line);
				close_window(data);
			}
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_column--;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->imgp_l, 32 * data->p_column, 32 * data->p_line);
		}
	}
}

void	key_w(t_data *data)
{
	if (data->map[data->p_line -1][data->p_column] != '1')
	{
		if (data->map[data->p_line -1][data->p_column] == 'C')
		{
			data->p_collection++;
			data->map[data->p_line - 1][data->p_column] = '0';
		}
		if (data->map[data->p_line - 1][data->p_column] == 'E')
		{
			if (data->p_collection == data->collection)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img0, 32 * data->p_column, 32 * data->p_line);
				data->p_line--;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgp_up, 32 * data->p_column, 32 * data->p_line);
				close_window(data);
			}
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_line--;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->imgp_up, 32 * data->p_column, 32 * data->p_line);
		}
	}
}

void	key_s(t_data *data)
{
	if (data->map[data->p_line + 1][data->p_column] != '1')
	{
		if (data->map[data->p_line + 1][data->p_column] == 'C')
		{
			data->p_collection++;
			data->map[data->p_line + 1][data->p_column] = '0';
		}
		if (data->map[data->p_line + 1][data->p_column] == 'E')
		{
			if (data->p_collection == data->collection)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->img0, 32 * data->p_column, 32 * data->p_line);
				data->p_line++;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
					data->imgp, 32 * data->p_column, 32 * data->p_line);
				close_window(data);
			}
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_line++;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
				data->imgp, 32 * data->p_column, 32 * data->p_line);
		}
	}
}
