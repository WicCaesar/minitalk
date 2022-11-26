/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:13:07 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/18 18:45:23 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoiforprintf(const char *str);
static int	ft_isignored(char c);
void		sign(const char *exp, int *count, t_flags *flags);

/* Converts a numeric character in a string to an integer by subtracting 0 from
the corresponding ASCII decimal value to get a valid numerical value, then
multiplies by 10 to calculate the following digit. It skips spaces and tabs.
Especially for ft_printf, it ignores all characters that represent flags. */
int	ft_atoiforprintf(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		while (ft_isignored(str[i]))
			i++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		return (num);
	}
	return (0);
}

static int	ft_isignored(char c)
{
	if (c == '%' || c == '.' || c == '-' || c == '+' || c == '#' || c == ' '
		|| (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*
+ Forces to precede the result with a + or - sign, even for positive numbers.
space If no sign is going to be written, a space is inserted before the value.
Sign only appears in numeric values. Undefined behaviour with 's' specifier.
Space is ignored when sign is present.
# Used with o, x or X specifiers, the value is ~preceded~ with 0, 0x or 0X
respectively for values different from zero. */
void	sign(const char *exp, int *count, t_flags *flags)
{
	va_list	sign;
	int		value;

	va_copy(sign, flags->argument);
	value = va_arg(sign, int);
	if (flags->plus == 1 && value < 0 && !ft_strchr("cupidosxX", exp[flags->i]))
		*count += ft_putchar_fd(FD, '-');
	if (flags->plus == 1 && value >= 0 && ft_strchr("diu", exp[flags->i]))
		*count += ft_putchar_fd(FD, '+');
	if (flags->space == 1 && value >= 0 && !ft_strchr("cs", exp[flags->i]))
		*count += ft_putchar_fd(FD, ' ');
	if (flags->hash == 1 && value != 0 && exp[flags->i] == 'o')
		*count += ft_putchar_fd(FD, '0');
	if (flags->hash == 1 && value != 0 && exp[flags->i] == 'x')
		*count += ft_putstr_fd(FD, "0x");
	if (flags->hash == 1 && value != 0 && exp[flags->i] == 'X')
		*count += ft_putstr_fd(FD, "0X");
	va_end(sign);
}
