#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main()
{
  int pid = 0;
  int fd[2];
  const char* p = "123123123";
  if(pipe(fd) == -1)
  {
    perror("error!\n");
  }

  char buf[1024] = {0};

  pid = fork();

  if(pid == 0)
  {
    int len = read(fd[0],buf, sizeof(buf));
    write(STDOUT_FILENO, buf, len);
  }
  else 
  {
    write(fd[1],p, strlen(p));
    wait(0);
  }

}