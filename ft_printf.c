/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:57:53 by iris              #+#    #+#             */
/*   Updated: 2022/11/08 11:31:06 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int printstr(char *str)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    if (str == NULL)
        return (write(1, "(null)", 6));
    while (str[i] != '\0')
    {
        counter += printchar(str[i]);
        i++;
    }
    return (counter);
}

int	putnbr(int nb)
{
	char	a;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		printchar('-');
		nb = nb * -1;
	}
	if (nb < 10 && nb != -2147483648)
	{
		a = nb + '0';
		printchar(a);
	}
	if (nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	} 
    return (nb);
}

int formatlist(va_list args, char format)
{
    int result;

    result = 0;
    if (format == 'c')
        result = printchar(va_arg(args, int));
    else if (format == '%')
        result = printchar('%');
    else if (format == 's')
        result = printstr(va_arg(args, char *));
    else if (format == 'd' || format == 'i')
        result = putnbr(va_arg(args, int));
 return (result);
}

int ft_printf(const char *format, ...)
{
    int i;
    int result;
    va_list args;

    i = 0;
    result = 0;
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            result += formatlist(args, format[i]);
        }
        else
            result += printchar(format[i]);
        i++;
    }
    va_end(args);
    return (result);
}

int main(void)
{
    int a;
    int b;

    // printf("printf: He %c l %c lo\n", '9', '8');
    // ft_printf("ft_printf: He %c l %c lo\n", '9', '8');
    // printf("printf: He l %% w l l o \n");
    // ft_printf("ft_printf: He %%  l l o \n");
    // printf("printf: He l %s l l o \n", "Hello");
    // ft_printf("ft_printf: He %s l l o \n", NULL);
    // printf("printf: He %i l l o \n", 8);
    // ft_printf("ft_printf: He %i l l o \n", 8);
    a = printf("printf: He %i l l o \n", 9);
    b = ft_printf("ft_printf: He %i l l o \n", 9);
    printf("%i %i", a, b);
    // printf("%s", NULL);
}