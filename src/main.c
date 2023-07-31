/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:10 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:10:12 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell	*g_shell_h = NULL;

void	count_last(t_pipe_group *pipes)
{
	g_shell_h->last = -1;
	while (pipes)
	{
		pipes = pipes->next;
		g_shell_h->last++;
	}
}

void	init_main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	signals();
	assign_env(envp);
	put_lvl();
}

void	ft_lexer(void)
{
	put_type_tok(&(g_shell_h->head));
	split_words(&(g_shell_h->head));
	expander(&(g_shell_h->head));
}

void	free_all(char *readed, char **splited)
{
	free_t_token(&(g_shell_h->head));
	free_t_pipe(&(g_shell_h->pipes));
	free(readed);
	free_splited(splited);
}

int	main(int argc, char **argv, char **envp)
{
	char	*readed;
	char	**splited;

	init_main(argc, argv, envp);
	while (1)
	{
		readed = readline("minishell > ");
		if (!readed)
			return (0);
		if (!(ft_strcmp(readed, "\0")))
		{
			free(readed);
			continue ;
		}
		splited = ft_split_minishell(readed);
		if (main_split(splited, readed) == 1)
			continue ;
		count_last(g_shell_h->pipes);
		executor(g_shell_h->pipes);
		free_all(readed, splited);
	}
	free_shell_h();
	return (0);
}
