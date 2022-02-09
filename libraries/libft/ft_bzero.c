/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/09 15:44:30 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			counter;
	char			*str_p;

	counter = 0;
	str_p = str;
	while (counter != n)
	{
		str_p[counter] = '\0';
		counter++;
	}
}
