/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:28:03 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/04 11:09:30 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	no_path_as_input(t_vars *vars, char **paths,
	char **cmd_and_params, int fd)
{
	close(vars->fd[0]);
	if (dup2(vars->fd[1], 1) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	close(vars->fd[1]);
	fd = open(vars->infile, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR: fd is not valid\n", 23);
		exit(1);
	}
	if (dup2(fd, 0) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	if (execve(get_filename(paths, cmd_and_params[0]),
			cmd_and_params, vars->env) == -1)
	{
		write(2, "ERROR: can't execute the first commend line\n", 44);
		exit(0);
	}
	return (0);
}

static int	with_path_as_input(t_vars *vars, char *path,
	char **cmd_and_params, int fd)
{
	close(vars->fd[0]);
	if (dup2(vars->fd[1], 1) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	close(vars->fd[1]);
	fd = open(vars->infile, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR: fd is not valid\n", 23);
		exit(1);
	}
	if (dup2(fd, 0) == -1)
	{
		write(2, "ERROR: dup2\n", 12);
		exit(1);
	}
	if (execve(path, cmd_and_params, vars->env) == -1)
	{
		write(2, "ERROR: can't execute the first commend line\n", 44);
		exit(0);
	}
	return (0);
}

void	process_part2(int pid, t_vars *vars, char **paths,
	char **cmd_and_params)
{
	int	fd;
	int	status;

	fd = -1;
	if (pid == -1)
	{
		write(2, "ERROR: fork\n", 12);
		exit(1);
	}
	else if (pid == 0)
	{
		wait(&status);
		if (status != 0)
			exit(1);
		process2(vars);
	}
	else
	{
		if (vars->path_cmd1 == NULL)
			no_path_as_input(vars, paths, cmd_and_params, fd);
		else
			with_path_as_input(vars, vars->path_cmd1, cmd_and_params, fd);
	}
}

void	process(char **paths, char **cmd_and_params, t_vars *vars)
{
	int	pid;

	if (access(vars->infile, R_OK) == -1)
	{
		perror("ERROR");
		exit(1);
	}
	pid = fork();
	process_part2(pid, vars, paths, cmd_and_params);
}
