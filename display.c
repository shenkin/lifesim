#include <strings.h>
#include "common.h"
#include "display.h"
#include "states.h"
#include "nodes.h"

// Display prototype.
// B stands for Backslash; it will be replaced programmatically
//  with the backslash character:
char display_pro[] =
 "   - x  0          - x  1          - x  2         \n"
 "  /     B         /     B         /     B         \n"
 " x 3     x 4     x 5     x 6     x 7     x 8      \n"
 "/         B     /         B     /         B       \n"
 "           - x  9          - x  10         - x  11\n"
 "B         /     B         /     B         /       \n"
 " x 12    x 13    x 14    x 15    x 16    x 17     \n"
 "  B     /         B     /         B     /         \n"
 "   - x  18         - x  19         - x  20        \n"
 "  /     B         /     B         /     B         \n"
 " x 21    x 22    x 23    x 24    x 25    x 26     \n"
 "/         B     /         B     /         B       \n"
 "           - x  27         - x  28         - x  29\n"
 "B         /     B         /     B         /       \n"
 " x 30    x 31    x 32    x 33    x 34    x 35     \n"
 "  B     /         B     /         B     /         \n"
 "   - x  36         - x  37         - x  38        \n"
 "  /     B         /     B         /     B         \n"
 " x 39    x 40    x 41    x 42    x 43    x 44     \n"
 "/         B     /         B     /         B       \n"
 "           - x  45         - x  46         - x  47\n"
 "B         /     B         /     B         /       \n"
 " x 48    x 49    x 50    x 51    x 52    x 53     \n"
 "  B     /         B     /         B     /         \n\0";

char *display; 


void init_display() {
    // copy display_pro to display:
    Uint l = strlen( display_pro );
    display = malloc( l + 1 );
    memcpy( display, display_pro, l+1 );
}

void init_display_pro() {
    // Initialize the display prototype string (replace
    //  B with backslash character) and copy it to the display:
    for( char *p=display_pro; *p!='\0'; ++p ) {
        Uint offset = p - display_pro;
        if( *p == 'B' ) {
            *p = '\\';
        }
    }
}

void init_display_position() {
    // Initialize the array of positions in the display
    //  associated with the nodes:
    Uint inode = 0;
    for( char *p=display; *p!='\0'; ++p ) {
        Uint offset = p - display;
        if( *p == 'x' ) {
            display_position[ inode ] = offset;
            inode += 1;
        }
    }
}

void set_display( Uint state[nnodes] ){
    // Set the display to a state:
    for( Uint inode=0; inode<nnodes; ++inode ) {
        Uint istate = state[ inode ];
        char c = display_chars[ istate ];
        Uint ipos = display_position[ inode ];
        display[ ipos ] = c;
    }
}

char *get_display() {
    return display;
}


void show_node_neighbors( Uint inode ) {
    // "Light up" node inode with state 0 and its neighbors 
    //  with state 1; this just performs a visible test of
    //  the neihbor arrays: 
    char cinode = display_chars[ 0 ]; // character for inode
    char cnnode = display_chars[ 1 ]; // character for neighbor
    init_display();
    Uint inode_pos = display_position[ inode ];
    display[ inode_pos ] = cinode;
    for( Uint jneigh=0; jneigh<nneighbors; jneigh+=1 ) {
        Uint nnode = nodes[ inode ].neighbors[ jneigh ];
        if( nnode < nnodes ){
            Uint nnode_pos = display_position[ nnode ];
            display[ nnode_pos ] = cnnode;
        }
    }
}
