#include <linux/module.h>
#include <linux/kernel.h>

static int __init entry_point(void) {
	printk(KERN_INFO "Hello, kernel!\n");
	return 0;
}

static void __exit exit_point(void) {
	printk(KERN_INFO "Bye, kernel!\n");
}

module_init(entry_point);
module_exit(exit_point);

MODULE_DESCRIPTION("Hello, Kernel Module.");			// explore this functions
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");

// continue: messing around with the program (check priv level)
// understand make more in detail (all files created by it)
// use modinfo with this
