/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_cpy_paste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:51:23 by malaine           #+#    #+#             */
/*   Updated: 2017/02/20 17:40:28 by malaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"
#include "shell.h"

void		ft_cut(t_line *l)
{
	do_term("cd");
	ft_strdel(&l->strcpy);
	l->strcpy = ft_strsub(l->str.data, l->cursor, l->str.size - l->cursor);
	if (l->strcpy == NULL)
		return ;
	fta_popback(&l->str, l->str.size - l->cursor);
}

void		ft_delete(t_line *l)
{
	l->sauv_cursor = l->cursor - 1;
	fta_popindex(&l->str, l->cursor - 1, 1);
	ft_left(l);
    do_term("cd");
	print(l);
}

void		ft_backspace(t_line *l)
{
	l->sauv_cursor = l->cursor;
	fta_popindex(&l->str, l->cursor, 1);
	print(l);
}

void		ft_paste(t_line *l)
{
	if (l->strcpy != NULL)
	{
		STR_INSERT_CS(&l->str, l->strcpy, ft_strlen(l->strcpy), l->cursor);
		l->sauv_cursor = l->cursor + ft_strlen(l->strcpy);
		print(l);
	}
}
