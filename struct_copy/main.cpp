
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
 
 
struct String
{
    string str;
};

int main()
{
    String str1;
    str1.str = "linux_ever";
    String str2;
   // str2 = str1;
    memcpy(&str2,&str1,sizeof(String));
    cout << "\n输出两个string对象的值之后的内存地址：" << endl;
    cout << "str1 = " << str1.str << endl;
    cout << "str2 = " << str2.str << endl;
    printf("str1's address is %x\n", str1.str.c_str());
    printf("str2's address is %x\n", str2.str.c_str());
 
    cout << "\n修改了str1之后的地址：" << endl;
    str1.str[0] = 'u';
    cout << "str1 = " << str1.str << endl;
    cout << "str2 = " << str2.str << endl;
    printf("str1's address is %x\n", str1.str.c_str());
    printf("str2's address is %x\n", str2.str.c_str());
 
    cout << "\n修改了str2之后的地址：" << endl;
 
    str2.str[0] = 'w';
    cout << "str1 = " << str1.str << endl;
    cout << "str2 = " << str2.str << endl;
    printf("str1's address is %x\n", str1.str.c_str());
    printf("str2's address is %x\n", str2.str.c_str());
 
    return 0;

}