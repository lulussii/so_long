/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:12:33 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/22 09:28:56 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb >= INT_MAX / size)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (0);
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
