/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:07:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/21 13:25:25 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int			i;
	long int	big_n;

	i = 0;
	big_n = n;
	if (big_n == 0)
		return (1);
	if (big_n < 0)
		i++;
	while (big_n != 0)
	{
		big_n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			size;
	long int	big_n;

	big_n = n;
	size = ft_length(n);
	if (n < 0)
		big_n *= -1;
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (0);
	result[size] = 0;
	if (big_n == 0)
		result[0] = '0';
	else
	{
		while (size--, big_n != 0)
		{
			result[size] = (big_n % 10) + '0';
			big_n /= 10;
		}
		if (n < 0)
			result[0] = '-';
	}
	return (result);
}
