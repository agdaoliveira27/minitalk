/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 02:08:39 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/10 20:13:19 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	char	*msg;
	char	chr;
	int		bit;
}	t_data;

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
char	*ft_strccpy(char *dest, char *src, char c);
size_t	ft_strlen(const char *str);

#endif