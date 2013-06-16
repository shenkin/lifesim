#ifndef __NODES_H_ 
#define __NODES_H_ 
#include "common.h"

#define nnodes 54
#define nneighbors 4

typedef struct {
    Uint state;
    Uint neighbors[ nneighbors ];
} Node;

EXTERN Node nodes[ nnodes ];

# endif // _NODES_H_
