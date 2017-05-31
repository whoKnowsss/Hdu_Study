/*
 *@author：lxf
 *@time：2017/5/29 12:30
 *@title：os实验四第三题
 *@subject：由父进程创建一个管道，然后再创建3个子进程，
            并由这3个字进程利用管道与父进程之间进行通信：
            子进程发送消息，父进程等三个子进程全部发完消
            息后再接受信息。通信的具体内容可根据自己的需
            要随意设计，要求能试验阻塞型读写过程中的各种
            情况，并且要实现进程间对管道的互斥访问。运行
            程序，观察各种情况下，进程实际读写的字节数以
            及进程阻塞唤醒的情况。
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define size 40
int fd[2]; //fd[0]:读管道，fd[1]:写管道
//成功创建子进程，进行写操作
void WritePipe(int id){
        printf("Xf's child %d,start write!!\n",id+1);
		//子进程进行写入前先关闭读取管道
        close(fd[0]);
        char str[25];
        // itoa(id+1, str, 10);   int转字符串 linux没这个函数
        sprintf(str, "%d", id+1);     // 使用sprintf将整数转换成字符串  
        strcat(str," !!\n");    //拼接到最后
	    char mesg[100] = "this message from xf's child ";
        strcat(mesg,str);
        //write函数写入失败时返回-1，成功时返回写入的字节数
        int re = (int)write(fd[1], mesg, size);
        if(  re != -1 ){
            printf("子进程%d写入完毕,写入的字节数为%d\n",id+1,re);
        }
        else{
            printf("子程序%d写入失败\n",id);
        }
        
        exit(0);
}
int main()
{
	pid_t pid[3]; //3个子进程
	char getMesg[40];
	if(pipe(fd)<0)    //创建管道失败
		{
			//标准错误流，内核在处理stdout和stderr时优先级不一
			//样，后者的优先级要高一些，因此有时候如果程序异常退出时，
			//stderr能得到输出，而stdout就不行。
			//printf(...)实际上相当于fprintf(stdout, ...)
			//strerror(errno) 错误信息
           fprintf(stderr, "Xf's create pipe error : %s\n",strerror(errno));
		}
	if ((pid[0]=fork())<0)  //创建子进程1失败
	{
		fprintf(stderr, " Xf's Fork 1 Error : %s \n",strerror(errno) );
		//EXIT_FAILURE为1，表示没有成功地执行一个程序,
		exit(EXIT_FAILURE);
	}
	if (pid[0]==0)          //子进程1，写操作
	{
	   WritePipe(0);
	}
	else
	{
		if ((pid[1]=fork())<0)  //创建子进程2失败
	  {
		fprintf(stderr, " Xf's Fork 2 Error : %s \n",strerror(errno) );
		//EXIT_FAILURE为1，表示没有成功地执行一个程序,
		exit(EXIT_FAILURE);
	  }
	  if (pid[1]==0)
	  {
	  	WritePipe(1);    //子进程2，写操作
	  }
	  else
	  {
         if ((pid[2]=fork())<0)  //创建子进程3失败
	     {
		    fprintf(stderr, " Xf's Fork 3 Error : %s \n",strerror(errno) );
		     //EXIT_FAILURE为1，表示没有成功地执行一个程序,
		    exit(EXIT_FAILURE);
	      }
	     if (pid[2]==0)
	      {
	      	WritePipe(2);    //子进程3，写操作
	      }
	      else               //父进程
	      {
	      	wait(0);         //阻塞自己，等3个子进程完结
	      	wait(0); 
	      	wait(0); 
			//读取前关闭写入管道
            close(fd[1]);
    
            printf("xf's父进程开始读取\n");
    
             for (int i=0; i<3; i++) 
               {
                  if ( read(fd[0], getMesg, size) != -1 ) 
                     printf("%s\n",getMesg);
                  else
                     printf("读取子进程%d的失败\n",i);              
               }
			printf("-------------Xf's End of Program-----------\n");
			return 0;
	      }
	  }
	}
	return 0;
}