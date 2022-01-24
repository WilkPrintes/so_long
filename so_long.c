/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/22 00:25:15 by wprintes         ###   ########.fr       */
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
	printf("=====get_key=====\n");
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
	printf("=====get_key ok=====\n");
	validation = 1;
}

int	close_window(t_data *data)
{
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
	line = 0;
	data.ptr = mlx_init();
	printf("ptr iniciado, pegando mapa\n");
	data.map = get_map(argv[1]);
	printf("MAPA COMPLETO EM data.map\n");
	if (data.map == NULL)
	{
		free(data.ptr);
		return (-1);
	}
	count = ft_strlen(data.map[0]) - 1;
	printf("Iniciado count\n");
	while (data.map[line][count] != '\0')
		line++;
	printf("Total de linhas: %d\n", line);
	data.win = mlx_new_window(data.ptr, 32 * count, 32 * (line + 1), "so_long");
	printf("data.win iniciada\n");
	set_assets(&data);
	data.lines = line;
	printf("data.lines iniciada\n");
	data.columns = count -1;
	printf("data.columns iniciada\n");
	render_map(&data);
	mlx_key_hook(data.win, &get_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.ptr);
}

int	error(int argc, char *argv[])
{
	printf("verificando erros\n");
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
	printf("tudo ok\n");
	return (0);
}

void	set_assets(t_data *data)
{
	printf("=====set_assets=====\n");
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
	printf("=====set_assets ok=====\n");
}
