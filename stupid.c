#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/errno.h>

#define FIRST_MINOR 0
#define MINOR_DEV_COUNT 4
#define DEV_NAME "stupid"
static dev_t stupid;

static int __init stupid_init(void)
{
  int r = alloc_chrdev_region(&stupid, FIRST_MINOR,
      MINOR_DEV_COUNT, DEV_NAME);
  if(r) {
    pr_err("stupid device hasn't been alloced!\n");
    return -ENODEV;
  }
  
  pr_info("the major: %d\nthe minor: %d\n",
      MAJOR(stupid), MINOR(stupid));
  return 0;
}

static void __exit stupid_exit(void)
{
  unregister_chrdev_region(stupid, MINOR_DEV_COUNT);
  pr_info("stupid is exited\n");
}

module_init(stupid_init);
module_exit(stupid_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yyyyyiiiiii");
