#include <stdio.h>
#include <string.h>

int tmp1[10];
int tmp2[10];

typedef struct Node{
    int data;
    Node * left;
    Node * right;
    Node()
    {
        data= 0;
        left = NULL;
        right = NULL;
    }
}Node;

typedef Node* Tree;

Tree insert(Tree tree, int data)
{
    if(tree == NULL)
    {
        Tree tmp = new Node;
        tmp->data = data;
        tree = tmp;
    }
    else 
    {
        if(data > tree->data)
        {
            tree->right = insert(tree->right,data);
        }
        else if(data < tree->data)
        {
            tree->left = insert(tree->left,data);
        }
    }
    return tree;
}

Tree makeTree(int *a,int num)
{
    Tree tree = NULL;
    for(int i = 0; i < num; i++)
    {
       tree = insert(tree,a[i]);
    }
    return tree;
}

bool comp(Tree tr1, Tree tr2)
{   
    if(tr1 == NULL && tr2 == NULL)
    {
        return true;
    }
    else if(tr1!= NULL && tr2!= NULL)
    {
        if(tr1->data == tr2->data)
        {
            return comp(tr1->right,tr2->right) && comp(tr1->left,tr2->left);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


void test(int *a,int num)
{
    for(int i = 0; i <num;i++)
    {
        printf(" %d",a[i]);
    }
}

void print(int* a, int* b,int num)
{
    Tree tree_a = makeTree(a,num);
    Tree tree_b = makeTree(b,num);

    bool f = comp(tree_a,tree_b);
    static bool flag = false;
    if(flag)
    {
        printf("\n");
    }
    flag = true;
    if(f)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

int main()
{
    int num=0;
    do
    {
        int line = -1;
        memset(tmp1,0,sizeof(tmp1));
        scanf("%d",&num);

        if(num != 0)
        {
            scanf("%d",&line);
        }

        for(int i = 0; i < line + 1; i++)
        {
            memset(tmp2,0,sizeof(tmp2));

            if(i == 0)
            {
                for(int j = 0; j <num ; j++)
                {
                    scanf("%d",&tmp1[j]);
                }
            }
            else
            {
                for(int j = 0; j <num ; j++)
                {
                    scanf("%d",&tmp2[j]);
                } 
                print(tmp1,tmp2,num);
            }
        }
    
    }while(num != 0);
    
    return 0;
}