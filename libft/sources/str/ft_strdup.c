/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:09:20 by ppetitea          #+#    #+#             */
/*   Updated: 2019/09/30 12:12:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/str.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = malloc(sizeof(char) * ft_strlen((char*)s1) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}