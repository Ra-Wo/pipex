/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:27:41 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/04 12:13:16 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define BOOLEAN int

typedef struct vars {
	char	**paths;
	char	*infile;
	char	*outfine;
	char	**cmd1_and_params;
	char	*path_cmd1;
	char	**cmd2_and_params;
	char	*path_cmd2;
	int		fd[2];
	char	**env;
	BOOLEAN	exit_success;
}	t_vars;

void			get_paths(t_vars *vars, char **env);
char			**ft_split(char const *s, char c);
void			get_args(t_vars *vars, char **argv);
char			*get_filename(char **paths, char *cmd);
unsigned int	ft_strlen(const char *str);
char			*ft_pathjoin(char const *s1, char const *s2);
void			process(char **paths, char **cmd_and_params, t_vars *vars);
void			process2(t_vars *vars);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_then_exit(t_vars *vars, char *error);
char			*get_filedata(t_vars *vars);
void			check_cmd_is_with_path(t_vars *vars);

void			cut_and_save_path1(t_vars *vars);
void			cut_and_save_path2(t_vars *vars);

void			check_cmds_is_valid(char **argv);
int				ft_isalpha(int character);

#endif