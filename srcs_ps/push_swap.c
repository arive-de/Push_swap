/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:14:54 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/05 14:37:03 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_dup(t_ps *env, int current)
{
	t_list_ck	*tmp;

	if (env->lst_a)
	{
		tmp = env->lst_a;
		while (tmp)
		{
			if (current == tmp->nb)
			{
				ft_putendl_fd("Error", 2);
				freedom(env);
				exit(0);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}

void	freedom(t_ps *env)
{
	int			i;
	t_list_ck	*tmp;
	t_list_ck	*tmp2;

	i = 0;
	while (env->lst_a)
	{
		tmp = env->lst_a;
		env->lst_a = env->lst_a->next;
		free(tmp);
	}
	while (env->lst_b)
	{
		tmp2 = env->lst_b;
		env->lst_b = env->lst_b->next;
		free(tmp2);
	}
	while (env->tab[i].move)
	{
		ft_strdel(&env->tab[i].move);
		i++;
	}
	free(env->line);
	free(env);
}

void	init(t_ps *env)
{
	init_tab(env);
	rank(env);
	if (is_sort(env->lst_a))
	{
		freedom(env);
		exit(1);
	}
	if (lst_count(env->lst_a) < 4)
		brut_small(env);
	else if (lst_count(env->lst_a) == 4)
		brut_4(env);
	else if (lst_count(env->lst_a) == 5)
		brut_5(env);
	else
		env = solver(env);
}

int		main(int argc, char **argv)
{
	int		i;
	int		a;
	t_ps	*env;

	i = 0;
	env = (t_ps*)ft_memalloc(sizeof(t_ps));
	env->lst_a = NULL;
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (!my_atoi(argv[i], &a))
			{
				ft_putendl_fd("Error", 2);
				free(env);
				return (0);
			}
			else if (is_dup(env, a))
				add_maillon_end(&env->lst_a, create_maillon_ck(a, 0, 0));
		}
		init(env);
	}
	freedom(env);
	return (0);
}
