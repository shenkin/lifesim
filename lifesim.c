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
    for( Uint inode=0; inode<nnodes; inode+=1 ) {
        show_node_neighbors( inode );        
        printf( "node neighbors of node %d:\n%s", 
         inode, get_display() );
    }
    set_random_state( );
    printf( "after:\n%s", get_display() );
    printf( "Finito la musica\n" );
}
