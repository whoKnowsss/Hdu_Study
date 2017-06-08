/*
 *@author：lxf
 *@time：2017/5/15 12：25
 *@title：os实验二第一题
 *@subject：设计一个模块，要求列出系统中所有内核线程
 *          的程序名、PID号、进程状态及进程优先级
 */


#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/sched.h>   //有进程描述符task_struct


static int __init xfmodule_1_init(void)
{
 
  struct task_struct *p;
  printk("Name\tPID\tState\tPrio\t\n"); 
   for_each_process(p)
{
   if(p->mm==NULL)
      printk("%s\t%d\t%ld\t%d\n",p->comm,p->pid,p->state,p->prio);
}
    
  return 0;
}


static void __exit xfmodule_1_exit(void)
{
   printk("xf's module01 exit!\n"); 
}

module_init(xfmodule_1_init);  //加载函数
module_exit(xfmodule_1_exit);  //卸载函数
MODULE_LICENSE("GPL");         //许可证声明
