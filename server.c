/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:36:54 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/21 20:27:37 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo)
{
	
}

int	main(void)
{
	char				*pid;
	struct sigaction	act;
	sigset_t			blk;

	pid = ft_itoa(getpid());
	ft_putstr(pid);
	ft_free(&pid);
	act.__sigaction_u.__sa_handler = handler;
	sigemptyset(&blk);
	sigaddset(&blk, SIGUSR1);
	sigaddset(&blk, SIGUSR2);
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		error_out();
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		error_out();
	while (1)
		pause();
}
