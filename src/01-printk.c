#include <linux/module.h>
#include <linux/kernel.h>

/*
 * ref: 
 * https://www.kernel.org/doc/html/latest/core-api/printk-basics.html#c.pr_emerg
 * https://www.kernel.org/doc/html/latest/core-api/printk-formats.html#printk-specifiers
 * https://www.kernel.org/doc/html/latest/core-api/printk-basics.html
 */

static int __init pk_entry(void) {
	printk(KERN_INFO "PRITNK!");

	// format: printk(LOG_LEVEL "MESSAGE %SPECIFIER", value);

	return 0;
}

static void __exit pk_exit(void) {
	printk(KERN_INFO "!KNTIRP");
}


module_init(pk_entry);
module_exit(pk_exit);

MODULE_DESCRIPTION("Learning printk.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
