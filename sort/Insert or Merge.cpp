#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
int n;
bool compare(int* in ,int* part, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(in[i] != part[i])
        {
            return false;
        }
    }
    return true;
}

void print(int *a,int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == n-1)
        {
            cout<<a[i]<<endl;
        }
        else
        {
            cout<<a[i]<<" ";
        }
    }
}

void Insertion_Sort(int* a ,int* part, int n)
{

    bool flag = false;
    for(int i = 0 ; i < n;i++)
    {
        int tmp = a[i];
        int j = i;
        for( ; j > 0 && tmp < a[j-1];j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
       // print(a, n);
        if(flag)
        {
            if(!compare(a, part, n))
            {
                cout<<"Insertion Sort"<<endl;
                print(a, n);
                flag = false;
            }
        }
        if(compare(a, part, n))
        {
            flag = true;
        }
    }
}

void Merge(int* a ,int* part, int * tmp,int s1,int s2,int e2)
{

    int s = s1;
    int x = s1;
    int e1 = s2 - 1;
    for(;s1 <= e1 && s2 <= e2; )
    {
        if(a[s1]<=a[s2])
        {
            tmp[s++] = a[s1++];
        }
        else
        {
            tmp[s++] = a[s2++];
        }
    }

    while(s1 <= e1)
    {
        tmp[s++] = a[s1++];
    }

    while(s2 <= e2)
    {
        tmp[s++] = a[s2++];
    }

    for(int i = x;i <= e2; i++)
    {
        a[i] = tmp[i];
    }

}


void Merge_Sort2(int* a ,int* part, int n)
{
    int* tmp = new int[n];
    int len = 1;
    int flag = false;
    while(len < n)
    {
        int i = 0;
        for(; i + len*2 < n; i+=len*2)//key
        {
            int s = i;
            int e = i + len * 2 - 1;
            int z = (s + e)/2 + 1;
            Merge(a, part,tmp, s, z, e);
        }

        if(i+len < n)//key
        {
            int s = i;
            int e = n -1;
            int z = i + len;
            Merge(a, part,tmp, s, z, e);
        }
        len*=2;
     //   print(a,n);
        if(flag)
        {
            if(!compare(a, part, n))
            {            
                cout<<"Merge Sort"<<endl;
                print(a, n);
                flag = false;
            }
        }

        if(compare(a, part, n))
        {
            flag = true;
        }
    }
    delete[] tmp;
}


void func(int* a,int i,int n)
{

    int parent = i;
    int child = 0;
    for( ;parent*2+1 < n ; parent = child )
    {
        child = parent*2+1;
        if(parent*2+2 < n && a[parent*2+1] < a[parent*2+2])
        {
            child++;
        }

        if(a[parent]<a[child])
        {
            swap(a[parent],a[child]);
        }
        else
        {
            break;
        }
    }
}



void Heap_Sort(int* a,int* part,int n)
{
    bool flag = false;
    for(int i = n-1;i>=0;i--)
    {
        func(a,i,n);
    }
    for(int i = n -1;i>=1;i--)
    {
        swap(a[0],a[i]);
        func(a,0,i);
        if(flag)
        {
            if(!compare(a, part, n))
            {            
                cout<<"Heap Sort"<<endl;
                print(a, n);
                flag = false;
            }
        }

        if(compare(a, part, n))
        {
            flag = true;
        }        
    }



}

int main()
{
    cin>>n;
    int *in = new int[n];
    int *part = new int[n];
    int* tmp = new int[n];

    for(int i = 0 ; i < n; i++)
    {
        cin>>in[i];
    }
    memcpy(tmp, in, n*sizeof(int));
    for(int i = 0 ; i < n; i++)
    {
        cin>>part[i];
    }
   // print(in, n);

    Insertion_Sort(in, part, n); 
   // Merge_Sort2(tmp, part, n);
    Heap_Sort(tmp, part, n);
  //  print(tmp, n);
    delete[] in;
    delete[] part;
    delete[] tmp;
    return 0;
}