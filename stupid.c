#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/cdev.h>

#define FIRST_MINOR 0
#define MINOR_DEV_COUNT 4
#define DEV_NAME "stupid"
static dev_t stupid;
static struct cdev stupid_cdev;

static int dev_open(struct inode *inode, struct file *file)
{
  pr_err("open isn't implemented yet!\n");
  return 0;
}

static int dev_release(struct inode *inode, struct file *file)
{
  pr_err("release isn't implemented yet!\n");
  return 0;
}

static ssize_t dev_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
  pr_err("read isn't implemented yet!\n");
  return 0;
}

static ssize_t dev_write(struct file *filp, const char __user *buf, size_t len, loff_t *off) {
  pr_err("write isn't implemented yet\n");
  return len;
}

static struct file_operations stupid_fops = {
  .owner = THIS_MODULE,
  .read = dev_read,
  .write = dev_write,
  .open = dev_open,
  .release = dev_release,
};

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

  cdev_init(&stupid_cdev, &stupid_fops);
  cdev_add(&stupid_cdev, stupid, MINOR_DEV_COUNT);
  return 0;
}

static void __exit stupid_exit(void)
{
  cdev_del(&stupid_cdev);
  unregister_chrdev_region(stupid, MINOR_DEV_COUNT);
  pr_info("stupid is exited\n");
}

module_init(stupid_init);
module_exit(stupid_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yyyyyiiiiii");
