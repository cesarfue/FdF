/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:42:34 by cesar             #+#    #+#             */
/*   Updated: 2023/12/16 17:51:33 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

ssize_t	switch_strings(const char c, va_list args, ssize_t *p_ret)
{
	if (c == 'c')
	{
		if (ft_pf_putchar(va_arg(args, int), p_ret) == -1)
			return (-1);
	}
	else if (c == 's')
	{
		if (ft_pf_putstr(va_arg(args, char *), p_ret) == -1)
			return (-1);
	}
	else
	{
		if (switch_decimals(c, args, p_ret) == -1)
			return (-1);
	}
	return (0);
}

ssize_t	switch_decimals(const char c, va_list args, ssize_t *p_ret)
{
	if (c == 'd' || c == 'i')
	{
		if (ft_pf_putnbr(va_arg(args, int), p_ret) == -1)
			return (-1);
	}
	else if (c == 'u')
	{
		if (ft_pf_putnbr((unsigned int)va_arg(args, int), p_ret) == -1)
			return (-1);
	}
	else
	{
		if (switch_hexa(c, args, p_ret) == -1)
			return (-1);
	}
	return (0);
}

ssize_t	switch_hexa(const char c, va_list args, ssize_t *p_ret)
{
	uintptr_t		p_ptr;

	if (c == 'p')
	{
		p_ptr = (uintptr_t)va_arg(args, void *);
		if (!p_ptr)
		{
			ft_pf_putstr("(nil)", p_ret);
			return (-1);
		}
		ft_pf_putstr("0x", p_ret);
		ft_pf_putptr(p_ptr, p_ret);
	}
	else
	{
		if (switch_ptr(c, args, p_ret) == -1)
			return (-1);
	}
	return (0);
}

ssize_t	switch_ptr(const char c, va_list args, ssize_t *p_ret)
{
	if (c == 'x')
	{
		if (ft_pf_putptrlow((uintptr_t)va_arg(args, void *), p_ret) == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		if (ft_pf_putptrhigh((uintptr_t)va_arg(args, void *), p_ret) == -1)
			return (-1);
	}
	else
	{
		if (switch_else(c, p_ret) == -1)
			return (-1);
	}
	return (0);
}

ssize_t	switch_else(const char c, ssize_t *p_ret)
{
	if (c == '%')
	{
		if (ft_pf_putchar(c, p_ret) == -1)
			return (-1);
	}
	return (0);
}
