/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:20:37 by livardan          #+#    #+#             */
/*   Updated: 2022/07/11 13:42:29 by livardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int signe;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signe);
}


void ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void decimal(char ascii,int power,int  pid)
{
	if (power > 0)
		decimal(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
		kill (pid, SIGUSR1);
	else
		kill (pid, SIGUSR2);
	usleep(10);
}

void string_to_binary (char *str,char*  pid1)
{
	int pid;
	int i;

	i = 0;
	pid = ft_atoi(pid1);
	while (str[i] != '\0')
	{

		decimal(str[i], 7, pid);
		i += 1;
	}

}
int main(int ac, char **av)
{

	if (ac == 3)
		string_to_binary(av[1], av[2]);
	else
		ft_putstr("usage: client server_pid msg_to_send\n");
	return (0);
}