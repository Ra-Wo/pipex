/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:27:35 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/04 12:11:43 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_vars *vars, char **env, int argc, char **argv)
{
	vars->exit_success = FALSE;
	if (argc <= 4)
	{
		write(2, "ERROR: missing parameters\n", 26);
		exit(1);
	}
	check_cmds_is_valid(argv);
	if (argc != 5)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	vars->path_cmd1 = NULL;
	vars->path_cmd2 = NULL;
	vars->env = env;
	get_paths(vars, env);
	get_args(vars, argv);
	check_cmd_is_with_path(vars);
}

static void	exit_suc(t_vars *vars)
{
	vars->exit_success = FALSE;
	exit(0);
}

void	free_then_exit(t_vars *vars, char *error)
{
	int	x;

	x = 0;
	if (error)
		write(2, &error, ft_strlen(error));
	while (vars->paths[x])
		free(vars->paths[x++]);
	free(vars->paths);
	x = 0;
	while (vars->cmd1_and_params[x])
		free(vars->cmd1_and_params[x++]);
	free(vars->cmd1_and_params);
	x = 0;
	while (vars->cmd2_and_params[x])
		free(vars->cmd2_and_params[x++]);
	free(vars->cmd2_and_params);
	if (vars->path_cmd1 != NULL)
		free(vars->path_cmd1);
	if (vars->path_cmd2 != NULL)
		free(vars->path_cmd2);
	if (vars->exit_success == TRUE)
		exit_suc(vars);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	t_vars	vars;
	int		ret_pip;
	int		pid;
	int		status;

	if (env[0] == NULL)
		return (write(2, "Error\n", 6), 1);
	init(&vars, env, argc, argv);
	ret_pip = pipe(vars.fd);
	if (ret_pip == -1)
		free_then_exit(&vars, "ERROR: pipe");
	pid = fork();
	if (pid == -1)
		free_then_exit(&vars, "ERROR: fork");
	else if (pid == 0)
		process(vars.paths, vars.cmd1_and_params, &vars);
	else
	{
		wait(&status);
		if (status == 0)
			vars.exit_success = TRUE;
		free_then_exit(&vars, NULL);
	}
	return (0);
}
