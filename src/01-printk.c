#include <linux/module.h>
#include <linux/kernel.h>

/*
 * ref: 
 * https://www.kernel.org/doc/html/latest/core-api/printk-basics.html#c.pr_emerg
 * https://www.kernel.org/doc/html/latest/core-api/printk-formats.html#printk-specifiers
 * https://www.kernel.org/doc/html/latest/core-api/printk-basics.html
 */


/* 
 * log levels and macros
 * KERN_EMERG		:	pr_emerg()	: 	"0"
 * KERN_ALERT		:	pr_alert()	:	"1"
 * KERN_CRIT		:	pr_crit()	:	"2"
 * KERN_ERR		:	pr_err()	:	"3"
 * KERN_WARNING		:	pr_warn()	:	"4"
 * KERN_NOTICE		:	pr_notice()	:	"5"
 * KERN_INFO		:	pr_info()	:	"6"
 * KERN_DEBUG		:	pr_debug()	:	"7"
 */


static int __init pk_entry(void) {
	printk(KERN_EMERG "Emergency!! (%s)\n", KERN_EMERG); 

	// format: printk(LOG_LEVEL "MESSAGE %SPECIFIER", value);

	return 0;
}

static void __exit pk_exit(void) {
	printk(KERN_INFO "!KNTIRP\n");
}


module_init(pk_entry);
module_exit(pk_exit);

MODULE_DESCRIPTION("Learning printk.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
