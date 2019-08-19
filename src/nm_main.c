/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:35 by cterblan          #+#    #+#             */
/*   Updated: 2019/08/09 09:38:59 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm_otool.h"

int main(int ac, char **av){
    int         fd;
    void        *ptr;
    struct stat buf;

    if (ac != 2){
        ft_printf("Please pass an argument!\n");
        return(1);
    }
    if ((fd = open(av[1], O_RDONLY)) < 0){
        ft_printf("Error: Unable to open file \"%s\"\n", av[1]);
        return (1);
    }
    if ((fstat(fd, &buf) < 0)){
        ft_printf("Error: fstat unable to gather data.\n");
        return (1);
    }
    if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED){
        ft_printf("Error: mmap failed to allocate memory.\n");
        return (1);
    }
    nm_parse(ptr);
    if ((munmap(ptr, buf.st_size) < 0)){
        ft_printf("Error: unmap failed to clear memory.\n");
        return(1);
    }
}