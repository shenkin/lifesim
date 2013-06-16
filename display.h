#ifndef _DISPLAY_H_
#define _DISPLAY_H_
    
#include "common.h"
#include "nodes.h"

EXTERN Uint display_position[ nnodes ];
EXTERN char display_states[] INIT( "rgb" );

void init_display();

void set_display( Uint state[nnodes] );

char *get_display();

#endif // _DISPLAY_H_
