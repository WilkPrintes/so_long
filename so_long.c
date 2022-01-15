/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/15 00:33:15 by wprintes         ###   ########.fr       */
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
	printf("closing\n");
	mlx_destroy_window(data->ptr, data->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		count;
	int		line;

	error(argc, argv);
	line = 0;
	data.ptr = mlx_init();
	data.map = get_map(argv[1]);
	if (data.map == NULL)
	{
		free(data.ptr);
		return (-1);
	}
	count = ft_strlen(data.map[0]) - 1;
	while (data.map[line][count] != '\0')
		line++;
	data.win = mlx_new_window(data.ptr, 32 * count, 32 * (line + 1), "so_long");
	set_assets(&data);
	data.lines = line;
	data.columns = count -1;
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
		exit(-1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
	{
		printf("Error\nYou must use a '.ber' file.\n");
		exit(0);
		return (-1);
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
