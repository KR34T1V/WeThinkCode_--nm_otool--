#include "../inc/nm_otool.h"


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
            output(sym, ptr);
            break;
        }
        //check LC_SEGMENT_64
        lc = (void *)lc + lc->cmdsize; //move to next command
        i++;
    }
}

void populate_64(struct symtab_command * sym, void *ptr){
    uint32_t        i;
    char            *strtable;
    struct nlist_64 *symtable;
    t_data_64       *head;
    t_data_64       *run;
    
    if (!(head = (t_data_64 *)malloc(sizeof(head))))
        exit(1);
    head->next = NULL;
    head->prev = NULL;
    run = head;
    symtable = (void *)ptr + sym->symoff;
    strtable = (void *)ptr + sym->stroff;

    i = 0;
    run = (t_data_64 *)g_data;
    while (i < sym->nsyms){
            run->value = symtable[i].n_value;
            run->symbol = symbol_type_64(symtable[i]);
            run->value = symtable[i].n_un.n_strx;
        i++;
    }
}