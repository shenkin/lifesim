#include "common.h"
#include "nodes.h"

Uint neighbor_initializer[][ 4 ] = {
 { 3, 4, nnodes, nnodes }, // Node 0
 { 5, 6, nnodes, nnodes }, // Node 1
 { 7, 8, nnodes, nnodes  }, // Node 2

 { 0, 11, 12, nnodes }, // Node 3
 { 0, 9, 13, nnodes }, // Node 4
 { 1, 9, 14, nnodes }, // Node 5
 { 1, 10, 15, nnodes }, // Node 6
 { 2, 10, 16, nnodes }, // Node 7
 { 2, 11, 17, nnodes,}, // Node 8

 { 4, 5, 13, 14 }, // Node 9
 { 6, 7, 15, 16 }, // Node 10
 { 3, 8, 12, 17 }, // Node 11

 { 3, 11, 18, 21 }, // Node 12
 { 4, 9, 18, 22 }, // Node 13
 { 9, 5, 19, 23 }, // Node 14
 { 6, 10, 19, 24 }, // Node 15
 { 7, 10, 20, 25 }, // Node 16
 { 8, 11, 20, 26 }, // Node 17

 { 12, 13, 21, 22 }, // Node 18
 { 14, 15, 23, 24 }, // Node 19
 { 16, 17, 25, 26 }, // Node 20

 { 12, 18, 29, 30 }, // Node 21
 { 13, 18, 27, 31 }, // Node 22
 { 14, 19, 27, 32 }, // Node 23
 { 15, 19, 28, 33 }, // Node 24
 { 16, 20, 28, 34 }, // Node 25
 { 17, 20, 29, 35 }, // Node 26

 { 22, 23, 31, 32 }, // Node 27
 { 24, 25, 34, 33 }, // Node 28
 { 26, 21, 35, 30 }, // Node 29

 { 21, 26, 36, 39 }, // Node 30
 { 22, 27, 36, 40 }, // Node 31
 { 27, 23, 37, 41 }, // Node 32
 { 24, 28, 37, 42 }, // Node 33
 { 28, 25, 38, 43 }, // Node 34
 { 26, 29, 38, 44 }, // Node 35

 { 30, 31, 39, 40 }, // Node 36
 { 32, 33, 41, 42 }, // Node 37
 { 34, 35, 43, 44 }, // Node 38

 { 30, 36, 47, 48 }, // Node 39
 { 36, 31, 45, 49 }, // Node 40
 { 32, 37, 45, 50 }, // Node 41
 { 37, 33, 46, 51 }, // Node 42
 { 34, 38, 46, 52 }, // Node 43
 { 38, 35, 53, 47 }, // Node 44

 { 40, 41, 49, 50 }, // Node 45
 { 42, 43, 51, 52 }, // Node 46
 { 44, 53, 39, 48 }, // Node 47

 { 47, 39, nnodes, nnodes }, // Node 48
 { 40, 45, nnodes, nnodes }, // Node 49
 { 45, 41, nnodes, nnodes }, // Node 50
 { 42, 46, nnodes, nnodes }, // Node 51
 { 46, 43, nnodes, nnodes }, // Node 52
 { 44, 47, nnodes, nnodes } // Node 53
 };

void initialize_node_neighbors() {
    for( Uint inode=0; inode<nnodes; ++inode ) {
        for( Uint ineigh=0; ineigh<nneighbors; ++ineigh ) {
            nodes[ inode ].neighbors[ ineigh ] 
             = neighbor_initializer[ inode ][ ineigh ];
        }
    }
}

