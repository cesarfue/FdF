/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:24:37 by cesar             #+#    #+#             */
/*   Updated: 2024/01/31 09:05:34 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*ret;

	ret = malloc(new_size);
	if (!ret)
		return (NULL);
	if (!ptr)
		return (ret);
	ft_memmove(ret, ptr, old_size);
	return (free(ptr), ret); 
}
