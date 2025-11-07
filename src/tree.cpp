#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void printNode( const node_t* node ){
    assert( node );

    printf( "(" treeValueFormat " ", node->data );

    if( node->left && (node->left)->left && (node->left)->right ){
        printNode( node->left );
    }
    if( node->right && (node->right)->left && (node->right)->right ){
        printNode( node->right );
    }

    printf( ")" );
}

void printTheSortedTree( const node_t* node ){
    assert( node );

    if( node->left && (node->left)->left && (node->left)->right ){
        printTheSortedTree( node->left );
    }

    printf( treeValueFormat " ", node->data );

    if( node->right && (node->right)->left && (node->right)->right ){
        printTheSortedTree( node->right );
    }
}

treeErrors initNode( node_t* node, treeElem_t element ){
    assert( node );

    node->data = element;

    node->left = (node_t*)calloc( oneStruct, sizeof( node_t ) );
    if( node->left == NULL ){
        return NOT_ENOUGH_MEMORY;
    }

    node->right = (node_t*)calloc( oneStruct, sizeof( node_t ) );
    if( node->right == NULL ){
        return NOT_ENOUGH_MEMORY;
    }

    return CORRECT_TREE;
}

treeErrors initTree( tree_t* tree ){
    assert( tree );

    treeErrors errorWithInitialization = initNode( tree, maxTreeValue );

    if( errorWithInitialization != CORRECT_TREE ){
        return errorWithInitialization;
    }

    return CORRECT_TREE;
}

treeErrors insertNode( node_t* root, treeElem_t element ){
    if( root == NULL ){
        return NODE_NULL_PTR;
    }

    node_t** nodePtr = &root;
    while( (*nodePtr)->right && (*nodePtr)->left ){
        if( element <= (*nodePtr)->data ){
            nodePtr = &( (*nodePtr)->left );
        }
        else{
            nodePtr = &( (*nodePtr)->right );
        }
    }

    initNode( *(nodePtr), element );

    return CORRECT_TREE;
}

void destroyNode( node_t* node ){
    assert( node );

    printf( "\n\nnode = %p\nData = "  treeValueFormat "\nleft prt = %p\nright ptr = %p\n", node, node->data, node->left, node->right );

    node->data = {};

    if( node->left  ){
        destroyNode( node->left );
    }

    if( node->right ){
        destroyNode( node->right );
    }

    printf( "\nnode %p befor delete\n", node );
    free( node );
}

void destroyTree( tree_t* tree ){
    if( tree == NULL ){
        return ;
    }

    if( tree->left ){
        destroyNode( tree->left );
    }
    if( tree->right ){
        destroyNode( tree->right );
    }

    *tree = {};
}
