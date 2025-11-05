#include <stdio.h>

#include "tree.h"

int main(){
    node_t node_1 = {};
    initNode( &node_1 );

    node_t node_2 = {};
    initNode( &node_2 );

    node_t node_3 = {};
    initNode( &node_3 );

    node_t node_4 = {};
    initNode( &node_4 );

    node_t node_5 = {};
    initNode( &node_5 );

    node_t node_6 = {};
    initNode( &node_6 );

    node_1.data = 10;
    node_2.data = 20;
    node_3.data = 5;
    node_4.data = 3;
    node_5.data = 7;
    node_6.data = 15;

    node_1.left = &( node_3 );
    node_1.right = &( node_2 );
    node_2.left = &( node_6 );
    node_3.left = &( node_4 );
    node_3.right = &( node_5 );

    printNode( &node_1 );
    printf( "\n" );

    dumpTree( &node_1 );

    destroyNode( &node_1 );

    return 0;
}
