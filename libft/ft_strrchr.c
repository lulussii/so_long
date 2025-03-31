/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:28:57 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/31 08:47:19 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp_c;

	if (!s)
		return (NULL);
	tmp_c = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == tmp_c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
