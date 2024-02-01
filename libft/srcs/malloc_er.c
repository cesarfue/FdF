/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_er.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:04:57 by cesar             #+#    #+#             */
/*   Updated: 2024/02/01 16:06:27 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*malloc_er(size_t size) /* Malloc, but better */
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		quit("Memory allocation failed");
	return (ret);
}
