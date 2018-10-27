/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:21:35 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/21 19:27:32 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ss;

	ss = (char*)s;
	i = ft_strlen(ss) + 1;
	while (i--)
		if (ss[i] == c)
			return (i == 0) ? ss : &ss[i];
	return (NULL);
}
