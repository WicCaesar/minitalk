/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:42:25 by cnascime          #+#    #+#             */
/*   Updated: 2022/11/26 20:25:29 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c);

// Insert the PID of the server in the first argument.
// Insert the message in the second argument.
// The message will be sent one character at a time.
// The server will print the message. Once finished, the client exits.
int	main(int argc, char **argv)
{
	int	pid;
	int	index;

	if (argc != 3 || !ft_isnumeric(argv[1]) || !argv[2])
	{
		ft_printf("Execute o comando ./client [ID do processo] [mensagem].\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	index = 0;
	while (argv[2][index] != '\0')
		send_char(pid, argv[2][index++]);
	return (0);
}

// Sends a character to the server, one bit at a time.
// Id est, kill sends a signal to the process specified in the first argument.
// The second argument is the signal.
// Shifts left by the index of the bit, eight times to complete a character.
// If the result of the comparison is TRUE, sends SIGUSR2. If FALSE, SIGUSR1.
void	send_char(int pid, char character)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (character & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(777);
	}
}
