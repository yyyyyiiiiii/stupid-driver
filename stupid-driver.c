#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/errno.h>

#define FIRST_MINOR 0
#define MINOR_DEV_COUNT 1
#define DEV_NAME "stupid_dev"
static dev_t stupid_dev;


static int __init stupid_init(void)
{
  int r = alloc_chrdev_region(&stupid_dev, FIRST_MINOR,
      MINOR_DEV_COUNT, DEV_NAME);
  if(r) {
    pr_err("stupid device hasn't been alloced!\n");
    return -ENOMEM;
  }
  
  pr_info("the major: %d\nthe minor: %d\n",
      MAJOR(stupid_dev), MINOR(stupid_dev));
  return 0;
}

static void __exit stupid_exit(void)
{
  unregister_chrdev_region(stupid_dev, MINOR_DEV_COUNT);
  pr_info("stupid is exited\n");
}

module_init(stupid_init);
module_exit(stupid_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yyyyyiiiiii");
