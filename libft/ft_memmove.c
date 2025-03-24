/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:12:09 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/22 15:37:19 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;

	if ((!dest && !src) && n > 0)
		return (NULL);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (tmp_dest > tmp_src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (n--)
		{
			*tmp_dest = *tmp_src;
			tmp_dest++;
			tmp_src++;
		}
	}
	return (dest);
}
