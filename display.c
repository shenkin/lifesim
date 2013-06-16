#include <strings.h>
#include "common.h"
#include "display.h"


// B stands for Backslash; it will be replaced programmatically:
char display[] =
 "   --x--0          --x--1          --x--2         \n"
 "  /     B         /     B         /     B         \n"
 " x3      x4      x5      x6      x7      x8       \n"
 "/         B     /         B     /         B       \n"
 "           --x--9          --x--10         --x--11\n"
 "B         /     B         /     B         /       \n"
 " x12     x13     x14     x15     x16     x17      \n"
 "  B     /         B     /         B     /         \n"
 "   --x--18         --x--19         --x--20        \n"
 "  /     B         /     B         /     B         \n"
 " x21     x22     x23     x24     x25     x26      \n"
 "/         B     /         B     /         B       \n"
 "           --x--27         --x--28         --x--29\n"
 "B         /     B         /     B         /       \n"
 " x30     x31     x32     x33     x34     x35      \n"
 "  B     /         B     /         B     /         \n"
 "   --x--36         --x--37         --x--38        \n"
 "  /     B         /     B         /     B         \n"
 " x39     x40     x41     x42     x43     x44      \n"
 "/         B     /         B     /         B       \n"
 "           --x--45         --x--46         --x--47\n"
 "B         /     B         /     B         /       \n"
 " x48     x49     x50     x51     x52     x53      \n"
 "  B     /         B     /         B     /         \n\0";


void init_display() {
    Uint inode = 0;
    for( char *p=display; *p!='\0'; ++p ) {
        Uint offset = p - display;
        if( *p == 'x' ) {
            display_position[ inode ] = offset;
            inode += 1;
        } else if( *p == 'B' ) {
            *p = '\\';
        }
    }
}

void set_display( Uint state[nnodes] ){
    for( Uint inode=0; inode<nnodes; ++inode ) {
        Uint istate = state[ istate ];
        char display_char = display_states[ istate ];
        display_position[ inode ] = display_char;
    }
}

char *get_display() {
    return display;
}

