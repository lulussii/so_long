/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:43 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/03 09:40:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sort_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printnbr_p(va_arg(args, long int), "0123456789abcdef", 16);
	else if ((format == 'd') || (format == 'i'))
		len += ft_printnbr_base(va_arg(args, int), "0123456789", 10);
	else if (format == 'u')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789", 10);
	else if (format == 'x')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				16);
	else if (format == 'X')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				16);
	else if (format == '%')
		len += write(1, "%", 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			len += sort_format(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
