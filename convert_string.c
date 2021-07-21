/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:57:02 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/21 20:09:03 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					pos;
	int					i;

	res = 0;
	pos = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		++i;
	if (nptr[i] == '-')
		pos *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		++i;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + (res * 10);
		if (res > 9223372036854775807 && (pos == 1))
			return (-1);
		if (res > 9223372036854775807 && (pos == -1))
			return (0);
		++i;
	}
	return (res * pos);
}

static int	get_size(int n)
{
	int			res;
	long long	tmp;

	if (n == 0)
		return (1);
	res = 0;
	tmp = n;
	if (n < 0)
	{
		res += 1;
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		res += 1;
		tmp /= 10;
	}
	return (res);
}

static void	assign_ptr(char *ptr, int n, int size)
{
	long long	tmp;

	ptr[size] = 0;
	if (n == 0)
	{
		ptr[0] = '0';
		return ;
	}
	tmp = n;
	if (n < 0)
	{
		ptr[0] = '-';
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		ptr[--size] = '0' + (tmp % 10);
		tmp /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	size = get_size(n);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	assign_ptr(ptr, n, size);
	return (ptr);
}
