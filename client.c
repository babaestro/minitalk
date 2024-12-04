/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:03:59 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/07/11 13:19:49 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	ft_acknowledge(int sig)
{
	if (sig == SIGUSR1)
	{
		g_ack = 1;
		ft_printf("Message received by server!");
	}
}

void	send_char(pid_t pid, char c_message)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c_message & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid_server;
	char				*message;

	sa.sa_handler = ft_acknowledge;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (argc != 3)
	{
		ft_printf("ERROR ! This how it works : ./client <PID> <MESSAGE> \n");
		return (1);
	}
	pid_server = (pid_t)ft_atoi(argv[1]);
	if (kill(pid_server, 0) == -1)
	{
		ft_printf("WRONG PID !\n");
		return (1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	message = argv[2];
	while (*message)
		send_char(pid_server, *message++);
	send_char(pid_server, '\0');
	return (0);
}
