/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:09:36 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 20:09:38 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	b_export(char **args)
{
	int	i;

	if (!args[1])
	{
		print_export();
		return (1);
	}
	i = 0;
	if (check_keyword(args[1]) || !args[2])
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(args[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	set_new(ft_strjoin(args[1], args[2]));
	return (0);
}
