#include "../inc/nm_otool.h"

void nm_parse(void *ptr){
    uint32_t magic_number;

    magic_number = *(uint32_t *)ptr;
    if (magic_number == MH_MAGIC_64){
        if(!(g_data = (t_data_64 *)malloc(sizeof(t_data_64))))
            exit(1);
        handle_64(ptr);
        //Handle MH_CIGAM_64
    } else if (magic_number == MH_MAGIC) {
        if(!(g_data = (t_data_32 *)malloc(sizeof(t_data_32))))
            exit(1);
        //handle_32
        //Handle MH_CIGAM
    }
}