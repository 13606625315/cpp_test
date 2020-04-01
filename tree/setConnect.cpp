#include <stdio.h>



typedef struct setStruct
{
    int* data;
    int size;
    int cap;
}setStruct;

typedef struct setStruct* Set;

Set createSet(int num)
{
    Set s = new setStruct;
    s->data = new int[num];
    s->size = 0;
    s->cap = num;
    for(int i = 0;i<num;i++)
    {
        s->data[i] = -1;
    }
    return s;
}

int find(Set s,int num)
{
    // int i = num;
    // for(; s->data[i] >= 0; i = s->data[i])
    // {
        
    // }
    // return  i;
    if(s->data[num] < 0)
    {
        return num;
    }
    else
    {
        return s->data[num] = find(s,s->data[num]);
    }
}


void Union(Set s,int num1 ,int num2)
{
    //s->data[num1] = num2;
    if(s->data[num1] > s->data[num2])
    {
        s->data[num1] = num2;
        s->data[num2]--;
    }
    else if(s->data[num1] <= s->data[num2])
    {
        s->data[num2] = num1;
        s->data[num1]--;
    }
}

int getComponents(Set s, int num)
{
    int max = 0;
    for(int i = 0 ; i < num;i++)
    {
        if(s->data[i] < 0)
        {
            max++;
        }
    }
    return max;
}

int main()
{
    int num = 0;
    scanf("%d\n",&num);
    Set set = createSet(num);
    char s;
    do
    {
        int num1;
        int num2;

        scanf("%c",&s);
     //   printf("s = %c\n",s);
        if(s == 'I')
        {
            scanf("%d %d\n",&num1,&num2);
            Union(set, find(set, num1-1), find(set, num2-1));
            // for(int i = 0 ; i < num;i++)
            // {
            //     printf("%d ",set->data[i]);
            // }
            // printf("\n");
        }
        else if(s == 'C')
        {
            scanf("%d %d\n",&num1,&num2);
            if(find(set, num1-1) != find(set, num2-1))
            {
                printf("no\n");
            }
            else
            {
                printf("yes\n");
            }
        }
        else 
        {
            int max = getComponents(set,num);
            if(max == 1)
            {
               printf("The network is connected.\n"); 
            }
            else
            {
                printf("There are %d components.\n",max); 
            }
        }
    }
    while(s != 'S');
    return 0;
}