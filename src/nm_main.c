/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:39 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/25 22:07:09 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm_otool.h"

int		main(int ac, char **av){
	int i;

	if (ac <= 1)
		start_nm("a.out");
	else
	{
		i = 1;
		while (i < ac)
			start_nm(av[i]);
	}
	return (0);
}