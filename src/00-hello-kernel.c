#include <linux/module.h>
#include <linux/kernel.h>

/* used to gather info mostly */
static int __init entry_point(void) {				// __init macro (see 03-macros)
	printk(KERN_INFO "Hello, kernel!\n");			// no glibc in kernel
	return 0;
}

/* time to clean up memory */
static void __exit exit_point(void) {				// __exit macro
	printk(KERN_INFO "Bye, kernel!\n");			// KERN_INFO: macro for msg level
}

module_init(entry_point);					// macro for entry point
module_exit(exit_point);					// macro for exit point

MODULE_DESCRIPTION("Hello, Kernel Module.");			// macros to license modules (see module.h)
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");

// continue: messing around with the program (check priv level)
// understand make more in detail (all files created by it)
// use modinfo with this
