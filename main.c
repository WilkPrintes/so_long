/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:12:48 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/07 17:07:27 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    void	*mlx_ptr;
    void    *mlx_window;

}t_data;

int close_window(t_data *data);

int get_key(int key, t_data *data)
{
    if (key == 120)
        close_window(data);
    else
        printf("key = %d\n", key);
}

int close_window(t_data *data)
{
    printf("fechando a janela\n");
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
    exit(0);
}

int main(void)
{
    void    *img;
    int    img_x;
    int    img_y;

	t_data data;
	data.mlx_ptr = mlx_init();
    data.mlx_window = mlx_new_window(data.mlx_ptr, 800, 600, "so_long");
    
    img = mlx_xpm_file_to_image(data.mlx_ptr, "./download.xpm", &img_x, &img_y);
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, img, 0, 0);
    mlx_key_hook(data.mlx_window, &get_key, &data);
    mlx_loop(data.mlx_ptr);
}

