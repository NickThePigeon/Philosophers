/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 14:13:52 by nicky         #+#    #+#                 */
/*   Updated: 2022/02/02 13:45:00 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

/* member struct */

typedef struct s_info	t_info;

typedef struct s_member
{
	int			id;
	int			eat;
	int			died;
	int			l_fork;
	int			r_fork;
	long long	last_eat;
	pthread_t	thread;
	t_info		*info;
}				t_member;

/* parent struct */

typedef struct s_info
{
	int					persons;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					times_of_eating;
	int					all_eat;
	int					dieded;
	long long			time_start;
	pthread_mutex_t		*mutex_fork;
	pthread_mutex_t		mutex_print;
	pthread_t			monitor_thread;
	t_member			*member;
}				t_info;

/* initialization */

int			get_args(int argc, char **argv, t_info *info);
int			init(t_info *info);
void		init_philosophers(t_info *info);

/* thread & mutex functions */

void		*monitor(void *void_info);
void		*cycle(void	*void_member);
int			create_thread(t_info *info);
int			join_thread(t_info *info);
int			init_mutex(t_info *info);
int			destroy_mutex(t_info *info);

/* philo state func */

void		philo_eat(t_member *mem);
void		philo_sleep(t_member *mem);
void		philo_think(t_member *member);
void		one_philo(t_info *info);

/* time functions */

int			death_clock(t_member *member);
long long	get_time(void);
void		set_timestamp(t_info *info, int philo_id, char *action);
long long	elapsed_time(long long time);
void		smart_sleep(long long time, t_member *member);
void		smart_sleep_one(long long time);

/* error functions */

int			error_msg(int error);

/* utils functions */

int			ft_atoi(const char *str);
void		ft_putnbr_fd(int n, int fd);
int			loop_ft_is(int (*func)(), int i, char *str);
int			ft_isspace(int c);
int			ft_isdigit(int arg);
size_t		ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd);
void		putnbr_ull(long long nbr);

#endif