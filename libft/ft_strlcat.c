/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:06:51 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/27 17:06:56 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = 0;
	if (size <= len_d)
		return (ft_strlen(src) + size);
	while (src[len_s] && len_d + len_s < size - 1)
	{
		dst[len_d + len_s] = src[len_s];
		len_s++;
	}
	dst[len_d + len_s] = '\0';
	return (len_d + ft_strlen(src));
}
