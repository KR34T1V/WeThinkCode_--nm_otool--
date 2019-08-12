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

char get_type(struct nlist_64 *symtable){
    uint8_t type;
    char tmp;
    
    type = symtable->n_type;
    if (type == N_UNDF)
        tmp  = 'u'; //undefined
    if (type == N_ABS)
        tmp = 'a'; //absolute
    if (type == N_SECT)
        //Defined in section number n_sect
    if (type == N_PBUD)
        //prebound undefined
    if (type == N_INDR)
        //Indirect
    if (type == N_EXT)
        tmp = ft_toupper(tmp);
    
}

void print_output(struct symtab_command * sym, void *ptr){
    uint32_t i;
    char *strtable;
    struct nlist_64 *symtable;

    symtable = (void *)ptr + sym->symoff;
    strtable = (void *)ptr + sym->stroff;

    i = 0;
    while (i < sym->nsyms){
        if (symtable[i].n_un.n_strx) //do not print empty symbols
            printf("%s\n", strtable + symtable[i].n_un.n_strx);
        i++;
    }
}

void handle_64(char *ptr){
    uint32_t ncmds;
    uint32_t i;
    struct mach_header_64 *header;
    struct load_command *lc;
    struct symtab_command *sym;


    header = (struct mach_header_64 *)ptr;
    ncmds = header->ncmds;
    lc = (void *)ptr + sizeof(*header);
    i = 0;
    while (i < ncmds){
        if (lc->cmd == LC_SYMTAB){ //check command
            sym = (struct symtab_command *) lc;
            ft_printf("symboles = %d\n", sym->nsyms);
            print_output(sym, ptr);
            break;
        }
        //check LC_SEGMENT_64
        lc = (void *)lc + lc->cmdsize; //move to next command
        i++;
    }
}

void nm(void *ptr){
    uint32_t magic_number;

    magic_number = *(uint32_t *)ptr;
    if (magic_number == MH_MAGIC_64){
        ft_printf("64 bit\n");
        handle_64(ptr);
        //Handle MH_CIGAM_64
    } else if (magic_number == MH_MAGIC) {
        ft_printf("32 bit\n");
        //handle_32
        //Handle MH_CIGAM
    }
}

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
    nm(ptr);
    if ((munmap(ptr, buf.st_size) < 0)){
        ft_printf("Error: unmap failed to clear memory.\n");
        return(1);
    }
}