/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:40 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:10:43 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	b_unset(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = find_path_env(g_shell_h->envp, args[i]);
		if (j != -1 && g_shell_h->envp[j])
		{
			free((g_shell_h->envp[j]));
			g_shell_h->envp[j] = NULL;
		}
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
