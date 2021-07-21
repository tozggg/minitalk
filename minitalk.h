/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:30:02 by taejkim           #+#    #+#             */
/*   Updated: 2021/07/21 20:26:47 by taejkim          ###   ########.fr       */
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

void	ft_free(char **ptr);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	error_out(void);

#endif
