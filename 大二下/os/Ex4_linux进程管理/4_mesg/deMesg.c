//
//  main.c
//  deSent
//
//  Created by 费克翔 on 2017/5/16.
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
    int mesgType;
    char mesg[mesgSize];
};

struct mesgArm mesg;

//定义有名信号量，macOS不能使用无名信号量
sem_t *receivSem;
sem_t *sendSem;
sem_t *end;
int back;

void sender(){
    
    
    for (int i=0; i==0 ; ) {
        
        //若接收队列未取走消息，则等待
        sem_wait(sendSem);
        
        printf("请输入您的信息\n");
        scanf("%s",mesg.mesg);
        
        if(strcmp(mesg.mesg,"exit")==0){
            strcpy(mesg.mesg, "end");
            i = 1;
        }
        sem_post(receivSem);
    }
    
    //若返接收程序未写入消息则等待;
    sem_wait(sendSem);
    
    //正确收到返回数据则输出
    if( strcmp(mesg.mesg, "over") == 0 ){
        printf("%s\n",mesg.mesg);
    }
    else{
        printf("返回消息接收失败");
    }

    return;
}


void receiver(){

    for( int i=0 ; i == 0 ;) {
        
        //若输入线程未写入消息，则等待
        sem_wait(receivSem);
        
        printf("receiver: ");
        
        //收到end则返回over，结束程序
        if ( strcmp(mesg.mesg, "end") == 0 ) {
            
            strcpy(mesg.mesg,"over");
            i = 1;
        }
        else{
            printf("%s\n",mesg.mesg);
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

