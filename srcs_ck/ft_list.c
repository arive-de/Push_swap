/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:19:13 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 18:03:09 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		lst_print(t_list_ck *lst_a, t_list_ck *lst_b)
{
	int i;

	i = 0;
	sleep(1);
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	while (lst_a || lst_b)
	{
		if (i++ == 0)
			ft_putstr("\n     a            b\n   -----        -----\n");
		ft_putstr("     ");
		if (lst_a)
			ft_putnbr(lst_a->nb);
		ft_putstr("            ");
		if (lst_b)
			ft_putnbr(lst_b->nb);
		ft_putstr("\n");
		if (lst_a)
			lst_a = lst_a->next;
		if (lst_b)
			lst_b = lst_b->next;
	}
}

t_list_ck	*create_maillon_ck(int nb)
{
	t_list_ck *maillon;

	maillon = (t_list_ck*)ft_memalloc(sizeof(t_list_ck));
	if (!maillon)
		return (NULL);
	maillon->nb = nb;
	maillon->next = NULL;
	return (maillon);
}

void		add_maillon_end(t_list_ck **begin_list, t_list_ck *data)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp = *begin_list;
	tmp2 = NULL;
	if (!(*begin_list))
		*begin_list = data;
	else
	{
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			tmp2->next = data;
		else
		{
			tmp2->next = data;
			data->next = tmp;
		}
	}
}

t_list_ck	*maillon_del(t_list_ck *lst)
{
	t_list_ck *tmp;

	if (lst)
	{
		tmp = lst->next;
		free(lst);
		return (tmp);
	}
	else
		return (NULL);
}

void		add_maillon_beg(t_list_ck **begin_list, t_list_ck *data)
{
	t_list_ck *tmp;

	if (!(*begin_list))
		*begin_list = data;
	else
	{
		tmp = data;
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
}
