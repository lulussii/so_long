/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:28:27 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/22 15:36:40 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	temp;

	i = 0;
	sign = 1;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || ((str[i] == ' ') && str[i]))
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		else if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		temp = temp * 10 + str[i] - '0';
		i++;
	}
	return (temp * sign);
}
