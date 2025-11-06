#ifndef H_TREE
#define H_TEE

typedef int treeElem_t;
#define treeValueFormat "%d"

const size_t oneStruct = 1;
static int firstRank   = 1;

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

void printNode( const node_t* node );

void printTheSortedTree( const node_t* node );

node_t* initNode( treeElem_t element );

treeErrors insertNode( node_t* root, treeElem_t element );

void destroyNode( node_t* node );

treeErrors dumpTree( node_t* node );

void dumpNode( node_t* node, int rank, FILE* treeFile );

#endif
