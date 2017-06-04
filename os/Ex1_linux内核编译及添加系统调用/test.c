#include<stdio.h>
#include<sys/syscall.h>
#include<unistd.h>
#define xfsetnice 332
int main()
{
printf("之前：%ld\n", syscall(xfsetnice,2308,0,1));
printf("中间：%ld\n", syscall(xfsetnice,2308,1,5));
printf("之后：%ld\n", syscall(xfsetnice,2308,0,1));
}

