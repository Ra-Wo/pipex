/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save_cmd_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:31:16 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:02 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_cmd_size(char *cmd)
{
	int	i;
	int	c;

	c = 0;
	i = ft_strlen(cmd);
	while (cmd[i--] != '/')
		c++;
	return (c - 1);
}

void	cut_and_save_path1(t_vars *vars)
{
	int		i;
	int		size_path;
	int		size_cmd;
	char	*the_cmd;

	i = 0;
	size_cmd = get_cmd_size(vars->cmd1_and_params[0]);
	vars->path_cmd1 = vars->cmd1_and_params[0];
	size_path = (ft_strlen(vars->cmd1_and_params[0]) - size_cmd);
	the_cmd = malloc(sizeof(char) * (size_cmd + 1));
	if (!the_cmd)
		free_then_exit(vars, "malloc Error");
	while (vars->cmd1_and_params[0][size_path])
		the_cmd[i++] = vars->cmd1_and_params[0][size_path++];
	the_cmd[i] = '\0';
	vars->cmd1_and_params[0] = the_cmd;
}

void	cut_and_save_path2(t_vars *vars)
{
	int		i;
	int		size_path;
	int		size_cmd;
	char	*the_cmd;

	i = 0;
	size_cmd = get_cmd_size(vars->cmd2_and_params[0]);
	vars->path_cmd2 = vars->cmd2_and_params[0];
	size_path = (ft_strlen(vars->cmd2_and_params[0]) - size_cmd);
	the_cmd = malloc(sizeof(char) * (size_cmd + 1));
	if (!the_cmd)
		free_then_exit(vars, "malloc Error");
	while (vars->cmd2_and_params[0][size_path])
		the_cmd[i++] = vars->cmd2_and_params[0][size_path++];
	the_cmd[i] = '\0';
	vars->cmd2_and_params[0] = the_cmd;
}
