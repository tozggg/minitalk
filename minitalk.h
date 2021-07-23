/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:30:02 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/23 23:57:29 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_pow(int base, int n);

void	ft_free(char **ptr);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	error_out(char *msg);

#endif
