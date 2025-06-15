/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:48:00 by agbarbos          #+#    #+#             */
/*   Updated: 2025/02/06 08:05:18 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_msg_received = 0;

static void	send_char(pid_t pid, char c)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 7;
	while (i >= 0)
	{
		g_msg_received = 0;
		if ((chr >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_msg_received == 0)
			;
		i--;
	}
}

static void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_msg_received = 1;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (ft_putstr("Please inform the PID and the message.\n"), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
		return (ft_putstr("Invalid PID.\n"), 2);
	signal(SIGUSR1, handle_signal);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
