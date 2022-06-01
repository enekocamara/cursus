/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:09:01 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/09 12:12:01 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_forks
{
	int				fork;
	pthread_mutex_t	mutex;
}t_forks;

typedef struct s_data
{
	pthread_t		*threads;
	int				eat_times;
	t_forks			*forks;
	struct timeval	init_time;
	int				t_sleep;
	int				t_eat;
	int				t_die;
	int				total;
	int				death;
	int				eatboo;
	pthread_mutex_t	*m_death;
}t_data;

typedef struct s_philo
{
	int				total;
	t_forks			*forks;
	int				id;
	int				eat_times;
	struct timeval	time;
	t_data			*data;
	pthread_mutex_t	*mutex;
}t_philo;

int			ft_input(t_data *data, char *argv[]);
int			ft_data_create(t_data *data);
int			ft_create_thread(t_data *data);
void		*ft_process(void *philo);

/*------------TIME-------------*/

int			ft_im_dead(t_philo *philo);
int			ft_death(t_philo *philo);
int			ft_my_usleep(t_philo *philo, int time);
long int	ft_to_ml(struct timeval time);
long int	ft_time(t_philo *philo);

/*-----------INPUT-------------*/

void		ft_group1(t_philo *philo);
void		ft_group2(t_philo *philo);
void		ft_group3(t_philo *philo);
/*-----------ERROR-------------*/

int			ft_error(int a);

/*----------PROCESS------------*/
int			ft_fork_handler(t_philo *philo, int boo);
int			ft_think(t_philo *philo);
int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);

/*--------------AUX-------------*/

int			ft_check_input(char *argv[]);
int			ft_groups(int id, int total);

/*------------UTILS------------*/

int			ft_atoi_ph(const char *str);
int			ft_f_left(int id, int total);
void		ft_pass_data(t_data *data, t_philo *philo);
void		ft_free_data(t_data *data);

#endif