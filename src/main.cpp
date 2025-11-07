#include <stdio.h>

#include "tree.h"

int main(){
    node_t node_1 = {};

    initNode( &node_1, 10 );

    insertNode( &node_1, 20 );
    insertNode( &node_1, 5 );
    insertNode( &node_1, 3 );
    insertNode( &node_1, 7 );
    insertNode( &node_1, 15 );

    printNode( &node_1 );
    printf( "\n" );

    dumpTree( &node_1 );

    printf( "\nThe sorted tree:\n\n" );
    printTheSortedTree( &node_1 );
    printf( "\n" );

    destroyNode( &node_1 );

    return 0;
}
