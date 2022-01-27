/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/24 18:01:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_window(t_data *data);
void	set_assets(t_data *data);
int		error(int argc, char *argv[]);

int	get_key(int key, t_data *data)
{
	static int	count;
	static int	validation;

	if (validation != 1)
		count = 0;
	if (key == 65307)
		close_window(data);
	if (key == 100)
		count = count + key_d(data);
	if (key == 97)
		count = count + key_a(data);
	if (key == 119)
		count = count + key_w(data);
	if (key == 115)
		count = count + key_s(data);
	printf("passos = %d\n", count);
	validation = 1;
}

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	mlx_clear_window(data->ptr, data->win);
	mlx_loop_end(data->ptr);
	mlx_destroy_image(data->ptr, data->imgp);
	mlx_destroy_image(data->ptr, data->imgp_up);
	mlx_destroy_image(data->ptr, data->imgp_l);
	mlx_destroy_image(data->ptr, data->imgc);
	mlx_destroy_image(data->ptr, data->imge);
	mlx_destroy_image(data->ptr, data->img0);
	mlx_destroy_image(data->ptr, data->img1);
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->ptr);
	exit(3);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		count;
	int		line;

	error(argc, argv);
	data.ptr = mlx_init();
	get_map(argv[1], &data);
	data.win = mlx_new_window(data.ptr, data.columns * 32, data.lines * 32, "so_long");
	set_assets(&data);
	render_map(&data);
	mlx_key_hook(data.win, &get_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.ptr);
}

int	error(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("invalid number of arguments\n");
		exit(0);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
	{
		printf("Error\nYou must use a '.ber' file.\n");
		exit(0);
	}
	return (0);
}

void	set_assets(t_data *data)
{
	data->img1 = mlx_xpm_file_to_image(data->ptr,
			"./assets/1.xpm", &data->img_x, &data->img_y);
	data->img0 = mlx_xpm_file_to_image(data->ptr,
			"./assets/0.xpm", &data->img_x, &data->img_y);
	data->imgc = mlx_xpm_file_to_image(data->ptr,
			"./assets/c.xpm", &data->img_x, &data->img_y);
	data->imge = mlx_xpm_file_to_image(data->ptr,
			"./assets/e.xpm", &data->img_x, &data->img_y);
	data->imgp = mlx_xpm_file_to_image(data->ptr,
			"./assets/p.xpm", &data->img_x, &data->img_y);
	data->imgp_l = mlx_xpm_file_to_image(data->ptr,
			"./assets/p_l.xpm", &data->img_x, &data->img_y);
	data->imgp_up = mlx_xpm_file_to_image(data->ptr,
			"./assets/p_up.xpm", &data->img_x, &data->img_y);
}
