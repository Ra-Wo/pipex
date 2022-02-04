/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:29:19 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/03 18:50:30 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_exit(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->paths[i])
		free(vars->paths[i++]);
	free(vars->paths);
	i = -1;
	while (vars->cmd1_and_params[++i])
		free(vars->cmd1_and_params[i]);
	free(vars->cmd1_and_params);
	exit(1);
}

void	get_args(t_vars *vars, char **argv)
{
	int	start;

	start = 1;
	vars->infile = argv[start++];
	vars->cmd1_and_params = ft_split(argv[start++], ' ');
	if (!vars->cmd1_and_params)
	{
		start = 0;
		while (vars->paths[start])
			free(vars->paths[start++]);
		free(vars->paths);
		exit(1);
	}
	vars->cmd2_and_params = ft_split(argv[start++], ' ');
	if (!vars->cmd2_and_params)
		free_exit(vars);
	vars->outfine = argv[start];
}
