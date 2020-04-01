#include <stdio.h>
int a[1000];
int b[1000];
int main()
{
   int size = 0;
   int len = 0;
   int num = 0;
   scanf("%d %d %d",&size, &len,&num);
   for(int i = 0;i < num; i++)
   {
       for(int j = 0; j < len; j++)
       {
           scanf("%d",&a[j]);
       }

       for(int j = 0; j < len; j++)
       {
            if(a[j] - j > size)
            {
                b[i] = -1;
                break;
            }
            if(b[i] == -1)
            {
                break;
            }

            int key = 10001;
            for(int k = j + 1 ;k<len;k++)
            {
                if(a[k]<a[j])
                {
                    if(a[k]>key)
                    {
                        b[i] = -1;
                        break;
                    }
                    else
                    {
                        key = a[k];
                    }
                }
            }
       }
   }

   for(int i = 0; i<num;i++)
   {
       if(b[i] == -1)
       {
           printf("NO\n");
       }
       else
       {
           printf("YES\n");
       }
       
   }
}