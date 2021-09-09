/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:39:36 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/09/05 16:11:25 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	get_signal(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signo;
}

void	converse(char ascii, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((ascii >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

int	message(int server_pid, char *msg)
{
	struct sigaction	signal;
	siginfo_t			siginfo;
	int					i;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &get_signal;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, 0);
	siginfo.si_pid = server_pid;
	i = 0;
	while (msg[i] != '\0')
	{
		converse(msg[i], server_pid);
		i++;
	}
	converse(msg[i], server_pid);
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = &get_signal;
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (argc == 3)
		message(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr_fd("Error arguments\n", 1);
	return (0);
}
