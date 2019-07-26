/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_nm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:35 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/26 12:03:36 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm_otool.h"

void	start_nm(char *path)
{
	int fd;
    char *ptr;
    struct stat buf;

    if ((fd = open(path, O_RDONLY)) < 0)
        ft_error("open");
    if (fstat(fd, &buf) < 0)
        ft_error("fstat");
    if (((ptr = (char *)mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED))
        ft_error("mmap");
    
}