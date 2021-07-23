/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:36:48 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/23 23:19:56 by taejkim          ###   ########.fr       */
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
		// 이거 조절
		usleep(80);
		++i;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*str;
	int		i;

	if (ac != 3)
		error_out("error : ./client [server pid] [string to sent]\n");
	pid = atoi(av[1]);
	//여기 pid 적합성검사 => 실제하는 서버의 pid인가 , 해당 pid의 서버에서 응답을 받을수 있는가
	str = av[2];
	i = 0;
	while (str[i])
		transmit(pid, str[i++]);
	return (0);
}
