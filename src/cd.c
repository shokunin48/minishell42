/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:07:56 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:07:59 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	change_dir(char *arg)
{
	char	*sub;
	char	*temp;
	char	*str1;
	char	*str2;

	sub = getcwd(0, 256);
	if (chdir(arg) == -1)
	{
		free(sub);
		return (-1);
	}
	temp = getcwd(0, 256);
	str1 = ft_strjoin("OLDPWD=", sub);
	str2 = ft_strjoin("PWD=", temp);
	set_new(str1);
	set_new(str2);
	free(sub);
	free(temp);
	return (1);
}

int	b_cd(char *arg)
{
	char	*key;

	if (!arg)
	{
		key = cut_key(g_shell_h->envp,
				find_path_env(g_shell_h->envp, "HOME"), "HOME");
		if (change_dir(key) == -1)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		free(key);
	}
	else
	{
		if (change_dir(arg) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
	}
	return (0);
}
