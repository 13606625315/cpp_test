#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
void maopao(int* a, int n);
void cha_ru(int* a, int n);
void shell(int* a, int n);
void xuan_zhe(int *a, int n);
void dui(int * a, int n);
void gui_bin(int * a, int n);
void gui_bin2(int * a, int n);
int main()
{
    int N;
    cin>>N;
    int* a = new int[N];
    for(int i = 0;i < N; i++)
    {
        cin>>a[i];
    }
    gui_bin(a,N);
    for(int i = 0;i < N; i++)
    {
        if(i == N-1)
        {
            cout<<a[i];
            break;
        }
        cout<<a[i]<<" ";
    } 
    delete[] a;
    return 0;
}

void maopao(int* a, int n)
{
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

void cha_ru(int*a ,int n)
{
    int tmp;
    for(int i = 1 ; i < n; i++)
    {
        tmp = a[i];
        int j;
        for(j = i; j > 0 && tmp < a[j-1];j--)
        {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }

}

void shell(int *a, int n)
{
    for(int m = n/2 ; m > 0; m /= 2)
    {
        // for(int i = m; i < n; i++)
        // {
        //     int tmp = a[i];
        //     int j;
        //     for( j = i ; j - m >= 0 && tmp < a[j-m]; j -= m)
        //     {
        //         a[j] = a[j-m];
        //     }
        //     a[j] = tmp;
        // }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= i - m; j += m  )
            {
                if(a[j]>a[j+m])
                {
                    swap(a[j], a[j+m]);
                }
            }
        }
    }
}

int getMin(int x ,int * a, int n)
{
    int pos = -1;
    int min = a[x];
    for(int i = x; i < n; i ++)
    {
        if(a[i] < min)
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}


void xuan_zhe(int *a, int n)
{
    int min = 0;
    int pos = 0;

    for(int i = 0 ; i < n; i++)
    {
        int pos = getMin(i, a, n);
        if(pos >= 0)
            swap(a[i], a[pos]);
    }
}


void change_dui(int *a,int n, int i)
{
    for(int parent = i;parent <=n - 1 &&parent*2+1<=n-1 ;)
    {
        int child = parent*2 + 1;
        if(parent*2+2<=n-1 && a[parent*2+2]>a[parent*2+1])
        {
            child++;
        }
        if(a[child]>a[parent])
        {
            swap(a[child],a[parent]);
        }
        parent = child;
    }
}

void create_dui(int *a,int n)
{
    for(int i = n - 1;i>= 0;i--)
    {
        change_dui(a, n, i);
    }
    // for(int i = 0 ; i < n; i++)
    // {
    //     cout<<a[i]<<endl;
    // }
}

void dui(int * a, int n)
{
    create_dui(a, n);    
    for(int i = 0; i < n;i++)
    {
        change_dui(a, n - i, 0);
        swap(a[0],a[n - i-1]);
    }
    
}



void merge(int* a,int * tmp,int s1,int s2, int e2)
{
    int e1 = s2-1;
    int p = s1;

    int p2 = s1;    

    while(s1<=e1 && s2 <=e2)
    {
        if(a[s1]<=a[s2])
        {
            tmp[p++] = a[s1++];
        }
        else
        {
            tmp[p++] = a[s2++];
        }
    }

    while(s1<=e1)
    {
        tmp[p++] = a[s1++];
    }

    while(s2<=e2)
    {
        tmp[p++] = a[s2++];
    }

    for(int i = p2;i <= e2; i++)
    {
        a[i] = tmp[i];
    }
}

void gui_bin_sort(int *a,int *tmp, int s, int e)
{

    if(s < e) 
    {
        int c = (e+s)/2;
        int s1 = s;
        int e1 = c;
        int s2 = c + 1;
        int e2 = e;
        gui_bin_sort(a,tmp,s1,e1);
        gui_bin_sort(a,tmp,s2,e2);
        merge(a,tmp,s,s2,e);

    }
}

void gui_bin(int *a,int n)
{
    int* tmp = new int[n];
    gui_bin_sort(a,tmp,0,n-1);
    delete[] tmp;
}


void gui_bin2(int *a,int n)
{
    int len = 1;
    int* tmp = new int[n];
    while(len<n)
    {
        int i = 0;
        for(; i + len*2 <= n ; i += len*2)
        {
            int s1 = i;
            int e2 = i+len*2 -1;        
            int s2 = (s1+e2)/2+1;
            merge(a,tmp,s1,s2,e2);
        //    cout<< s1 << " "<<e2<< " ";
        }

        if( i + len  < n)
        {
            int s1 =i;
            int e2 = n-1;
            int s2 = i + len;
            merge(a,tmp,s1,s2,e2);
       //     cout<< s1 << " "<<e2<< " ";      
        }

    //    cout<<len<<endl;        
        len *= 2;

    }

    delete[] tmp;
}