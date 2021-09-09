/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:17:53 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/09/05 15:18:20 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

typedef struct s_sig
{
	int			size;
	int			pid;
	char		c;
}				t_sig;

void	get_signal(int signal, siginfo_t *siginfo, void *unused);
void	error(char *str);
int		message(int server_pid, char *msg);
void	hand(int signal, siginfo_t *siginfo, void *unused);
void	converse(char ascii, int pid);

#endif