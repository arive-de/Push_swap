/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:51:12 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 18:02:56 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

	i = 0;
	tmp = env->lst_a;
	while (env->lst_a)
	{
		tmp = env->lst_a;
		env->lst_a = env->lst_a->next;
		free(tmp);
	}
	while (env->tab[i].move)
	{
		ft_strdel(&env->tab[i].move);
		i++;
	}
	free(env->line);
	free(env);
}

int		visu(t_ps *env, int i)
{
	env->visu = 1;
	i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int			i;
	int			a;
	t_ps		*env;

	i = 0;
	env = (t_ps*)ft_memalloc(sizeof(t_ps));
	env->lst_a = NULL;
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v' && argv[2] != '\0')
			i = visu(env, i);
		while (argv[++i])
		{
			if (!my_atoi(argv[i], &a))
			{
				ft_putendl_fd("Error", 2);
				free(env);
				return (0);
			}
			else if (is_dup(env, a))
				add_maillon_end(&env->lst_a, create_maillon_ck(a));
		}
		solver(env);
	}
	return (0);
}
