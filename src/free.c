/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:09:46 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:09:48 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	free_t_token(t_token **token)
{
	t_token	*tmp;
	t_token	*next;

	if (!(*token))
		return ;
	tmp = *token;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->info);
		free(tmp);
		tmp = next;
	}
	*token = NULL;
}

void	free_t_pipe(t_pipe_group **token)
{
	t_pipe_group	*tmp;
	t_pipe_group	*next;

	if (!(*token))
		return ;
	tmp = *token;
	while (tmp)
	{
		next = tmp->next;
		free_argv(tmp->argv);
		if (tmp->heredoc)
			unlink(tmp->heredoc);
		free(tmp->heredoc);
		free(tmp);
		tmp = next;
	}
	*token = NULL;
}

void	free_shell_h(void)
{
	int	i;

	i = 0;
	free_t_pipe(&(g_shell_h->pipes));
	free_t_token(&(g_shell_h->head));
	while (i < g_shell_h->current_env)
	{
		free(g_shell_h->envp[i]);
		i++;
	}
	free(g_shell_h->envp);
	free(g_shell_h);
	clear_history();
}

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	free_readed_and_splited(char *readed, char **splited)
{
	free_splited(splited);
	free(readed);
}
