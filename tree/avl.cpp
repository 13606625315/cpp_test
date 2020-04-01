#include <stdio.h>

typedef struct Node
{
    int k;
    Node* left;
    Node* right;
    int hight;
    Node(){
        k = 0;
        left = right = NULL;
        hight = 0;
    }
}Node;

typedef Node* Tree;

int max(int a,int b)
{
    return a>b?a:b;
}

  int getH(Tree A)
  {
      int MaxH, HR, HL;
      if(A) {
        //   HL = getH(A->left);
        //   HR = getH(A->right);
        //   MaxH = (HL>HR)?HL:HR;
          return A->hight;
      }
      return -1;
  }
  

Tree RR(Tree t)
{
    Tree tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    t->hight = max(getH(t->right),getH(t->left)) + 1;
    tmp->hight = max(getH(tmp->right),t->hight) +1 ;    
    return tmp; 
}


Tree LL(Tree t)
{
    Tree tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    t->hight = max(getH(t->right),getH(t->left)) + 1;
    tmp->hight = max(getH(tmp->right),t->hight) +1 ;
    return tmp; 
}


Tree RL(Tree t)
{
    Tree tmp = t->right;
    t->right = LL(tmp);
    return RR(t);
}

Tree LR(Tree t)
{
    Tree tmp = t->left;
    t->left = RR(tmp);
    return LL(t);
}


Tree insert(Tree tree,int k)
{
    if(NULL == tree)
    {
        Tree tmp = new Node;
        tmp->k = k;
        tree = tmp;
    }
    else if(k > tree->k)
    {
        tree->right = insert(tree->right, k);
        if(getH(tree->right) - getH(tree->left) == 2)
        {
            if(k > tree->right->k)
            {
                tree = RR(tree);
            }
            else
            {
                tree = RL(tree);
            }
        }
    }
    else if(k < tree->k)
    {
        tree->left = insert(tree->left, k);
        if(getH(tree->left) - getH(tree->right) == 2)
        {
            if(k <tree->left->k)
            {
                tree = LL(tree);
            }
            else
            {
                tree = LR(tree);
            }
        }
    }
    tree->hight = max(getH(tree->right),getH(tree->left)) + 1;
    return tree;
}


int main()
{
    int num = 0;
    scanf("%d",&num);
    Tree tree = NULL;
    for(int i = 0;i<num; i++)
    {
        int k = 0;
        scanf("%d",&k);
        tree = insert(tree,k);
    }
    printf("%d",tree->k);
    return 0;
}