//
//  main.c
//  deSent2
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

#define mesgSize 30

int mesgId;

//定义消息缓冲区
struct mesgArm{
    long int mesgType;
    char mesg[mesgSize];
};

struct mesgArm mesg;

//定义有名信号量，macOS不能使用无名信号量
sem_t *receivSem;
sem_t *sendSem;

int back;

void sender(){
    
    struct mesgArm sendMesg;
    sendMesg.mesgType = 1;
    
    for (int i=0; i==0 ; ) {
        
        //若接收队列未取走消息，则等待
        sem_wait(sendSem);
        
        printf("请输入您的信息:");
        scanf("%s",sendMesg.mesg);
        if ( strcmp(sendMesg.mesg,"exit") == 0 ) {
            strcpy(sendMesg.mesg, "end");
            i = 1;
        }
        if( msgsnd(mesgId, &sendMesg, sizeof(struct mesgArm), 0) == 0){
            sem_post(receivSem);
        }
        else{
            printf("信息发送失败\n");
        }
        
    }
    
    //若返接收程序未写入消息则等待;
    sem_wait(sendSem);
    
    //正确收到返回数据则输出
    if ( msgrcv(mesgId, &sendMesg, sizeof(struct mesgArm), 0, 0) == -1 ) {
            printf("返回消息接收失败\n");
    }
    else{
        if( strcmp(sendMesg.mesg, "over") == 0 ){
            printf("%s\n",sendMesg.mesg);
            printf("返回消息接收完毕\n");
        }

    }

    return;
}


void receiver(){
    
    struct mesgArm recvMesg;
    recvMesg.mesgType = 1;
    
    for( int i=0 ; i == 0 ;) {
        
        //若输入线程未写入消息，则等待
        sem_wait(receivSem);
        
        if ( msgrcv(mesgId, &recvMesg, sizeof(struct mesgArm), 0, 0) == -1) {
            printf("消息接收失败\n");
        }
        //成功接收消息
        else{
            
            if ( strcmp(recvMesg.mesg, "end") == 0 ) {
                strcpy(recvMesg.mesg,"over");
                if (msgsnd(mesgId, &recvMesg, sizeof(struct mesgArm), 0) != 0) {
                    printf("返回消息发送失败\n");
                }
                i = 1;
            }
            else{
                printf("receiver :%s\n",recvMesg.mesg);
            }
            //收到end则返回over，结束程序;
            
        }
        sem_post(sendSem);
    }
    
    return;
}


int main(int argc, const char * argv[]) {
    
    
    sem_unlink("send");
    sem_unlink("reciev");
    
    pthread_t senderId,receiverId;
    
    sendSem = sem_open("send", O_CREAT,0611,1);
    receivSem = sem_open("reciev",O_CREAT,0611,0);
    
    mesgId = msgget((key_t)2582, 0666 | IPC_CREAT);
    
    
    if ( pthread_create(&senderId, NULL, (void *)sender, NULL) != 0){
        printf("创建进程sender失败\n");
    }
    
    if ( pthread_create(&receiverId, NULL, (void *)receiver, NULL) != 0){
        printf("创建进程receiver失败\n");
    }
    
    //等待子进程结束
    pthread_join(senderId, NULL);
    pthread_join(receiverId, NULL);
    
    
    printf("程序完成，退出\n");
    return 0;
}

