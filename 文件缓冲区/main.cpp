#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    printf("123");

   // fsync(1);

   // sleep(10);
    close(1);    
    //fclose(stdout);
    //_Exit(0);
}

