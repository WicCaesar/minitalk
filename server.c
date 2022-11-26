/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:43:38 by cnascime          #+#    #+#             */
/*   Updated: 2022/11/26 18:14:58 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	receive_char(int signal);

// Gets the process ID of the calling process. Starts listening for a message.
// When a message is received, it prints it and hopefully sends a confirmation.
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, receive_char);
	signal(SIGUSR2, receive_char);
	while (1)
		pause();
	return (0);
}

// Static variables are initialized to 0.
// If it receives SIGUSR2, it interprets that bit as 1.
// Signal handlers run asynchronously, which means they can be interrupted by
// other signals at any point, so it's recommended to use one of the 
// standard library's async-signal-safe functions, such as write, not printf.
// To print 10.000 bytes, it shouldn't take more than 1'40".
void	receive_char(int signal)
{
	static char	character;
	static int	bit;

	if (signal == SIGUSR2)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		bit = 0;
		character = 0;
	}
}
