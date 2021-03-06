/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:42:01 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:42:04 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

unsigned int		op(t_process *proc, unsigned int first, unsigned int second)
{
	unsigned int	res;

	if (g_env->global_field[proc->counter] == 6)
		res = first & second;
	else if (g_env->global_field[proc->counter] == 7)
		res = first | second;
	else
		res = first ^ second;
	return (res);
}

int					validate_and(int *mass, t_process *process)
{
	int	i;

	i = 0;
	if ((mass[0] == T_REG || mass[0] == T_DIR || mass[0] == T_IND) &&
		(mass[1] == T_REG || mass[1] == T_DIR || mass[1] == T_IND) &&
		(mass[2] == T_REG))
		i = 1;
	type_to_size(mass, 4);
	if (!i)
	{
		invalid_coding_byte(mass, process, 3);
	}
	return (i);
}

unsigned int		get_arg_and(int *params, int num, t_process *process)
{
	unsigned int	arg;

	if (num == 0)
		arg = bytes_to_int(process->counter + 2, params[0]);
	else
		arg = bytes_to_int(process->counter + 2 + params[0], params[1]);
	if (params[num] == IND_SIZE || params[num] == 1)
		arg = (params[num] == IND_SIZE) ? bytes_to_int(arg, DIR_SIZE) :
	process->registers[arg];
	return (arg);
}

void				and(t_process *process)
{
	char			coding_byte;
	unsigned int	first;
	unsigned int	second;
	int				params[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(params, coding_byte);
	if (!validate_and(params, process))
		return ;
	first = get_arg_and(params, 0, process);
	second = get_arg_and(params, 1, process);
	coding_byte = g_env->global_field[process->counter + 2 + params[0] +
		params[1]];
	if (validate_reqistry(coding_byte))
	{
		if ((int)coding_byte != 1)
			process->registers[(int)coding_byte] = op(process, first, second);
		process->carry = (op(process, first, second) == 0) ? 1 : 0;
	}
	process->counter += params[0] + params[1] + params[2] + 2;
}
