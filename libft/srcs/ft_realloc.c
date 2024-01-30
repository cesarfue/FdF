/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:24:37 by cesar             #+#    #+#             */
/*   Updated: 2024/01/30 14:54:46 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	size_t	old_size;

	if (size == 0)
		return (free(ptr), NULL);
	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	else if (ptr == NULL)
		return (ret);
	old_size = sizeof(ret);
	if (size <= old_size)
		return (ret);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	return (ret);
}