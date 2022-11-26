/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:43:38 by cnascime          #+#    #+#             */
/*   Updated: 2022/11/24 23:07:42 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	receive_char(int signal, siginfo_t *info, void *ucontext);

// Gets the process ID of the calling process. Starts listening for a message.
// When a message is received, it prints it and hopefully sends a confirmation.
int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	act.sa_sigaction = receive_char;
	act.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

// Static variables are initialized to 0.
// If it receives SIGUSR2, it interprets that bit as 1.
// Signal handlers run asynchronously, which means they can be interrupted by
// other signals at any point, so it's recommended to use one of the 
// standard library's async-signal-safe functions, such as write, not printf.
// Casting ucontext to void* is a way to silence the compiler warning.
// When receiving the null character, sends back a confirmation signal.
void	receive_char(int signal, siginfo_t *info, void *ucontext)
{
	static char			character;
	static int			bit;
	static int			clientpid;

	(void)ucontext;
	clientpid = info->si_pid;
	if (signal == SIGUSR2)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			kill(clientpid, SIGUSR2);
		bit = 0;
		character = 0;
	}
}
