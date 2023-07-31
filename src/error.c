/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:08:55 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:08:58 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	throw_error(char *error)
{
	ft_putstr_fd(error, 2);
	free_t_pipe(&(g_shell_h->pipes));
	free_t_token(&(g_shell_h->head));
	return (1);
}

void	throw_error_exec(char *error)
{
	ft_putstr_fd(error, 2);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
