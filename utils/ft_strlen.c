/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:29:10 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/13 10:29:11 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	num;

	num = 0;
	while (str[num] != '\0')
		num++;
	return (num);
}
