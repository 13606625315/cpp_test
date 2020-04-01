#include<stdio.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
typedef struct Node
{
    int isRoot;
    int rightNum;
    int leftNum;
    struct Node * right;
    struct Node * left;
    int data;
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
int num1;

queue<Tree> q;
#define DEBUG1

Tree getList(int num,Tree* list)
{
#if defined DEBUG
    printf("\n num = %d\n",num);
#endif
    for(int i = 0;i < num;i++)
    {
        Tree tmp = new Node;
        char s2[2],s3[2];
        scanf("%s %s",&s2,&s3);
        string tmp2(s2),tmp3(s3);
#if defined DEBUG        
        printf("str = %s %s\n",tmp2.c_str(),tmp3.c_str());
#endif
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
        list[i]->data = i;
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
            return list[i];
        }
    }
    return NULL;

}

void level_tra(Tree tree)
{
    int flag = 0;
    q.push(tree);
    int i = 100;
    while(!q.empty() && i--)
    {
        Tree tmp = q.front();
        q.pop();
      //  printf("tm p = %d\n",tmp->data);
        if(tmp->left!=NULL)
        {
            q.push(tmp->left);
        }
        if(tmp->right!=NULL)
        {
            q.push(tmp->right);
        }
        if(tmp->left==NULL && tmp->right==NULL)
        {
            if(flag == 1)
            {
                printf(" ");
            }
            if(flag == 0)
            {
                flag =1;
            }
            printf("%d",tmp->data);
        }
    }
}

int main()
{
    memset(list1,0,sizeof(list1));

    scanf("%d",&num1);
    Tree tree1 = getList(num1,list1);
    level_tra(tree1);


    return 0;
}