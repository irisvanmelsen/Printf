/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:57:53 by iris              #+#    #+#             */
/*   Updated: 2022/11/08 17:27:59 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

// int printchar(char c)
// {
//     write(1, &c, 1);
//     return (1);
// }

// int printstr(char *str)
// {
//     int i;
//     int counter;

//     i = 0;
//     counter = 0;
//     if (str == NULL)
//         return (write(1, "(null)", 6));
//     while (str[i] != '\0')
//     {
//         counter += printchar(str[i]);
//         i++;
//     }
//     return (counter);
// }

// int	putnbr(int nb)
// {
//     int     counter;

//     counter = 0;
// 	if (nb == -2147483648)
//         return (write(1, "-2147483648", 11));
//     if (nb < 0)
// 	{
//         nb = nb * -1;
// 		counter += printchar('-');
// 	}
// 	if (nb < 10)
//     {
// 		counter += printchar(nb + '0');
// 	} 
//     if (nb >= 10)
//     {
// 		counter += putnbr(nb / 10);
// 		counter += putnbr(nb % 10);
//     }
//     return (counter);
// }

// int	putun(unsigned int nb)
// {
//     unsigned int     counter;

//     counter = 0;
// 	if (nb < 10)
//     {
// 		counter += printchar(nb + '0');
// 	} 
//     if (nb >= 10)
//     {
// 		counter += putnbr(nb / 10);
// 		counter += putnbr(nb % 10);
//     }
//     return (counter);
// }

// int printhexalow(unsigned long nb, char const *str)
// {
//     unsigned int     counter;

//     counter = 0;
// 	if (nb < 16)
//     {
// 		counter += printchar(str[nb]);
// 	} 
//     if (nb >= 16)
//     {
// 		counter += printhexalow(nb / 16, "0123456789abcdef");
// 		counter += printhexalow(nb % 16, "0123456789abcdef");
//     }
//     return (counter);
// }

// int printhexaup(unsigned long nb, char const *str)
// {
//     unsigned int     counter;

//     counter = 0;
// 	if (nb < 16)
//     {
// 		counter += printchar(str[nb]);
// 	} 
//     if (nb >= 16)
//     {
// 		counter += printhexaup(nb / 16, "0123456789ABCDEF");
// 		counter += printhexaup(nb % 16, "0123456789ABCDEF");
//     }
//     return (counter);
// }

int	formatlist(va_list args, char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = printchar(va_arg(args, int));
	else if (format == '%')
		result = printchar('%');
	else if (format == 's')
		result = printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		result = putnbr(va_arg(args, int));
	else if (format == 'u')
		result = putun(va_arg(args, unsigned int));
	else if (format == 'x')
		result = printhexalow(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		result = printhexaup(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		write(1, "0x", 2);
		result = printhexalow(va_arg(args, unsigned long), "0123456789abcdef");
		result += 2;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	args;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result += formatlist(args, format[i]);
		}
		else if (format [i] != '%')
			result += printchar(format[i]);
		i++;
	}
	va_end(args);
	return (result);
}

// int main(void)
// {
//     // int a;
//     // int b;

// //     // printf("printf: He %c l %c lo\n", '9', '8');
// //     // ft_printf("ft_printf: He %c l %c lo\n", '9', '8');
// //     // printf("printf: He l %% w l l o \n");
// //     // ft_printf("ft_printf: He %%  l l o \n");
// //     // printf("printf: He l %s l l o \n", "Hello");
// //     // ft_printf("ft_printf: He %s l l o \n", NULL);
// //     // printf("printf: He %i l l o \n", 8);
// //     // ft_printf("ft_printf: He %i l l o \n", 8);
// //     //a = printf("ft: He %li l l o \n", -2147483648);
// //     //b = ft_printf("lb: He %i l l o \n", -2147483648);
// //     //a = printf("ft: He %u l l o \n", 0);
// //     //b = ft_printf("lb: He %u l l o \n", 0);
//     //  a = printf("%x", 123);
//     //  b = ft_printf("%x\n", 123);
//     printf("%d", ft_printf("%%%\0fjsfjklsdfjls"));
// //     // printf("%s", NULL);
// }