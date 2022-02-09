/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:35:27 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/09 16:56:02 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "get_next_line.h"
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img1;
	void	*img0;
	void	*imgc;
	void	*imge;
	void	*imgp;
	void	*imgp_l;
	void	*imgp_up;
	int		p_line;
	int		p_column;
	int		img_x;
	int		img_y;
	char	**map;
	int		collection;
	int		p_collection;
	int		lines;
	int		columns;
}t_data;

int		close_window(t_data *data);
int		get_map(char *path, t_data *data);
int		key_w(t_data *data);
int		key_a(t_data *data);
int		key_s(t_data *data);
int		key_d(t_data *data);
int		render_map(t_data *data);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
void	free_matrix(t_data *data);
int		validations(char **map, int count, int len_init);
int		*find_contents(char **map, int lines, int columns);
int		walls(char **map, int lines);
void	empty_file(t_data *data, char *temp, char *line);

#endif