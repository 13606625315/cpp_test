#include <stdio.h>

typedef struct HeapStruct
{
    int* data;
    int size;
    int capacity;//用来判断是不是满了
}HeapStruct;

typedef struct HeapStruct* Heap;

Heap createHeap(int cap)
{
    Heap t = new HeapStruct;
    t->data = new int[cap + 1];
    t->data[0] = 0;
    t->size = 0;
    t->capacity = cap;
    return t;
}

void insert(Heap t, int key)
{

    t->size++;
    int i = t->size;
    t->data[i] = key;
    for(; t->data[i] < t->data[i/2] && i > 1;i = i/2)
    {
        int tmp = t->data[i/2];
        t->data[i/2] = t->data[i];
        t->data[i] = tmp; 
    }

}

void printPath(Heap t, int key)
{
    for(int i = key; i > 0;i = i/2)
    {
        if(i == 1)
        {
          printf("%d\n",t->data[i]);  
        }
        else
        {
            printf("%d ",t->data[i]);
        }
    }
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d",&num1);
    scanf("%d",&num2);
    
    Heap heap = createHeap(num1);

    for(int i = 0; i < num1; i++)
    {
        int key = 0;
        scanf("%d",&key);
        insert(heap,key);

    }

    for(int i = 0; i < num2;i++)
    {
        int key = 0;
        scanf("%d",&key);
        printPath(heap,key);
    }

    return 0;
}