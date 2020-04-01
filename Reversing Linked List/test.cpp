// Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

// Input Specification:
// Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
// ​5
// ​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

// Then N lines follow, each describes a node in the format:

// Address Data Next

      
    
// where Address is the position of the node, Data is an integer, and Next is the position of the next node.

// Output Specification:
// For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

// Sample Input:
// 00100 6 4
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218

      
    
// Sample Output:
// 00000 4 33218
// 33218 3 12309
// 12309 2 00100
// 00100 1 99999
// 99999 5 68237
// 68237 6 -1
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