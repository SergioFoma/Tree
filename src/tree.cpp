#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void printNode( const node_t* node ){
    assert( node );

    printf( "(" );
    printf( treeValueFormat " ", node->data );

    if( node->left ){
        printNode( node->left );
    }
    if( node->right ){
        printNode( node->right );
    }

    printf( ")" );
}

treeErrors initNode( node_t* node ){
    assert( node );

    node->data = ( treeElem_t )0;
    node->left = ( node_t* )calloc( oneStruct, sizeof( node_t* ) );
    if( node->left == NULL ){
        return NOT_ENOUGH_MEMORY;
    }
    node->left = NULL;

    node->right = ( node_t* )calloc( oneStruct, sizeof( node_t* ) );
    if( node->right == NULL ){
        return NOT_ENOUGH_MEMORY;
    }
    node->right = NULL;

    return CORRECT_TREE;

}

void destroyNode( node_t* node ){
    assert( node );

    node->data = ( treeElem_t )0;

    if( node->left  ){
        destroyNode( node->left );
    }
    else if( node->right ){
        destroyNode( node->right );
    }

    /*free( node->left );
    free( node->right );*/
}

void dumpNode( node_t* node, int rank, FILE* treeFile ){
    assert( node );
    assert( treeFile );

    fprintf( treeFile, "\tnode%lx [shape=\"plain\"; style =\"filled\"; fillcolor =\"azure3\"; label = "
                        "<<table><tr><td> %p </td></tr> <tr><td> elem = " treeValueFormat "</td></tr> ",
                        ( unsigned long )node, node, node->data  );

    if( node->left != NULL ){
        fprintf( treeFile, "<tr><td> %p </td></tr>", node->left );
    }
    else{
        fprintf( treeFile, "<tr><td> NULL </td></tr>" );
    }

    if( node->right != NULL ){
        fprintf( treeFile, "<tr><td> %p </td></tr>", node->right );
    }
    else{
        fprintf( treeFile, "<tr><td> NULL </td></tr>" );
    }

    fprintf( treeFile, "</table>>;color = \"red\"];\n" );

    fprintf( treeFile, "\t{\n"
                       "\t\trank = %d;\n"
                       "\t\tnode%lx;\n"
                       "\t}\n",
                       rank, ( unsigned long )node );

    if( node->left ){
        fprintf( treeFile, "\t\tnode%lx;\n"
                            "\tnode%lx->node%lx[color = \"orange\"];\n",
                            ( unsigned long )node->left, ( unsigned long )node, ( unsigned long )node->left );
        dumpNode( node->left, rank + 1, treeFile );
    }
    if( node->right ){
        fprintf( treeFile, "\t\tnode%lx;\n"
                           "\tnode%lx->node%lx[color = \"orange\"];\n",
                           ( unsigned long )node->right, ( unsigned long )node, ( unsigned long )node->right );
        dumpNode( node->right, rank + 1, treeFile );
    }

}

treeErrors dumpTree( node_t* node ){
    assert( node );

    FILE* treeFile = fopen( "treeDump.txt", "w" );

    if( treeFile == NULL ){
        return ERROR_OF_OPEN_FILE;
        fclose( treeFile );
    }

    fprintf( treeFile,  "digraph G{\n"
                        "\trankdir = TB;\n"
                        "\tnode[shape = \"hexagon\", color = \"black\", fontsize = 14, shape = record ];\n"
                        "\tedge[color = \"red\", fontsize = 12];\n" );

    dumpNode( node, firstRank, treeFile );

    fprintf( treeFile, "}" );

    fclose( treeFile );

    system("dot treeDump.txt -Tpng -o treeDump.png");

    return CORRECT_TREE;
}
