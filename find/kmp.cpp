#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
char str[1000001];
char pat[100001];
int n;


// void getMatch(vector<int>& match)
// {
//     for(int i = 1 ; i <match.size(); i ++)
//     {
//         if(match[i-1] >= 0)
//         {
//             if(str[i] == str[match[i-1]+1] )
//             {
//                 match[i] = match[i-1]+1;
//             }
//         }
//     }

// }

void BuildMatch( char *pattern, vector<int>& match )
{
    int i, j;
    int m = strlen(pattern);
    match[0] = -1;
     
    for ( j=1; j<m; j++ ) {
        i = match[j-1];
        while ( (i>=0) && (pattern[i+1]!=pattern[j]) )
            i = match[i];
        if ( pattern[i+1]==pattern[j] )
             match[j] = i+1;
        else match[j] = -1;
    }
}
 

char* kmp(char* str,char* pat)
{
    int n = strlen(str);
    int m = strlen(pat);
    if ( n < m ) 
        return NULL;

    vector<int> match(m,-1);
    BuildMatch(pat, match);

    int i = 0;
    int j = 0;
    while(i < n && j< m)
    {
        if(str[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j>0)
                j = match[j-1] + 1;
            else
                i++;

        }
    }

    if(j == m)
    {
        return str + i - j;
    }
    else
    {
        return NULL;
    }
    
}









int main()
{
  cin>>str>>n;
  for(int i =0 ; i < n; i++)
  {
    memset(pat,0,sizeof(pat));
    cin>>pat;
  //  cout<<"  "<<pat<<endl;
    int len = strlen(pat);
    char* re = kmp(str, pat);
    if(re == NULL)
    {
      cout<<"Not Found"<<endl;
    }
    else
    {
      cout<<re<<endl;
    }
  }
  
  
  
  return 0;
}