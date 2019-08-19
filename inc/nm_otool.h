/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:05:47 by cterblan          #+#    #+#             */
/*   Updated: 2019/08/09 08:18:25 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "../inc/private_includes.h"

/*
** Functions
*/
void nm_parse(void *ptr);
void handle_64(char *ptr);
char symbol_type_64(struct nlist_64 symtable);
void output(struct symtab_command * sym, void *ptr);

/*
** Structures
*/
typedef struct      s_data_64 {
    uint64_t        value;
    char            symbol;
    char            *name;

    struct s_data   *prev;
    struct s_data   *next;
}                   t_data_64;

typedef struct      s_data_32 {
    uint32_t        value;
    char            symbol;
    char            *name;

    struct s_data   *prev;
    struct s_data   *next;
}                   t_data_32;

/*
**  Global variables
*/
void    *g_data;

#endif