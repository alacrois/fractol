/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacrois <alacrois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 18:31:18 by alacrois          #+#    #+#             */
/*   Updated: 2014/12/03 19:36:04 by alacrois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	i2;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			i2 = 0;
			while ((s1[i + i2] == s2[i2]) && (i2 < len))
				i2++;
			if (i2 == len)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
