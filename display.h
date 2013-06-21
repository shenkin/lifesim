#ifndef _DISPLAY_H_
#define _DISPLAY_H_
    
#include "common.h"
#include "nodes.h"

// For each node, list its index in the display string:
EXTERN Uint display_position[ nnodes ];

// Allowed display states:
EXTERN char display_chars[] INIT( "RGB" );

void init_display_pro();
void init_display();

void init_display_position();

void set_display( Uint state[nnodes] );

char *get_display();

void show_node_neighbors( Uint inode ) ;

#endif // _DISPLAY_H_
