#ifndef H_TREE
#define H_TREE

#include <limits.h>

typedef int treeElem_t;
#define treeValueFormat "%d"
#define maxTreeValue INT_MAX

const size_t oneStruct = 1;

enum treeErrors {
    CORRECT_TREE        = 0,
    NODE_NULL_PTR       = 1,
    NOT_ENOUGH_MEMORY   = 2,
    ERROR_OF_OPEN_FILE  = 3
};

struct node_t {
    treeElem_t data;
    node_t* left;
    node_t* right;
};

struct tree_t{
    node_t rootTree;
};

void printNode( const node_t* node );

void printTheSortedTree( const node_t* node );

treeErrors initTree( tree_t* tree );

treeErrors initNode( node_t* node, treeElem_t element );

treeErrors insertNode( node_t* root, treeElem_t element );

void destroyNode( node_t* node );

void destroyTree( node_t* node );

#endif
