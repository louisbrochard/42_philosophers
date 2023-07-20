/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:16:33 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/20 10:16:35 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cur;

	if (n == 0)
		return (0);
	cur = 0;
	while (s1[cur] && s2[cur])
	{
		if (s1[cur] != s2[cur] || cur >= n - 1)
			return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
		cur++;
	}
	return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
}
