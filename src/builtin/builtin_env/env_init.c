/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:28:20 by mseinic           #+#    #+#             */
/*   Updated: 2017/02/20 19:16:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	tab_size(char **tab)
{
	size_t	size;

	size = 0;
	while (tab != NULL && tab[size] != NULL)
		size++;
	return (size);
}

t_env_cell	env_cell_ret(char	*str)
{
	t_env_cell	cell[1];
	char		*ptr;

	ptr = ft_strchr(str, '=');
	if (ptr == NULL)
	{
		cell->key = ft_strdup(str);
		cell->value = NULL;
	}
	else
	{
		*ptr = '\0';
		ptr++;
		cell->key = ft_strdup(str);
		cell->value = ft_strdup(ptr);
	}
	return (*cell);
}

int		env_tab_init(t_env *env, char **environ)
{
	size_t		i;
	t_env_cell	cell;

	i = 0;
	while (environ[i] != NULL)
	{
		cell = env_cell_ret(environ[i]);
		fta_append(&env->tab, &cell, 1);
		i++;
	}
	return (0);
}

int		env_tab(t_env *env, char **environ)
{
	size_t	size;

	if ((size = tab_size(environ)) == 0)
		size = 2;
	size++;
	env->tab = NEW_ARRAY(t_env_cell);
	if (fta_reserve(&env->tab, size))
		return (1);
	env_tab_init(env, environ);
	return (0);
}

int		env_init(t_env *env, char	**environ)
{
	if (env == NULL)
		return (1);
	env_tab(env, environ);
	return (0);
}
