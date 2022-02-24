/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:25:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/02/14 10:47:22 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static char	*ft_clean_command(char *command)
{
	int	c;

	c = 0;
	while (command[c] && ft_isalpha(command[c]))
		c++;
	return (ft_substr(command, 0,c));
}

static void	ft_search_command(t_data *data, char *command)
{
	//char	**paths;
	char	*temp;
	char	**parameter;
	int		c;

	c = 0;
	write(2, "search\n", 7);
	while (data->path[c])
	{
		temp = ft_strjoin(data->path[c], "/");
		temp = ft_strjoin(temp, ft_clean_command(command));
		if (access(temp, X_OK) == 0)
		{
			//ft_putstr(temp);
			parameter = ft_split(command, ' ');
			//ft_putstr(parameter[0]);
			execve(temp, parameter, data->env);
			exit(0);
		}
		c++;
	}
	write(2, "command not found\n", 18);
	exit (0);
}

void	ft_read_pipe(int *pipe)
{
	char	str[999];

	read(pipe[0], str, 2);
	write(2, str, ft_strlen(str));
}

void	ft_recursive_child(t_data *data, char **command, int command_line, int *pipe1)
{
	int	pid;
	int	status;
	int	pipe2[2];
	int	w;

	pipe(pipe2);
	pid = fork ();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		close(pipe1[1]);
		close(pipe2[0]);
		if (ft_cases(command[command_line], data))
		{
			write(2, "cases\n", 6);
			exit (0);
		}
		write(2, "grandchild\n", 11);
		if (!data->input_pipe)
			dup2(pipe1[0], STDIN_FILENO);
		ft_putstr(command[command_line + 1]);
		if (command[command_line + 1] != NULL)
			dup2(pipe2[1], STDOUT_FILENO);
		data->input_pipe = 0;
		ft_search_command(data, command[command_line]);
	}
	else
	{
		w = waitpid(pid, &status, 0);
		write(2, "child\n", 6);
		if (w == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (command[command_line] != NULL)
		{
			/*close(pipes[1]);
			close(pipes[0]);*/
			data->input_pipe = 0;
			close(pipe1[1]);
			close(pipe1[0]);
			if(command[command_line] != NULL)
				ft_recursive_child(data, command, command_line + 1, pipe2);
		}
	}
}

void	ft_create_child(t_data *data, char **command)
{
	//int	pid;
	//int	status;
	int	pipe2[2];

	data->input_pipe = 1;
	pipe(pipe2);
	ft_recursive_child(data, command, 0, pipe2);/*
	printf("start\n");
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		pipe(pipe2);
		printf("first child\n");
		ft_recursive_child(data, command, 0, pipe2);
		exit (0);
	}
	else
	{
		waitpid(pid, &status, 0);
		printf("Father\n");
	}*/
}

void	ft_clean_command2(t_data *data, char **command)
{
	int	c;

	c = 0;
	(void)data;
	while(command[c] != NULL)
	{
		command[c] = ft_index(&command[c]);
		c++;
	}
}
