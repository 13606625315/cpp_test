#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
typedef struct Node
{
    int isRoot;
    string data;
    int rightNum;
    int leftNum;
    struct Node * right;
    struct Node * left;
    Node()
    {
        rightNum = -1;
        leftNum = -1;
        isRoot = 1;
        right = NULL;
        left = NULL;
    }
}Node;

typedef Node* pNode;
typedef pNode Tree;
#define Max 100
Tree list1[Max];
Tree list2[Max];
int num1;
int num2;

#define DEBUG1

Tree getList(int num,Tree* list)
{
#if defined DEBUG
    printf("\n num = %d\n",num);
#endif
    for(int i = 0;i < num;i++)
    {
        Tree tmp = new Node;
        char s1[2],s2[2],s3[2];
        scanf("%s %s %s",&s1,&s2,&s3);
        string tmp1(s1),tmp2(s2),tmp3(s3);
#if defined DEBUG        
        printf("str = %s %s %s\n",tmp1.c_str(),tmp2.c_str(),tmp3.c_str());
#endif
        tmp->data = tmp1;
        if(tmp2 != "-")
        {
            tmp->leftNum = stoi(tmp2,0,10);
        }
        if(tmp3 != "-")
        {
            tmp->rightNum = stoi(tmp3,0,10);
        }
        list[i] = tmp;
    }
    for(int i = 0; i < num;i++)
    {
        int leftNum = list[i]->leftNum;
        int rightNum = list[i]->rightNum;
        if( leftNum != -1)
        {
            list[i]->left = list[leftNum];
            list[leftNum]->isRoot = 0;
        }
        if(rightNum != -1)
        {
            list[i]->right = list[rightNum];
            list[rightNum]->isRoot = 0;
        }
    }
    for(int i = 0; i< num;i++)
    {
        if(list[i]->isRoot == 1)
        {
#if defined DEBUG            
            printf("\n data === %s\n",list[i]->data.c_str());
#endif            
            return list[i];
        }
    }
    return NULL;

}

int compare(Tree tree1, Tree tree2)
{
    if(tree1 == NULL && tree2 == NULL )
    {
        return 1;
    }
    else if(tree1 != NULL && tree2 != NULL)
    {
        if(tree1->data == tree2->data)
        {
            int a = compare(tree1->right,tree2->right)&&compare(tree1->left,tree2->left);
            int b = compare(tree1->right,tree2->left)&&compare(tree1->left,tree2->right);
            return a || b;
        }
    }
    return 0;
}

int main()
{
    memset(list1,0,sizeof(list1));
    memset(list2,0,sizeof(list2));
    scanf("%d",&num1);
    Tree tree1 = getList(num1,list1);
    scanf("%d",&num2);
    Tree tree2 = getList(num2,list2);
    if(compare(tree1,tree2))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}