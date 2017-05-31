//
//  main.c
//  deShm2
//
//  Created by 费克翔 on 2017/5/18.
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

int chSmId;

typedef struct mesgArm{
    long int mesgType;
    char mesg[mesgSize];
}mesg;

int main(int argc, const char * argv[]) {

    sem_unlink("send");
    sem_unlink("reciev");
    
    sem_t *receivSem;
    sem_t *sendSem;
    
    //定义有名信号量
    sendSem = sem_open("send", O_CREAT,0611,1);
    receivSem = sem_open("reciev",O_CREAT,0611,0);
    
    chSmId = shmget((key_t)2582, sizeof(mesg), IPC_CREAT);
    if(chSmId==-1){
        printf("共享内存请求失败\n");
    }
    else{
//        printf("%d",chSmId);
    }
    
    void *childMen = NULL;
    mesg *sendMesg = NULL;

    childMen = shmat(chSmId, NULL, 0);
    if (childMen == (void *)-1) {
        printf("链接失败\n");
    }
    sendMesg = (mesg *)childMen;
    
    //若接收队列未取走消息，则等待
    sem_wait(sendSem);
    
    printf("请输入您的信息:");
    
    scanf("%s",sendMesg->mesg);
    
    sem_post(receivSem);
    
    sem_wait(sendSem);

    printf("收到返回信息 ：%s\n",sendMesg->mesg);
    
    shmctl(chSmId,IPC_RMID,0);
    
    return 0;
}

