#define DEF
#include "common.h"
#include "nodes.h"
#include "states.h"
#include "display.h"

int main( int nargs, char *args[] ) {
    init_display_pro();
    init_display();
    init_display_position();
    printf( "before:\n%s", get_display() );
    initialize_node_neighbors();
/*
    for( Uint inode=0; inode<nnodes; inode+=1 ) {
        show_node_neighbors( inode );        
        printf( "node neighbors of node %d:\n%s", 
         inode, get_display() );
    }
*/
    set_random_state( );
    printf( "after:\n%s", get_display() );
    printf( "after state str: %s\n", get_state_str( ) );
    char last_state_str[ nnodes + 1 ];
    strcpy( last_state_str, get_state_str );
    for( Uint i=0; i<100; ++i ) {
        propagate_state( 0 );
        char * state_str = get_state_str();
        if( !strcmp(state_str,last_state_str) ) {
            printf( "converged at state %d\n", i );
            break;
        }
        strcpy( last_state_str, state_str );
        //set_display_to_state();
        printf( "i, state str= %4d, %s\n", i, get_state_str( ) );
    }
    printf( "at end state str= %s\n", get_state_str( ) );
    printf( "at end:\n%s", get_display() );
    printf( "Finito la musica\n" );
}
