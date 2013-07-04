#include "common.h"

char behavior = 'g';
static Uint state[ nnodes ];

static bool check_state( Uint istate ) {
    if( istate < nnode_states ) {
        return true;
    } else {
        return false;
    }
}

static bool check_node( Uint inode ) {
    if( inode < nnodes ) {
        return true;
    } else {
        return false;
    }
}

static void update_node( Uint inode, Uint istate ) {
    state[ inode ] = istate;
    nodes[ inode ].state = istate;
}

static void copy_state_vector( Uint dest[nnodes], Uint src[nnodes] ) {
    for( Uint i=0; i<nnodes; i+=1 ) {
        dest[ i ] = src[ i ];
    }
}

static void propagate_state_gang() {
    Uint new_state[ nnodes ];
    for( Uint i=0; i<nnodes; i+=1 ) {
        Uint *neighbors = nodes[ i ].neighbors;
        Uint istate = state[ i ];
        Uint istate_plus_one = ( istate + 1 ) % nnode_states;
        new_state[ i ] = istate;
        for( Uint j=0; j<nneighbors; j+= 1 ) {
            Uint neighbor = neighbors[ j ];
            Uint neighbor_state = state[ neighbor ];
            if( neighbor == nnodes ) {
                // This node has no more neighbors
                break;
            }
            if( neighbor_state == istate_plus_one ) {
                new_state[ i ] = istate_plus_one;
                break;
            }
        }
    }
    copy_state_vector( state, new_state );
}

static void propagate_state_seq( Uint inode ) {
}

static void propagate_state_rand() {
}

char *get_state_str( ) {
    static char str[ nnodes + 1 ];
    str[ nnodes ] = '\0';
    for( Uint inode=0; inode<nnodes; ++inode ) {
        str[ inode ] = '0' + state[ inode ];
    }
    return str;
}

bool set_sync_behavior( char b ) {
    switch ( b ) {
        case 'g':
            break;
        case 's':
            break;
        case 'r':
            break;
        default:
            return false;
            break;
    }
    behavior = b;
    return true;
}

bool set_constant_state( Uint istate ) {
    if( ! check_state(istate) ) {
        return false;
    }
    for( Uint i=0; i<nnodes; i+=1 ) {
        update_node( i, istate );
    }
    set_display( state );
    return true;
}

void set_random_state() {
    for( Uint i=0; i<nnodes; i+=1 ) {
        Uint istate = random() % nnode_states;
        update_node( i, istate );
    }
    set_display( state );
}

bool set_full_state( Uint new_state[nnodes] ) {
    for( Uint i=0; i<nnodes; i+=1 ) {
        Uint istate = new_state[ i ];
        if( ! check_state(istate) ) {
            return false;
        }
    }
    copy_state_vector( state, new_state );
    return true;
}

void propagate_state( Uint inode ) {
    
    switch ( behavior ) {
        case 'g':
            propagate_state_gang();
            break;
        case 's':
            propagate_state_seq( inode );
            break;
        case 'r':
            propagate_state_rand();
            break;
    }
}

bool set_node( Uint inode, Uint istate ) {
    if( ! check_state(istate) ) {
        return false;
    }
    if( ! check_node(inode) ) {
        return false;
    }
    update_node( inode, istate );
}

void set_display_to_state( ){
    // Set the display to the current state
    //printf( "before setting display: %s\n", get_state_str() );
    set_display( state );
    //printf( "after setting display: %s\n", get_state_str() );
}
