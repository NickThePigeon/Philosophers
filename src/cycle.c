/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cycle.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:45:22 by nduijf        #+#    #+#                 */
/*   Updated: 2022/02/03 14:41:13 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_member *mem)
{
	t_info	*i;

	i = mem->info;
	pthread_mutex_lock(&(i->mutex_fork[mem->l_fork]));
	pthread_mutex_lock(&(i->mutex_fork[mem->r_fork]));
	if (!i->dieded && !i->all_eat)
	{
		set_timestamp(i, mem->id, "has taken a fork");
		set_timestamp(i, mem->id, "has taken a fork");
		set_timestamp(i, mem->id, "is eating");
		if ((elapsed_time(mem->last_eat) + i->time_to_eat) > i->time_to_die)
		{
			smart_sleep((mem->last_eat - get_time()) + i->time_to_die, mem);
			death_clock(mem);
		}
		else
		{
			smart_sleep(i->time_to_eat, mem);
			mem->last_eat = get_time();
			mem->eat++;
		}
	}
	pthread_mutex_unlock(&(i->mutex_fork[mem->l_fork]));
	pthread_mutex_unlock(&(i->mutex_fork[mem->r_fork]));
}

void	philo_sleep(t_member *mem)
{
	t_info	*i;

	i = mem->info;
	if (!i->dieded && !i->all_eat)
	{
		set_timestamp(i, mem->id, "is sleeping");
		if (elapsed_time(mem->last_eat) + i->time_to_sleep > i->time_to_die)
		{
			smart_sleep((mem->last_eat - get_time()) + i->time_to_die, mem);
			death_clock(mem);
		}
		else
			smart_sleep(i->time_to_sleep, mem);
	}
}

void	philo_think(t_member *member)
{
	t_info	*i;

	i = member->info;
	if (!i->dieded && !i->all_eat)
		set_timestamp(member->info, member->id, "is thinking");
}

void	one_philo(t_info *info)
{
	info->time_start = get_time();
	set_timestamp(info, 0, "has taken a fork");
	smart_sleep_one(info->time_to_die);
	set_timestamp(info, 0, "died");
}
