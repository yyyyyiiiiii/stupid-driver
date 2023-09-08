#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int __init stupid_driver_init(void)
{
  pr_info("stupid driver is inited\n");
  return 0;
}

static void __exit stupid_driver_exit(void)
{
  pr_info("stupid driver is exited\n");
}

module_init(stupid_driver_init);
module_exit(stupid_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yyyyyiiiiii");
