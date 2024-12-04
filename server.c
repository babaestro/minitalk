/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:04:02 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/07/11 13:20:46 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include "libft.h"
#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char				message;
	static int				bit_index = 0;
	static unsigned char	c = 0;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1) 
		c |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		message = c;
		if (c == '\0')
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
		}
		else
			ft_printf("%c", message);
		c = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("--------------------------------\n \n"
		"Welcome to Minitalk \U0001F44B \n"
		"Your Server PID is: %d \U0001F440\n \n"
		"----------------------------------\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
