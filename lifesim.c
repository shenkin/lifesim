#define DEF
#include "common.h"
#include "nodes.h"
#include "states.h"
#include "display.h"

int main( int nargs, char *args[] ) {
    printf( "before:\n%s", get_display() );
    init_display();
    set_random_state( );
    printf( "after:\n%s", get_display() );
}
