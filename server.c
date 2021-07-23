/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:36:54 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/24 03:13:42 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(char *pid)
{
	if (pid == NULL)
		error_out("error : not found pid\n");
	ft_putstr("server pid : ");
	ft_putstr(pid);
	ft_putchar('\n');
}

void	handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c |= ft_pow(2, i);
	++i;
	if (i == 8)
	{
		if (c == 0)
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	print_pid(pid);
	free(pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
