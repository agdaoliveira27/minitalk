/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 02:14:54 by agbarbos          #+#    #+#             */
/*   Updated: 2025/02/08 02:49:57 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data = {NULL, 0, 0};

static	void	add_char(char c)
{
	char	*str;
	int		len;

	len = 0;
	if (g_data.msg)
		len = ft_strlen(g_data.msg);
	str = (char *)malloc(len + 2);
	if (str == NULL)
		return ;
	if (g_data.msg)
	{
		str = ft_strccpy(str, g_data.msg, c);
		free(g_data.msg);
		g_data.msg = str;
	}
	else
	{
		g_data.msg = str;
		g_data.msg[len] = c;
		g_data.msg[len + 1] = '\0';
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_data.chr = g_data.chr << 1;
	if (signal == SIGUSR2)
		g_data.chr |= 1;
	g_data.bit++;
	if (g_data.bit == 8)
	{
		add_char(g_data.chr);
		if (g_data.chr == '\0')
		{
			ft_putstr(g_data.msg);
			write(1, "\n", 1);
			if (g_data.msg)
			{
				free(g_data.msg);
				g_data.msg = NULL;
				kill(info->si_pid, SIGUSR1);
			}
		}
		g_data.chr = 0;
		g_data.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	connection;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	connection.sa_sigaction = handle_signal;
	connection.sa_flags = SA_SIGINFO;
	sigemptyset(&connection.sa_mask);
	sigaction(SIGUSR1, &connection, NULL);
	sigaction(SIGUSR2, &connection, NULL);
	while (1)
		pause();
	return (0);
}
