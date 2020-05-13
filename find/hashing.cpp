#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<math.h>
using namespace std;
unordered_set<int> ss;

int hash1(int num,int size)
{
  return num%size;
}

int getPrime(int size)
{

  if(size<2)
  {
      return 2;
  }

  int tmp = size%2 == 0?size+1:size;
  while(1)
  {
    for(int i = sqrt(tmp);i >= 2;i--)
    {
      if(tmp%i == 0)
      {
        break;
      }
      if( i == 2)
      {
        return tmp;
      }
    }
    tmp = tmp+2;
  }
  
}

int main()
{
  int size = 0;
  int n = 0;
  cin>>size>>n;
  size = getPrime(size);
//  cout<<endl<< size<<endl;
  for(int i = 0;i<n;i++)
  {
    int num;
    cin>>num;
    num = hash1(num, size);

    bool flag = false;
    int pos = 0;
    for(int i = 0; i < size/2; i++)
    {
        pos = hash1(num + i * i, size);
        if(ss.find(pos) == ss.end())
        {
            ss.insert(pos);
            cout<<pos;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout<<"-";
    }

    if(i != n-1)
     	cout<<" ";
  }
  
  
  return 0;
}