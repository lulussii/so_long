/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:18:48 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/31 08:24:18 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_printnbr_base(long int nb, char *base, int base_size)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += (int)write(1, "-", 1);
		nb = -nb;
	}
	if (nb > base_size - 1)
	{
		len += (int)ft_printnbr_base(nb / base_size, base, base_size);
	}
	len += (int)ft_printchar(base[nb % base_size]);
	return (len);
}

int	ft_printnbr_p(long int nb, char *base, long int base_size)
{
	long int	len;

	len = 0;
	if (nb == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += ft_printstr("0x");
	if (nb < 0)
	{
		len += (int)write(1, "-", 1);
		nb = -nb;
	}
	if (nb > base_size - 1)
	{
		len += (int)ft_printnbr_base(nb / base_size, base, base_size);
	}
	len += (int)ft_printchar(base[nb % base_size]);
	return (len);
}
