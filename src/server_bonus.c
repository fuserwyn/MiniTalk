/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:39:46 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/09/05 14:39:46 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include "../libft/libft.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	get_signal(int signal, siginfo_t *siginfo, void *unused)
{
	static char	a;
	static int	i;

	(void)unused;
	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
	{
		a = a | (1 << i);
		i++;
	}
	if (i == 8)
	{
		write(1, &a, 1);
		a = 0;
		i = 0;
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Error signal", 1);
		return ;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	signal;

	(void)argv;
	pid = getpid();
	if (argc != 1)
		error("Error arguments\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &get_signal;
	sigemptyset(&signal.sa_mask);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
