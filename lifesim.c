#define DEF
#include "common.h"
#include "nodes.h"
#include "states.h"
#include "display.h"

int main( int nargs, char *args[] ) {
    printf( "before:\n%s", get_display() );
    init_display();
    printf( "between:\n%s", get_display() );
    set_constant_state( 0 );
    printf( "after:\n%s", get_display() );
}
