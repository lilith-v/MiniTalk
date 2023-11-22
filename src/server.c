/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:37 by livardan          #+#    #+#             */
/*   Updated: 2022/07/11 13:45:29 by livardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void signal_handler(int signum)
{
	static int ascii = 0;
	static int power = 0;

	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	if ((power += 1) == 8)
	{
		ft_putchar(ascii);
		ascii = 0;
		power = 0;
	}
}

int main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (42)
	{};
	return (0);
}