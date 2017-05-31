#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static int__init  hello_init(void)
{

 printk("hello wolrd\n");
 return 0;
}

static void__exit  hello_exit(void)
{

 printk("exit\n");

}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
