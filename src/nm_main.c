/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:35 by cterblan          #+#    #+#             */
/*   Updated: 2019/08/09 08:35:39 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm_otool.h"
void handle_64(char *ptr){
    uint32_t ncmds;
    uint32_t i;
    struct mach_header_64 *header;
    struct load_command *lc;
    struct symtab_command *sym;


    header = (struct mach_header_64 *)ptr;
    i = 0;
    ncmds = header->ncmds;
    lc = (void *)ptr + sizeof(*header);
    while (i < ncmds){
        if (lc->cmd == LC_SYMTAB){
            sym = (struct symtab_command *) lc;
            ft_printf("symboles = %d\n", sym->nsyms);
            break;
        }
        lc = (void *)lc + lc->cmdsize;
        i++;
    }
}

void nm(char *ptr){
    uint32_t magic_number;

    magic_number = *(uint32_t *)ptr;
    if (magic_number == MH_MAGIC_64){
        ft_printf("64\n");
        handle_64(ptr);
    }
}

int main(int ac, char **av){
    int fd;
    char *ptr;
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
    nm(ptr);
    if ((munmap(ptr, buf.st_size) < 0)){
        ft_printf("Error: unmap failed to clear memory.\n");
        return(1);
    }
}