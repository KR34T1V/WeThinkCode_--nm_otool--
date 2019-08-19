#include "../inc/nm_otool.h"

void output(struct symtab_command * sym, void *ptr){
    uint32_t i;
    char *strtable;
    struct nlist_64 *symtable;

    symtable = (void *)ptr + sym->symoff;
    strtable = (void *)ptr + sym->stroff;

    i = 0;
    while (i < sym->nsyms){
        if (symtable[i].n_un.n_strx) { //do not print empty symbols
            ft_printf("%016llx %s\n",symtable[i].n_value, strtable + symtable[i].n_un.n_strx);
        }
        i++;
    }
}