
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	//用读写追加方式打开一个已经存在的文件
	int fd=open(argv[1],O_RDWR);
	if(fd==-1)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{

		//打印文件描述符号
		printf("success fd = %d\n",fd);
		char buf[5*1024*1000];
		memset(buf,0,sizeof(buf));
     //	memset(buf + 4*1024,1,sizeof(buf));   
		strcpy(buf,"hello world\n");
    	strcpy(buf + 5*1024*1000 - 10,"hello world\n");
		write(fd,buf,sizeof(buf));     
	//	memset(0,0,sizeof(buf));           
     //   fsync(fd);

       //_Exit(0);
        sleep(10)      ; //证明write写到内核，和内核写到disk是异步的。
       close(fd);
      

	}
	return 0;
}