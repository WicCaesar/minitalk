/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:19:04 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/18 18:46:21 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lowerflags(t_flags *flags);
void	raiseflags(const char *exp, t_flags *flags);
void	treatflags(const char *exp, int *places, t_flags *flags);
void	treatspecs(const char *exp, int *count, t_flags *flags);
int		ft_printf(const char *fixed, ...);

void	lowerflags(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

void	raiseflags(const char *exp, t_flags *flags)
{
	while (ft_strchr(".-0#+ ", exp[++flags->i]))
	{
		if (exp[flags->i] == '-')
			flags->dash = 1;
		if (exp[flags->i] == '0')
			flags->zero = 1;
		if (exp[flags->i] == '#')
			flags->hash = 1;
		if (exp[flags->i] == '+')
			flags->plus = 1;
		if (exp[flags->i] == ' ')
			flags->space = 1;
	}
	if (flags->plus == 1 && flags->space == 1)
		flags->space = 0;
}

/* Manage all the following flags:
- Left-justify within the given field width; Right justification is the default.
0 ~Left-pads~ the number with zeroes (0) instead of spaces.
. precision (displays only .X amount of characters)
# Used with x or X specifiers, the value is ~preceded~ with 0x or 0X
respectively for values different from zero.
+ Forces to precede the result with a + or - sign, even for positive numbers.
space If no sign is going to be written, a space is inserted before the value.

For specifiers d and i, precision is the minimum number of digits to be print.
For the specifier s, the precision is the maximum field width.
Stay tuned when:

Flag '0' is ignored when flag '-' is present.
Flag '0' is ignored when flag '.' is present (%d e %i)
Flag '0' result in undefined behavior with specifier c, s and p
Flag '.' result in undefined behavior with specifier c and p
Syntax to use printf:
%[flag][minwidth][.][precision][conversion specifier]*/

// The prototype of va_start defines what is "fixed" on the process, i.e. what
// value is to be "ignored". From there on, everything else is considered part
// of the list. For every va_start, there must be a va_end in the same function.
/* E.g.:		int multiply (int howmanyfactors, ...)
				va_list factors;
				va_start (factors, howmanyfactors);
								...
				printf("8! = %d\n", multiply(7, 8, 7, 6, 5, 4, 3, 2));
The first 7 is ignored, not part of the list, useful for the while loop.
The other numbers are considered part of the list.*/
void	treatflags(const char *exp, int *count, t_flags *flags)
{
	sign(exp, count, flags);
	treatspecs(exp, count, flags);
}

/*
• %% Prints a percent sign.
• %c Prints a single character.
• %s Prints a string.
• %p The void * pointer argument has to be printed in hexadecimal format.
• %i Prints an integer in base 10.
• %d Prints a decimal (base 10) number.
• %u Prints an unsigned decimal (base 10) number.
• %o Prints an unsigned octal (base 8) number.
• %x Prints an unsigned hexadecimal (base 16) lowercase format.
• %X Prints an unsigned hexadecimal (base 16) uppercase format.
*/
void	treatspecs(const char *exp, int *count, t_flags *flags)
{
	if (exp[flags->i] == 'c' || exp[flags->i] == 'C')
		*count += ft_putchar_fd(FD, va_arg(flags->argument, int));
	if (exp[flags->i] == 's' || exp[flags->i] == 'S')
		*count += ft_putstr_fd(FD, va_arg(flags->argument, char *));
	if (exp[flags->i] == 'd' || exp[flags->i] == 'i'
		|| exp[flags->i] == 'D' || exp[flags->i] == 'I')
		*count += ft_putint(va_arg(flags->argument, int));
	if (exp[flags->i] == 'u' || exp[flags->i] == 'U')
		*count += ft_putuns(va_arg(flags->argument, unsigned int));
	if (exp[flags->i] == 'o' || exp[flags->i] == 'O')
		*count += ft_putoct(va_arg(flags->argument, unsigned int));
	if (exp[flags->i] == 'x' || exp[flags->i] == 'X')
		*count
			+= ft_puthex(exp[flags->i], va_arg(flags->argument, unsigned int));
	if (exp[flags->i] == 'p' || exp[flags->i] == 'P')
		*count += ft_putptr(va_arg(flags->argument, unsigned long long));
	if (exp[flags->i] == '%')
		*count += ft_putchar_fd(FD, exp[flags->i]);
}

// Creates a structure that holds every possible element of printf.
// Starts the variadic function macro, that runs along the string and shows each
// character on screen. If it finds a %, three actions are taken:
// 1. Resets the flags to zero, "cleaning" them from previous iterations;
// 2. Identifies each flag (padding, precision, sign, minimum width);
// 3. Treats the encountered flags accordingly.
int	ft_printf(const char *fixed, ...)
{
	int		count;
	t_flags	*flags;

	count = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags || !fixed)
		return (0);
	va_start(flags->argument, fixed);
	flags->i = 0;
	while (fixed[flags->i] != '\0')
	{
		if (fixed[flags->i] == '%' && fixed[flags->i + 1] != '\0')
		{
			lowerflags(flags);
			raiseflags(fixed, flags);
			treatflags(fixed, &count, flags);
		}
		else
			count += ft_putchar_fd(FD, fixed[flags->i]);
		flags->i++;
	}
	va_end(flags->argument);
	free(flags);
	return (count);
}
