/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_includes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:44 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/26 12:50:07 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_INCLUDES_H
# define PRIVATE_INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

# include "../lib/ft_printf/inc/export_ft_printf.h"

typedef struct      s_mach_header
{
    uint64_t        magic;
    cpu_type_t      cpu_type;
    cpu_subtype_t   cpu_subtype;
    uint64_t        filetype;
    uint64_t        ncmds;
    uint64_t        cmd_size;
    uint64_t        flags;
}                   t_mach_header;

typedef struct      s_segment_command
{
    uint64_t        cmd;
    uint64_t        cmd_size;
    char            seg_name[16];
    uint64_t        vm_addr;
    uint64_t        vm_size;
    uint64_t        file_off;
    uint64_t        file_size;
    vm_prot_t       max_prot;
    vm_prot_t       init_prot;
    uint64_t        nsects;
    uint64_t        flags;
}                   t_seg_cmd;
#endif