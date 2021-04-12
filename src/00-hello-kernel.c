#include <linux/module.h>
#include <linux/kernel.h>

static int __init entry_point(void) {
	printk(KERN_INFO "Hello, kernel!\n");
	return 0;
}

static void __exit my_exit(void) {
	printk(KERN_INFO "Bye, kernel!\n");
}


module_init(entry_point);
module_exit(exit_point);

