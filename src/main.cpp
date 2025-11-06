#include <stdio.h>

#include "tree.h"

int main(){
    node_t* node_1 = initNode( 10 );

    /*node_t* node_2 = initNode( 20 );

    node_t* node_3 = initNode( 5 );

    node_t* node_4 = initNode( 3 );

    node_t* node_5 = initNode( 7 );

    node_t* node_6 = initNode( 15 );

    node_1->left    = node_3 ;
    node_1->right   = node_2 ;
    node_2->left    = node_6 ;
    node_3->left    = node_4 ;
    node_3->right   = node_5 ;*/

    insertNode( node_1, 20 );
    insertNode( node_1, 5 );
    insertNode( node_1, 3 );
    insertNode( node_1, 7 );
    insertNode( node_1, 15 );
    insertNode( node_1, 60 );

    printNode( node_1 );
    printf( "\n" );

    dumpTree( node_1 );

    printf( "\nThe sorted tree:\n\n" );
    printTheSortedTree( node_1 );
    printf( "\n" );

    destroyNode( node_1 );

    return 0;
}
