/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:28:14 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/04 12:02:21 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	no_path_as_input(t_vars *vars)
{
	if (execve(get_filename(vars->paths, vars->cmd2_and_params[0]),
			vars->cmd2_and_params, vars->env) == -1)
	{
		perror("ERROR");
		exit(1);
	}
	exit(0);
}

static void	with_path_as_input(t_vars *vars)
{
	if (execve(vars->path_cmd2, vars->cmd2_and_params, vars->env) == -1)
	{
		perror("ERROR");
		exit(1);
	}
	exit(0);
}

void	process2(t_vars *vars)
{
	int	fd;

	close(vars->fd[1]);
	if (dup2(vars->fd[0], 0) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	close(vars->fd[0]);
	fd = open(vars->outfine, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("ERROR");
		exit(1);
	}
	if (dup2(fd, 1) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	if (vars->path_cmd2 == NULL)
		no_path_as_input(vars);
	else
		with_path_as_input(vars);
}
