/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:14:37 by livardan          #+#    #+#             */
/*   Updated: 2022/07/11 13:39:29 by livardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> // sigaction, signal, kill
# include <unistd.h> // getpid, write, exit, pause, usleep
# include <stdlib.h> // malloc, free

void error(char *str);
void luck(int signum, siginfo_t *siginfo, void *unused);
void servers_pid(void);
char *ft_itoa(int n);
int ft_atoi(const char *str);
void ft_putstr(char *str);
void ft_putchar(char c);
int ft_strlen(const char *str);

#endif