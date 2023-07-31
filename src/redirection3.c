/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:31 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:10:33 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	redirection_loop(t_pipe_group **tmp, t_token **tok,
					int *first, int *count_words)
{
	while (*tok)
	{
		if ((*tok)->type == APPEND || (*tok)->type == HEREDOC
			|| (*tok)->type == GREATER_THAN || (*tok)->type == LESS_THAN)
		{
			create_red(tok, tmp);
			if ((g_shell_h->pipes) == NULL)
				return (1);
		}
		else if ((*tok)->type == SINGLE_QUOTES
			|| (*tok)->type == DOUBLE_QUOTES || (*tok)->type == WORD)
		{
			if (quote_if(tmp, tok, first, count_words))
				continue ;
		}
		else if ((*tok)->type == PIPE)
		{
			if (pipe_if(tmp, tok, first, count_words))
				return (throw_error(SYNTAX_ERROR));
		}
		else
			*tok = (*tok)->next;
	}
	return (0);
}

t_pipe_group	*redirection(t_token **token)
{
	t_pipe_group	*tmp;
	t_token			*token_tmp;
	int				first;
	int				count_words;

	g_shell_h->pipes = init_pipe(0);
	tmp = g_shell_h->pipes;
	token_tmp = *token;
	first = 0;
	count_words = 0;
	if (redirection_loop(&tmp, &token_tmp, &first, &count_words))
		return (NULL);
	if (!first)
	{
		throw_error("minishell: syntax error near unexpected token\n");
		return (NULL);
	}
	tmp->argv[count_words] = NULL;
	return ((g_shell_h->pipes));
}
