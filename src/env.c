/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:08:50 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:08:53 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_env(void)
{
	int	i;

	i = 0;
	while (i < g_shell_h->current_env)
	{
		if (g_shell_h->envp[i] == NULL)
		{
			i++;
			continue ;
		}
		printf("%s\n", g_shell_h->envp[i]);
		i++;
	}
	return (0);
}
