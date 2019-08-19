#include "../inc/nm_otool.h"

char symbol_type_64(struct nlist_64 symtable){
    uint8_t type;
    char tmp;
    //U (undefined) A (absolute) T (text section symbol) D (data section symbol)
    //B (bss section symbol) C (common symbol)
    //- (for debugger symbol table entries; see -a below)
    //S (symbol in a section other than those above)
    //I (indirect symbol)
    //If the symbol is local (non-external) its lowercase
    type = symtable.n_type;
    if ((type & N_TYPE) == N_UNDF)
        tmp  = 'u'; //undefined
    if ((type & N_TYPE) == N_ABS)
        tmp = 'a'; //absolute
    if ((type & N_TYPE) == N_INDR)
        tmp = 'i'; //indirect
    if (tmp && type == N_EXT)
        tmp = ft_toupper(tmp);
    return (tmp);
    
}