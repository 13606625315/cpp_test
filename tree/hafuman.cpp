#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef struct Node
{
    bool flag;
    int w;
    Node* left;
    Node* right;
    Node(){
        w= 0;
        left = NULL;
        right = NULL;
        flag = false;
    }
}Node;


typedef struct Node* tree;

struct HNode
{
    Node* v;
    int size;
};

typedef HNode *heap;

void swap(tree n1, tree n2)
{
    int tmpw = n1->w;
    tree left = n1->left;
    tree right = n1->right;

    n1->w = n2->w;
    n1->left = n2->left;
    n1->right = n2->right;

    n2->w = tmpw;
    n2->right = right;
    n2->left = left;
}

heap createHeap(int *f,int num)
{
    heap a = new HNode;
    a->size = 0;
    a->v = new Node[num+1];
    a->v[0].w = -1;
    return a;
}

void insert(heap h,tree t)
{
    h->size++;
    int i = h->size; 
    swap(&h->v[i],t);

    for(; h->v[i].w < h->v[i/2].w;i = i/2)
    {
        swap(&h->v[i],&h->v[i/2]);
    }
}
#if 1
tree deleteMin(heap h)
{
    tree t = new Node;
    memcpy(t, &h->v[1],sizeof(Node));
    swap(&h->v[h->size],&h->v[1]);
    h->size--;
    int size = h->size; 
    for(int i = 1;i * 2<= size;)
    {   
        if( i * 2 == size )
        {
            if( h->v[i].w > h->v[i*2].w )
            {
                swap(&h->v[i],&h->v[i*2]);
                i = i * 2;
            }
            else
                break;
        }
        else if(i * 2 < size)
        {
            if(h->v[i*2].w > h->v[i*2 + 1].w)
            {
                if( h->v[i].w > h->v[i*2 +1].w )
                {                
                    swap(&h->v[i],&h->v[i*2 + 1]);
                    i = i*2 + 1;
                }
                else
                    break;
            }
            else
            {
                if( h->v[i].w > h->v[i*2].w )
                {                   
                    swap(&h->v[i],&h->v[i*2]);
                    i = i*2;
                }
                else
                    break;
            }
        }      
    }
    return t;
}
#else
tree deleteMin(heap h)
{
    tree t = new Node;
    memcpy(t, &h->v[1],sizeof(Node));
    h->size--;
    int size = h->size; 

    Node tmp = h->v[size+1];
    int c = 0;
    int i = 1;
    for(;i * 2<= size; i = c)
    {   
        c = i *2;
        if(c < size && h->v[c].w > h->v[c + 1].w)
        {
            c++;
        }

        if(tmp.w <= h->v[c].w)
        {
            break;
        }
        else
        {
           h->v[i] = h->v[c];
        }
    }
    h->v[i]=tmp;
    return t;
}
#endif
int calculate(tree t, int level)
{
    if(t->right == t->left)
    {
        return t->w * level;
    }
    else
    {
        return  calculate(t->right, level + 1) + calculate(t->left , level + 1);
    }
}

int sumW(int* f, int num)
{
    heap h = createHeap(f,num);
    for(int i= 0; i < num; i++)
    {
        tree a = new Node;
        a->w = f[i];
        insert(h , a);
    }  
    for(int i = 0 ;i < num -1;i++)
    {
        tree t = new Node;
        t->left = deleteMin(h);
        t->right = deleteMin(h);  
        t->w = t->left->w + t->right->w;              
        insert(h,t);
    }
    tree t = deleteMin(h);
    int an = calculate(t,0);
    delete[] h->v;
    return an;
}

bool insertTest(tree t , char* str)
{
    int size = strlen(str);

    for(int i = 0 ; i <size; i++)
    { 
        if(t->flag == true)
        {
            return false;
        }

        if(str[i] == '0')
        {   
            if(t->left ==  NULL)
            {
                tree tmp = new Node;
                t->left = tmp;
            }
            t=t->left;
            
        }
        else
        {
            if(t->right ==  NULL)
            {            
                tree tmp = new Node;
                t->right = tmp;
            }

            t= t->right;
            
        }

    }
    
    if(t->flag == false)
    {
        if(t->left == t->right)
        {
            t->flag = true;
            return true;
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

void freeTest(tree t)
{
    if(t == NULL)
    {
        return;
    }
    freeTest(t->right);
    freeTest(t->left);
    delete t;
    t = NULL;
}

int main()
{
    int num = 0;
    cin>>num;
    char * c = new char[num];
    int* f = new int[num]; 
    for(int i = 0; i < num; i++)
    {
        cin>>c[i];cin>>f[i];
    }

    int sum = sumW(f, num);
    int ww = 0;
    cin>>ww;
    for(int i = 0; i < ww; i++)
    {
        char tmp;
        char tmpa[1024];
        int tmpsum = 0;
        tree t = new Node;
        bool flag = true;        

        for(int j = 0; j <num ; j++)
        {
            cin>>tmp;cin>>tmpa;
            tmpsum += f[j] * strlen(tmpa);
            if(insertTest(t,tmpa) == false && flag)
            {
                flag = false;
            }
           // freeTest(t);
        }
        if(tmpsum == sum && flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }  
    }
    
    return 0;
}