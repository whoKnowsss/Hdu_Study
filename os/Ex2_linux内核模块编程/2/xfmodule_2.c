/*
 *@author：lxf
 *@time：2017/5/15 14:39
 *@title：os实验二第二题
 *@subject：设计一个带参数的模块，其参数为某个进程的PID号，
 *          该模块的功能是列出改进程的家族信息，包括父进程，
 *          兄弟进程和子进程的的程序名、PID号
 *@ps:因为带参数，加载模块时要指出参数，如 sudo insmod xfmodule_2.ko pid=xx
 */
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/sched.h>           //有进程描述符task_struct
#include<linux/moduleparam.h>     //模块带参数

static int pid;                   //参数申明

module_param(pid,int,0644);        //参数说明

MODULE_LICENSE("GPL");


static int __init xfmodule_2_init(void)
{
  struct task_struct *p;
  struct task_struct *parent;
  struct task_struct *process;
  struct list_head *list;

  printk("xf's Process Begin!\n");
  printk("Realitiont\t\tName\t\tPID\n");

   //根据pid找到进程的地址
   //p=find_task_by_vpid(pid); 这个函数现在不管用啦
   p=pid_task(find_vpid(pid),PIDTYPE_PID);

  printk("Me\t\t\t%s\t\t%d\n",p->comm,p->pid);  //输出自己的信息

  parent=p->parent;               //父进程
  //特别注意children.next指向的是sibling成员，因此在使
  //用list_entry()获得task_struct指针时，
  //参数要用sibling而不是children，更不是tasks成员
  printk("father\t\t\t%s\t\t%d\n",parent->comm,parent->pid);
  list_for_each(list,&p->children)       //~A~M~N~F~P~[~K
     {
         process=list_entry(list,struct task_struct,sibling);
         printk("Child\t\t\t%s\t\t%d\n",process->comm,process->pid);
     }
//  list= &parent->children;
  list_for_each(list,&parent->children)  //遍历parent的children，即是他的sibling
    {
       process=list_entry(list,struct task_struct,sibling);
      if(process->pid!=pid)
      printk("Brother\t\t\t%s\t\t%d\n",process->comm,process->pid);
    }

 //  list=&p->children;     //子进程
   list_for_each(list,&p->children)       //遍历子进程
     {
         process=list_entry(list,struct task_struct,sibling);
         printk("Child\t\t\t%s\t\t%d\n",process->comm,process->pid);
     }

   return 0;
}


static void __exit xfmodule_2_exit(void)
{
   printk("xf's module_2_2 exit!\n");
}

module_init(xfmodule_2_init);
module_exit(xfmodule_2_exit);