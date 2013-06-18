#ifndef __STATES_H_ 
#define __STATES_H_ 
#include "common.h"

EXTERN Uint nnode_states INIT( 3 );

bool set_sync_behavior( char b );

bool set_constant_state( Uint istate ) ;

void set_random_state() ;

bool set_full_state( Uint new_state[nnodes] ) ;

void propagate_state( Uint inode ) ;

bool set_node( Uint inode, Uint istate ) ;

char *get_state_str( Uint state[] ) ;

# endif // _STATES_H_
