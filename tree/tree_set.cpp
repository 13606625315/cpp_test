#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};



BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }

    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }


    return 0;
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(NULL == BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Right = NULL;
        BST->Left = NULL;
    }
    else if(X > BST->Data)
    {
        BST->Right = Insert(BST->Right,X);
    }
    else if(X < BST->Data)
    {
        BST->Left = Insert(BST->Left,X);
    }

    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if(NULL == BST)
    {
        printf("Not Found\n");
    }
    else if(X>BST->Data)
    {
        BST->Right = Delete(BST->Right,X);
    }
    else if(X<BST->Data)
    {
        BST->Left = Delete(BST->Left,X);
    }
    else
    {
        if (NULL == BST->Right && NULL == BST->Left)
        {
            BST = NULL;
        }
        else if(NULL == BST->Right && NULL != BST->Left)
        {
            BST = BST->Left;
        }
        else if(NULL != BST->Right && NULL == BST->Left)
        {
            BST = BST->Right;
        }
        else
        {
            BinTree tmp = FindMin(BST->Right);
            BST->Data = tmp->Data;
            BST->Right = Delete(BST->Right,tmp->Data);
        }
    }

    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if(NULL == BST)
    {
        return NULL;
    }
    else if(X == BST->Data)
    {
        return BST;
    }
    else if(X > BST->Data)
    {
        return Find(BST->Right,X);
    }
    else
    {
        return Find(BST->Left,X);
    }
}

Position FindMin( BinTree BST )
{
    if(NULL == BST)
    {
        return NULL;
    }
    else if(NULL == BST->Left)
    {
        return BST;
    }
    else
    {
       return FindMin(BST->Left);
    }
}
Position FindMax( BinTree BST )
{
    if(NULL == BST)
    {
        return NULL;
    }
    else if(NULL == BST->Right)
    {
        return BST;
    }
    else
    {
        return FindMax(BST->Right);
    }
}