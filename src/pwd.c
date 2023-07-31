/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:15 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:10:17 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_pwd(void)
{
	int		j;
	char	*pwd;

	j = 0;
	j = find_path_env(g_shell_h->envp, "PWD");
	pwd = ft_strchr(g_shell_h->envp[j], '=');
	pwd++;
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
