#include <stdio.h>

#include "tree.h"
#include "treeDump.h"

int main(){

    tree_t tree = {};

    initTree( &tree );

    insertNode( &tree.rootTree, 10 );
    insertNode( &tree.rootTree, 20 );
    insertNode( &tree.rootTree, 5 );
    insertNode( &tree.rootTree, 3 );
    insertNode( &tree.rootTree, 7 );
    insertNode( &tree.rootTree, 15 );

    printNode( &tree.rootTree );
    printf( "\n" );

    dumpTree( &tree.rootTree );

    printf( "\nThe sorted tree:\n\n" );
    printTheSortedTree( &tree.rootTree );
    printf( "\n" );

    dumpTree( &tree.rootTree );

    destroyTree( &tree.rootTree );

    return 0;
}
