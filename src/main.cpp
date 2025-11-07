#include <stdio.h>

#include "tree.h"
#include "treeDump.h"

int main(){

    tree_t tree = {};

    initTree( &tree );

    insertNode( &tree , 10 );
    insertNode( &tree , 20 );
    insertNode( &tree , 5 );
    insertNode( &tree , 3 );
    insertNode( &tree , 7 );
    insertNode( &tree , 15 );

    printTree( &tree );
    printf( "\n" );

    printf( "\nThe sorted tree:\n\n" );
    printTheSortedTree( &tree );
    printf( "\n" );

    dumpTree( &tree );

    destroyTree( &tree );

    return 0;
}
