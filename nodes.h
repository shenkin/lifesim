#ifndef __NODES_H_ 
#define __NODES_H_ 
#include "common.h"

#define nnodes 54
#define nneighbors 4

typedef struct node_struct {
    Uint state;
    Uint neighbors[ nneighbors ];
} Node;

typedef Node Nodes[ nnodes ];
EXTERN Nodes nodes;

void initialize_node_neighbors();

# endif // _NODES_H_
