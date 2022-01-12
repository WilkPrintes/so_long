/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:43:00 by wprintes          #+#    #+#             */
/*   Updated: 2022/01/12 20:41:21 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "./libraries/minilibx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    void	*mlx_ptr;
    void    *mlx_window;
    void    *img1;
    void    *img0;
    void    *imgc;
    void    *imge;
    void    *imgp;
    void    *imgp_l;
    void    *imgp_up;
    int     p_line;
    int     p_column;
    int     img_x;
    int     img_y;
    char    **map;
    int     collection;
    int     p_collection;
    int     lines;
    int     columns;
}t_data;

int render(void);
int close_window(t_data *data);
char **get_map(void);