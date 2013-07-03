#define DEF
#include "common.h"
#include "nodes.h"
#include "states.h"
#include "display.h"

int main( int nargs, char *args[] ) {
    init_display_pro();
    init_display();
    init_display_position();
    initialize_node_neighbors();

    time_t *tloc;
    srandom( time(tloc) );
    set_random_state( );
    char last_state_str[ nnodes + 1 ];
    strcpy( last_state_str, get_state_str() );
    printf( "initial state:\n%s", get_display() );
    Uint i=0;
    Uint converged = 0;
    for( ; i<100; ++i ) {
        printf( "i, state str= %4d, %s\n", i, get_state_str() );
        propagate_state( 0 );
        char *state_str = get_state_str();
        if( !strcmp(state_str,last_state_str) ) {
            converged = 1;
            break;
        }
        strcpy( last_state_str, state_str );
    }
    printf( "i, state str= %4d, %s\n", i, get_state_str() );

    char *msg;
    if( converged ) {
        msg = "converged at step";
    } else {
        msg = "did not converge by step";
    }
    printf( "%s %d\n", msg, i );

    set_display_to_state();
    printf( "final state:\n%s", get_display() );
    printf( "Finito la musica\n" );
}
