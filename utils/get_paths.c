/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:29:31 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_is_path(char *str, char *to_find)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (to_find[x])
	{
		if (str[x] != to_find[x])
		{
			sign = 0;
			break ;
		}
		x++;
	}
	return (sign);
}

void	get_paths(t_vars *vars, char **env)
{
	int	x;

	x = -1;
	while (env[++x])
	{
		if (check_is_path(env[x], "PATH="))
		{
			vars->paths = ft_split((env[x] + 5), ':');
			break ;
		}
	}
}
