//
//  main.c
//  deSharedMemory
//
//  Created by 费克翔 on 2017/5/17.
//  Copyright © 2017年 Crazzy. All rights reserved.
//



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>

#define mesgSize 30

pid_t chilId;

int shId;

int paSmId;
int chSmId;





//定义消息缓冲区
typedef struct mesgArm{
    long int mesgType;
    char mesg[mesgSize];
}mesg;

//定义有名信号量，macOS不能使用无名信号


int main(int argc, const char * argv[]) {
    
    sem_t *receivSem;
    sem_t *sendSem;

    //定义有名信号量
    sendSem = sem_open("send", O_EXCL,0611,1);
    receivSem = sem_open("reciev",O_EXCL,0611,0);
    

    //创建共享内存
    void *parentMen = NULL;
    mesg *receivMesg = NULL;
    paSmId = shmget((key_t)2582, sizeof(mesg), IPC_CREAT);
    if(paSmId==-1){
        printf("共享内存请求失败\n");
    }
    else{
    //    printf("%d",paSmId);
    }
    
    parentMen = shmat(paSmId, NULL, 0);
    if (parentMen == (void *)-1) {
        printf("链接失败\n");
        perror("shmat");
    }

    receivMesg = (mesg *)parentMen;
    
    sem_wait(receivSem);
    
    printf("receiver :%s\n",receivMesg->mesg);
    
    strcpy( receivMesg->mesg, "over");
    
    sem_post(sendSem);

    shmctl(paSmId,IPC_RMID,0);

    printf("程序完成，退出\n");
    return 0;
}

