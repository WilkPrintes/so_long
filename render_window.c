/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/12 20:42:04 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data);

int get_key(int key, t_data *data)
{
    if (key == 120)
        close_window(data);
    if (key == 100)
    {    
        if(data->map[data->p_line][data->p_column + 1] != '1')
        {
            if (data->map[data->p_line][data->p_column + 1] == 'C')
            {
                data->p_collection++;
                data->map[data->p_line][data->p_column + 1] = '0';
                printf("coletáveis %d/%d", data->p_collection, data->collection);
            }    
            if (data->map[data->p_line][data->p_column + 1] == 'E')
            {
                if (data->p_collection == data->collection)
                {
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                    data->p_column++;
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp, 32*data->p_column, 32*data->p_line);
                    close_window(data);
                }
            }else
            {
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                data->p_column++;
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp, 32*data->p_column, 32*data->p_line);
            }
        }
    }
    if (key == 97)
    {    
        if(data->map[data->p_line][data->p_column - 1] != '1')
        {  
            if (data->map[data->p_line][data->p_column - 1] == 'C')
            {
                data->p_collection++;
                data->map[data->p_line][data->p_column - 1] = '0';
                printf("coletáveis %d/%d", data->p_collection, data->collection);
            } 
            if (data->map[data->p_line][data->p_column - 1] == 'E')
            {
                if (data->p_collection == data->collection)
                {
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                    data->p_column--;
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp_l, 32*data->p_column, 32*data->p_line);
                    close_window(data);
                }
            }else
            {
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                data->p_column--;
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp_l, 32*data->p_column, 32*data->p_line);
            }
        }
    }
    if (key == 119)
    {
            
        if(data->map[data->p_line -1 ][data->p_column] != '1')
        {  
            if (data->map[data->p_line -1 ][data->p_column] == 'C')
            {
                data->p_collection++;
                data->map[data->p_line - 1][data->p_column] = '0';
                printf("coletáveis %d/%d", data->p_collection, data->collection);
            } 
            if (data->map[data->p_line - 1][data->p_column] == 'E')
            {
                if (data->p_collection == data->collection)
                {
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                    data->p_line--;
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp_up, 32*data->p_column, 32*data->p_line);
                    close_window(data);
                }
            }else
            {
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                data->p_line--;
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp_up, 32*data->p_column, 32*data->p_line);
            }
        }
    }
    if (key == 115)
    {    
        if(data->map[data->p_line + 1 ][data->p_column] != '1')
        {  
            if (data->map[data->p_line + 1 ][data->p_column] == 'C')
            {
                data->p_collection++;
                data->map[data->p_line + 1][data->p_column] = '0';
                printf("coletáveis %d/%d", data->p_collection, data->collection);
            } 
            if (data->map[data->p_line + 1][data->p_column] == 'E')
            {
                if (data->p_collection == data->collection)
                {
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                    data->p_line++;
                    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp, 32*data->p_column, 32*data->p_line);
                    close_window(data);
                }
            }else 
            {
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img0, 32*data->p_column, 32*data->p_line);
                data->p_line++;
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->imgp, 32*data->p_column, 32*data->p_line);
            } 
        }
    }
    else
        printf("key = %d\n", key);
}

int close_window(t_data *data)
{
    printf("fechando a janela\n");
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
    exit(0);
}

int render(void)
{
	t_data data;
    int count;
    int line;

    line = 0;
    data.collection = 0;
    data.p_collection = 0;
	data.mlx_ptr = mlx_init();
    data.map = get_map();
    count = ft_strlen(data.map[0]) - 1;
    while (data.map[line][count] != '\0')
        line++;
    line++;
    printf("%d / %d\n", line, count);
    data.mlx_window = mlx_new_window(data.mlx_ptr, 32*count, 32*line, "so_long");
    data.img1 = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/1.xpm", &data.img_x, &data.img_y);
    data.img0 = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/0.xpm", &data.img_x, &data.img_y);
    data.imgc = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/c.xpm", &data.img_x, &data.img_y);
    data.imge = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/e.xpm", &data.img_x, &data.img_y);
    data.imgp = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/p.xpm", &data.img_x, &data.img_y);
    data.imgp_l = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/p_l.xpm", &data.img_x, &data.img_y);
    data.imgp_up = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/p_up.xpm", &data.img_x, &data.img_y);
    data.lines = line - 1;
    data.columns = count -1;
    line = 0;
    count = 0;
    while (line <= data.lines)
    {
        count = 0;
        while(count <= data.columns)
        {
            if (data.map[line][count] == '1')
                mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img1, 32*count, 32*line);
            else if (data.map[line][count] == '0')
                mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img0, 32*count, 32*line);
            else if (data.map[line][count] == 'C')
            {
                mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.imgc, 32*count, 32*line);
                data.collection++;
            }
            else if (data.map[line][count] == 'E')
                mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.imge, 32*count, 32*line);
            else if (data.map[line][count] == 'P')
            {
                data.p_line = line;
                data.p_column = count;
                mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.imgp, 32*count, 32*line);
            }
            count++;
        }
        line++;
    }
    mlx_key_hook(data.mlx_window, &get_key, &data);
    mlx_hook(data.mlx_window, 17, 0, close_window, &data);
    mlx_loop(data.mlx_ptr);
}
