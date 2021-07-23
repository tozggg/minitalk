/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:36:48 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/24 03:02:57 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transmit(int pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		if (bit == 0)
			kill(pid, SIGUSR2);
		usleep(100);
		++i;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*str;
	int		i;

	if (ac != 3)
		error_out("error : ./client [server pid] [string to pass]\n");
	pid = atoi(av[1]);
	if (!(100 <= pid && pid <= 100000))
		error_out("error : pid incorret\n");
	str = av[2];
	i = 0;
	while (str[i])
		transmit(pid, str[i++]);
	transmit(pid, 0);
	return (0);
}
