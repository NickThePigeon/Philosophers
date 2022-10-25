/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:46:47 by nduijf        #+#    #+#                 */
/*   Updated: 2021/12/15 18:47:06 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->mutex_print, NULL) != 0)
		return (0);
	while (i < info->persons)
	{
		if (pthread_mutex_init(&info->mutex_fork[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	destroy_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->persons)
	{
		if (pthread_mutex_destroy(&info->mutex_fork[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&info->mutex_print) != 0)
		return (0);
	return (1);
}
