/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:43:25 by nduijf        #+#    #+#                 */
/*   Updated: 2022/02/03 14:42:03 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread(t_info *info)
{
	int			i;
	t_member	*member;

	member = info->member;
	i = 0;
	if (pthread_create(&info->monitor_thread, NULL, monitor, info) != 0)
		return (0);
	while (i < info->persons)
	{
		if (pthread_create(&member[i].thread, NULL, cycle, &member[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	join_thread(t_info *info)
{
	t_member	*member;
	int			i;

	member = info->member;
	i = 0;
	while (i < info->persons)
	{
		if (pthread_join(info->member[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(info->monitor_thread, NULL) != 0)
		return (0);
	return (1);
}

void	*cycle(void	*void_member)
{
	t_member	*member;
	t_info		*info;

	member = (t_member *)void_member;
	info = member->info;
	member->last_eat = get_time();
	info->time_start = get_time();
	if (member->id % 2 == 0)
		usleep(1500);
	while (!info->dieded && !info->all_eat)
	{
		philo_eat(member);
		if (info->all_eat == 1)
			break ;
		death_clock(member);
		philo_sleep(member);
		death_clock(member);
		philo_think(member);
		death_clock(member);
	}
	return (NULL);
}

int	death_clock(t_member *member)
{
	t_info	*info;

	info = member->info;
	if (elapsed_time(member->last_eat) >= info->time_to_die && !info->dieded)
	{
		info->dieded = 1;
		usleep(1000);
		set_timestamp(member->info, member->id, "died");
		return (1);
	}
	return (0);
}
