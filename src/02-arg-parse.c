/* macros __init, __initdata, __exit
MODULE_() */

#include <linux/kernel.h>
#include <linux/module.h>

static int __init arg_init(void) {
	return 0;
}

static void __exit arg_exit(void) {
}

module_init(arg_init);
module_exit(arg_exit);

MODULE_DESCRIPTION("Arg passig to modules.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
