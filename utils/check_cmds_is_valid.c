/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:41:47 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/03 14:40:01 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_cmd_empty(char **argv, int sign, int i)
{
	while (argv[2][i])
	{
		if (ft_isalpha(argv[2][i]))
			sign = 0;
		i++;
	}
	if (sign == 1)
	{
		write(2, "Error: command not found\n", 25);
		exit(1);
	}
	i = 0;
	sign = 1;
	while (argv[3][i])
	{
		if (ft_isalpha(argv[3][i]))
			sign = 0;
		i++;
	}
	if (sign == 1)
	{
		write(2, "Error: command not found\n", 25);
		exit(1);
	}
}

void	check_cmds_is_valid(char **argv)
{
	int	sign;
	int	i;

	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		write(2, "Error: command not found\n", 25);
		exit(1);
	}
	i = 0;
	sign = 1;
	check_cmd_empty(argv, sign, i);
}
