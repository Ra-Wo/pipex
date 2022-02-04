/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:07:17 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/02 19:11:22 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_input_is_path(char *cmd)
{
	int	x;

	x = -1;
	while (cmd[++x])
		if (cmd[x] == '/')
			return (1);
	return (0);
}

void	check_cmd_is_with_path(t_vars *vars)
{
	int	x;

	x = 0;
	if (check_input_is_path(vars->cmd1_and_params[0]))
		cut_and_save_path1(vars);
	if (check_input_is_path(vars->cmd2_and_params[0]))
		cut_and_save_path2(vars);
}
