/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:38:57 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 02:55:59 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_d(t_data *data)
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
				close_window(data);
			return (0);
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_column++;
			mlx_put_image_to_window(data->ptr, data->win,
				data->imgp, 32 * data->p_column, 32 * data->p_line);
		}
		return (1);
	}
	return (0);
}

int	key_a(t_data *data)
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
				close_window(data);
			return (0);
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_column--;
			mlx_put_image_to_window(data->ptr, data->win,
				data->imgp_l, 32 * data->p_column, 32 * data->p_line);
		}
		return (1);
	}
	return (0);
}

int	key_w(t_data *data)
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
				close_window(data);
			return (0);	
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_line--;
			mlx_put_image_to_window(data->ptr, data->win,
				data->imgp_up, 32 * data->p_column, 32 * data->p_line);
		}
		return (1);
	}
	return (0);
}

int	key_s(t_data *data)
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
				close_window(data);
			return (0);
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win,
				data->img0, 32 * data->p_column, 32 * data->p_line);
			data->p_line++;
			mlx_put_image_to_window(data->ptr, data->win,
				data->imgp, 32 * data->p_column, 32 * data->p_line);
		}
		return (1);
	}
	return (0);
}
