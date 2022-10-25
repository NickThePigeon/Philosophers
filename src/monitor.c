/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:49:59 by nduijf        #+#    #+#                 */
/*   Updated: 2022/02/02 13:44:55 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_all_eat(t_info *in)
{
	int	i;
	int	holder;

	i = 0;
	holder = 0;
	while (i < in->persons)
	{
		if (in->member[i].eat >= in->times_of_eating && in->times_of_eating > 0)
			holder++;
		i++;
	}
	if (holder == in->persons && in->times_of_eating > 0)
	{
		in->all_eat = 1;
		in->dieded = 1;
	}
}

void	*monitor(void *void_info)
{
	t_info	*info;
	int		i;

	info = (t_info *)void_info;
	i = 0;
	while (!info->dieded)
	{
		check_all_eat(info);
		if (i == info->persons - 1)
			i = 0;
		usleep(50);
		i++;
	}
	return (NULL);
}
