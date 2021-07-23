/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:36:54 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/23 23:18:51 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(char *pid)
{
	if (pid == NULL)
		error_out("error : not found pid");
	ft_putstr("server pid : ");
	ft_putstr(pid);
	ft_putchar('\n');
}

void	handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c = c | ft_pow(2, i);
	++i;
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	char				*pid;
	struct sigaction	act;
	sigset_t			blk;

	pid = ft_itoa(getpid());
	print_pid(pid);
	ft_free(&pid);
	//-------------
	act.__sigaction_u.__sa_handler = handler;
	sigemptyset(&blk);
	sigaddset(&blk, SIGUSR1);
	sigaddset(&blk, SIGUSR2);
	act.sa_mask = blk;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		error_out("error : signal send failed\n");
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		error_out("error : signal send failed\n");
	//------------- 여기까지 sigaction 사용 signal 도 한번 사용해보자 = 블록하지않아도 오류가 나지 않는가
	while (1)
		pause();
	return (0);
}
