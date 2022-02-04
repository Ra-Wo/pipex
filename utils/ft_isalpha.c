/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:15:21 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/03 14:10:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_isalpha(int character)
{
	if (character >= 'A' && character <= 'Z')
	{
		return (1);
	}
	else if ((character >= 'a') && (character <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
