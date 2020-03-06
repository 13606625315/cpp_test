#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int uuint;
typedef struct Element
{
    uuint address;
    uuint data;
    uuint next ;
}Element;
#define MAXSIZE 100000
typedef struct Node
{
    Element element[MAXSIZE];
}Node;
Element element[MAXSIZE];
typedef struct Node* List;
uuint N;
uuint K;


void printList(List list);
void getList(List list)
{
    uuint address = 0;
    scanf("%d %d %d", &address, &N, &K);

    for(int i = 0; i < N; i++)
    {   
        uuint add,data,next;
        scanf("%d %d %d",&add,&data,&next);
        element[add].address = add;
        element[add].data = data;
        element[add].next = next;
    }

    if(address == -1)
    {
        N = 0;
    }

    for(int i = 0;i < N ;i++)
    {
        list->element[i] = element[address];
        address = element[address].next;
        if(address == -1)
        {

            N = i + 1;
            break;
        }
    }
}

void dealList(List list)
{
    for(int i = 0;i < N - N%K;i = i+K )
    {
        for(int r = i ,l = i+K-1; r < l;r++,l--)
        {
            Element element = list->element[r];
            list->element[r] = list->element[l];
            list->element[l] = element;
        }
    }

    for(int i = 0; i < N-1; i++)
    {
        list->element[i].next = list->element[i+1].address;
    }    
    list->element[N-1].next = -1;
}

void printList(List list)
{
    for(int i = 0;i < N;i++)
    {
        if(list->element[i].next != -1)
            printf("%05d %d %05d\n",list->element[i].address,list->element[i].data,list->element[i].next);
        else
            printf("%05d %d %d\n",list->element[i].address,list->element[i].data,list->element[i].next);
    }
}

int main()
{
    List list;
    list = (List)malloc(sizeof(Node));    
    getList(list);
    dealList(list);
    printList(list);
    return 0;
}