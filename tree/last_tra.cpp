#include<stdio.h>
#include<stack>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
}Node;

typedef Node* Tree;
stack<Tree> s;

Tree getTree()
{
    int num;
    scanf("%d",&num);
    Tree tree = NULL;
    Tree head_tree = NULL;
    for(int i = 0; i < 2*num; i++)
    {
        int data;
        char in[10];
        scanf("%s",&in);
        if(in[1] == 'u')
        {
            scanf("%d",&data);
            Tree tmp = new Node;
            tmp->data = data;
            s.push(tmp);
            if(tree == NULL)
            {
                tree = tmp;
                head_tree = tree;
            }
            else if(tree->left == NULL)
            {
                tree->left = tmp;
                tree = tree->left;
            }
            else if(tree->right == NULL)
            {
                tree->right = tmp;
                tree = tree->right;
            }
        }
        else
        {
            tree = s.top();
            s.pop();
        }
    
    }
    return head_tree;
}
void tra(Tree tree)
{
    if(tree == NULL)
    {
        return ;
    }
    tra(tree->left);
    tra(tree->right);
    static int a = 0;
    if(a == 0)
    {
        printf("%d",tree->data);
        a = 1;
    }
    else
    {
        printf(" %d",tree->data);
    }
}
int main()
{
    Tree tree = getTree();
    tra(tree);
    return 0;
}