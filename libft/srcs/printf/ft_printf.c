/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:56 by cesar             #+#    #+#             */
/*   Updated: 2023/12/16 17:54:12 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	ssize_t		ret;
	ssize_t		*p_ret;
	va_list		args;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = 0;
	p_ret = &ret;
	i = -1;
	while (format[++i] && ret != -1)
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (!(switch_strings(format[++i], args, p_ret)))
				return (-1);
		}
		else if (format[i] == '%' && !format[i + 1])
			return (-1);
		else
			ft_pf_putchar(format[i], p_ret);
	}
	va_end(args);
	return (ret);
}
