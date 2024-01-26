/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:24:37 by cesar             #+#    #+#             */
/*   Updated: 2024/01/26 16:20:06 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h" 

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	
	if (size == 0)
		return (free(ptr), NULL);
	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(ret, ptr, size - 1);
		free(ptr);
	}
	return (ret);
}