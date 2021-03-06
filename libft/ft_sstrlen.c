/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:37:14 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/09 17:37:44 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sstrlen(char **sstr)
{
	size_t i;

	i = 0;
	while (sstr[i])
		i++;
	return (i);
}
