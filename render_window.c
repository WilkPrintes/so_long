/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/13 18:12:40 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data);
void set_assets(t_data *data);

int	get_key(int key, t_data *data)
{
	static int count;
	static int validation;

	if (validation != 1)
		count = 0;
	if (key == 120)
		close_window(data);
	if (key == 100)
		key_d(data);
	if (key == 97)
		key_a(data);
	if (key == 119)
		key_w(data);
	if (key == 115)
		key_s(data);
	else
	{
		count++;
		validation = 1;
		printf("passos = %d\n", count);
	}
}

int	close_window(t_data *data)
{
	printf("fechando a janela\n");
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	exit(0);
}

int	render(void)
{
	t_data	data;
	int		count;
	int		line;

	line = 0;
	data.collection = 0;
	data.p_collection = 0;
	data.mlx_ptr = mlx_init();
	data.map = get_map();
	if (data.map == NULL)
	{
		free(data.mlx_ptr);
		return (-1);
	}
	count = ft_strlen(data.map[0]) - 1;
	while (data.map[line][count] != '\0')
		line++;
	line++;
	data.mlx_window = mlx_new_window(data.mlx_ptr,
			32 * count, 32 * line, "so_long");
	set_assets(&data);
	data.lines = line - 1;
	data.columns = count -1;
	render_map(&data);
	mlx_key_hook(data.mlx_window, &get_key, &data);
	mlx_hook(data.mlx_window, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}

void set_assets(t_data *data)
{
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/1.xpm", &data->img_x, &data->img_y);
	data->img0 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/0.xpm", &data->img_x, &data->img_y);
	data->imgc = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/c.xpm", &data->img_x, &data->img_y);
	data->imge = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/e.xpm", &data->img_x, &data->img_y);
	data->imgp = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/p.xpm", &data->img_x, &data->img_y);
	data->imgp_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/p_l.xpm", &data->img_x, &data->img_y);
	data->imgp_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/p_up.xpm", &data->img_x, &data->img_y);
}