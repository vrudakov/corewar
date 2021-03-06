/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:58:57 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 16:59:03 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int				lst_size(t_list *list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = list;
	if (temp == NULL)
		return (0);
	while (temp)
	{
		if (((t_process*)temp->content)->id != 2000000000)
		{
			i++;
		}
		temp = temp->next;
	}
	return (i);
}

int				get_opcode_by_name(char *name)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!strcmp(name, g_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	big_to_little(unsigned int value)
{
	value = ((value >> 24) & 0xff) |
			((value << 8) & 0xff0000) |
			((value >> 8) & 0xff00) |
			((value << 24) & 0xff000000);
	return (value);
}

int				get_register(int process_counter, int skip)
{
	process_counter += skip;
	if (process_counter > MEM_SIZE - 1)
	{
		return (g_env->global_field[process_counter % MEM_SIZE]);
	}
	return (g_env->global_field[process_counter]);
}
