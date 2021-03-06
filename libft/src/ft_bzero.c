/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:05:01 by omotyliu          #+#    #+#             */
/*   Updated: 2016/11/25 17:05:02 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*ch1;

	ch1 = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		ch1[i] = '\0';
		i++;
	}
}
