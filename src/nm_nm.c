/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_nm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:35 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/26 12:37:46 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm_otool.h"

void handle_64(char *ptr){
    int                     ncmds;
    int                     i;
    struct mach_header_64   *header;
    struct load_command     *lc;

    header = (struct mach_header_64 *) ptr;
    ncmds = header->ncmds;
    i = 0;
    lc = (void *)ptr + sizeof(*header);
    while (i < ncmds){
        if (lc->cmd == LC_SYMTAB){
            ft_printf("here");
            break;
        }
        lc = (void *) lc + lc->cmdsize;
        i++;
    }
}

void    nm(char *ptr)
{
    uint32_t magic_number;
    magic_number = (u_int32_t) ptr;
    if (magic_number == MH_MAGIC_64)
        handle_64(ptr);
}

void	start_nm(char *path)
{
	int fd;
    char *ptr;
    struct stat buf;

    if ((fd = open(path, O_RDONLY)) < 0){
        ft_printf("Error: Unable to open file: \"%s\"\n", path);
        exit(1);
    }
    if (fstat(fd, &buf) < 0)
        ft_error("fstat");
    if (((ptr = (char *)mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED))
        ft_error("mmap");
    nm(ptr);
    if (munmap(ptr, buf.st_size) < 0)
        ft_error("munmap");
}