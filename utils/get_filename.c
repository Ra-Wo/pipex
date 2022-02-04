/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:29:25 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/03 14:04:56 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_filename(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_pathjoin(paths[i], cmd);
		if (access(path, F_OK) != -1)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
