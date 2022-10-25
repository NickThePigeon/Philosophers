/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 20:16:32 by nduijf        #+#    #+#                 */
/*   Updated: 2022/01/31 16:16:19 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * (long long)1000) + (current.tv_usec / 1000));
}

void	smart_sleep(long long time, t_member *member)
{
	long long	i;

	i = get_time();
	while (!(member->info->dieded))
	{
		if (elapsed_time(i) >= time)
			break ;
		usleep(50);
	}
}

void	smart_sleep_one(long long time)
{
	long long	i;

	i = get_time();
	while (1)
	{
		if (elapsed_time(i) >= time)
			break ;
		usleep(100);
	}
}

void	set_timestamp(t_info *info, int philo_id, char *action)
{
	pthread_mutex_lock(&info->mutex_print);
	putnbr_ull(get_time() - info->time_start);
	write(1, " ", 1);
	putnbr_ull(philo_id + 1);
	write(1, " ", 1);
	write(1, action, ft_strlen(action));
	write(1, "\n", 1);
	pthread_mutex_unlock(&info->mutex_print);
}

long long	elapsed_time(long long time)
{
	long long	now;

	now = get_time();
	return (now - time);
}
