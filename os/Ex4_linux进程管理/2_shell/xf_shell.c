#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#define cmdWrong -1
#define cmdExit 0
#define cmdCMD1 1
#define cmdCMD2 2
#define cmdCMD3 3
char *shellCommand[]={"exit","cmd1","cmd2","cmd3"};


//获得输入并返回指令
int getInput()
{
  char *in;
  int i;
  scanf("%s",in);
  for(i=0;i<4;i++)
   {
      if(strcmp(in,shellCommand[i])==0)
          return i;
   }
   return -1;
}

//创建子进程，运行程序
void cmdFork(int i)
  {
     pid_t pid;
     if((pid=fork())<0)
       {
          printf("Error:fork error! xf's shell end!\n");
          exit(0);
       }
     else if(pid==0)
       {
         int execl_status=-1;
         printf("Note:child is running!\n");
         switch(i)
            {
              case cmdCMD1:
                   execl_status=execl("./cmd1","cmd1",NULL);
                   break;
              case cmdCMD2:
                   execl_status=execl("./cmd2","cmd2",NULL);
                   break;
              case cmdCMD3:
                   execl_status=execl("./cmd3","cmd3",NULL);
                   break;
              default:
                   printf("Command not found!\n");
                   break;
            }
         if (execl_status<0)
            {
                printf("Error:fork error! xf's shell end!\n");
                exit(0);
            }
            printf("child is running!");
            exit(0);
       }
      
  }

//对输入的指令进行判断，执行相应步骤
void runCmd(int i)
{
  switch(i)
   {
     case cmdWrong: 
       printf("Command not found!\n");
       break;
     case cmdExit:
       printf("xf's shell end!\n");
       exit(0);
       break;
     default:
       cmdFork(i);
       break;
   }
}
int main()
{
  int command;
  printf("xf's shell start!\n");
  printf("please input your command(cmd1/cmd2/cmd3/exit)\n");
  while(1)
  {
    command=getInput();
    runCmd(command); 
    wait(0);  //父进程要等到子进程结束，才接收下一条命令
    printf("wait for another command!\n"); 
 }
  return 0;
}
