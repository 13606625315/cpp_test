#include<iostream>
#include<string>
using namespace std;
int main()
{
    char t[1000000] = {0};
    char p[1000] = {0};
    cin>>t>>p;
    string a(t);
    string b(p);
    int s= b.size();
    for(int i = 0 ; i < a.size() - b.size()+1;i++)
    {
        if(a[i] != b[0])
        {
            continue;
        }
        else
        {
            cout<<a.substr(i,s)<<endl;
            if(a.substr(i,s) == b)
            {
                cout<<i+1;
                return 0;
            }
        }
        
    }
    cout<<"No";
    return 0;
}