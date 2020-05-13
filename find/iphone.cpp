#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;
unordered_map<string, int> mmp;


struct CmpByKeyLength {  
  bool operator()(const string& k1, const string& k2) {  
    return k1 < k2;  
  }  
}; 


int main()
{
  int max1 = 0;
  int n = 0;
  cin>>n;
 // cout<<n<<endl;
  for(int i = 0 ; i < n; i++)
  {
    char num1[12] = {0};
    char num2[12] = {0};
    scanf("%s %s",num1,num2);
 //   printf("%d, %s %s\n",i,num1,num2);
    string str1(num1);
    string str2(num2);
    mmp[str1]++;
    mmp[str2]++;
    max1 = max(max1,max(mmp[str1],mmp[str2]));
  }
  map<string, int, CmpByKeyLength> wwp;
  for(auto&it:mmp)
  {
   if(it.second == max1)
   {
     wwp[it.first] = max1;
   }
  }
 //sort(wwp.begin(),wwp.end(),cmp);
  if(wwp.size()>1)
  {
       cout<<wwp.begin()->first<<" "<<max1<<" "<<wwp.size()<<endl;
  }
  else
  {
    	    cout<<wwp.begin()->first<<" "<<max1<<endl;
  }

 // cout<<max1;
  return 0;
}

