/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:05:36 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/24 03:11:29 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_pow(int base, int n)
{
	int	res;
	int	i;

	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	res = base;
	i = 0;
	while (++i < n)
		res *= base;
	return (res);
}

void	error_out(char *msg)
{
	ft_putstr(msg);
	exit(1);
}
