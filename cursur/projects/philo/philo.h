/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:09:01 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/12 16:58:40 by ecamara          ###   ########.fr       */
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

struct	s_forks;
struct	s_time;
struct	s_philo;
struct	s_data;

typedef struct s_forks
{
	int				fork;
	pthread_mutex_t	mutex;
}t_forks;

typedef struct s_time
{
	struct timeval	time;
}t_time;

typedef struct s_death
{
	int				death;
	pthread_mutex_t	m_death;
}t_death;

typedef struct s_philo
{
	int				num_of_philos;
	int				philo_num;
	int				t_to_sleep;
	int				t_to_eat;
	int				t_to_die;
	t_time			*g_time;
	struct timeval	time;
	t_forks			**forks;
	t_death			*death;
}t_philo;

typedef struct s_data
{
	pthread_t		*hilos;
	t_philo			*philos;
	t_forks			*forks;
	int				t_to_sleep;
	int				t_to_eat;
	int				t_to_die;
	int				num_of_philos;
}t_data;

void	*ft_process(void *philo);
void	ft_create_forks(t_forks *forks, int num_philos);
int		ft_create_thread(t_data *data, int num_philos);
int		ft_data_create(t_data *data, int num_philos);
int		ft_input(t_data *data, char *argv[]);
void	ft_live_1(int num_of_philo, int num, int time, t_philo *philo);
int		ft_death(t_philo *philo);
int		ft_im_dead(t_philo *philo);
int		ft_my_usleep(t_philo *philo, int time, int time_to_die);
void	ft_rutine(t_philo *philo, int num_of_philo, int philo_num, int group);
int		ft_sleep(t_philo *philo, int philo_num, int t_to_sleep);
void	ft_fork_handler(t_philo *philo, t_forks *forks, int left_fork, int a);
int		ft_eat(t_philo *philo, int t_to_eat, int philo_num);
int		ft_think(t_philo *philo, int philo_num, int t_to_eat, int t_to_sleep);
int		ft_groups(int philo_num, int num_of_philo);
int		ft_f_left(int philo_num, int num_of_philo);
int		ft_diff(int t_to_eat, int t_to_sleep);
long int	ft_time(t_time *time);
void	*ft_process(void *philo);
int		ft_data_create(t_data *data, int num_philos);
int		ft_input(t_data *data, char *argv[]);
void	ft_pass_data(t_data *data, t_death *death, int i, t_time *time);
int		ft_create_thread(t_data *data, int num_philos);
int		ft_error(int a);
int		ft_to_ml(struct timeval time);

#endif