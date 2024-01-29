/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:24:37 by cesar             #+#    #+#             */
/*   Updated: 2024/01/29 16:22:11 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h" 

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	
	if (size == 0)
		return (NULL);
	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(ret, ptr, size);
		free(ptr);
	}
	return (ret);
}