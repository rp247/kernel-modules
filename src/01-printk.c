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
 *
 * KERN_EMERG		:	pr_emerg()	: 	"0"
 * KERN_ALERT		:	pr_alert()	:	"1"
 * KERN_CRIT		:	pr_crit()	:	"2"
 * KERN_ERR		:	pr_err()	:	"3"
 * KERN_WARNING		:	pr_warn()	:	"4"
 * KERN_NOTICE		:	pr_notice()	:	"5"
 * KERN_INFO		:	pr_info()	:	"6"
 * KERN_DEBUG		:	pr_debug()	:	"7"
 *
 */


/*
 * specifiers
 *
 * unsigned char           %u	,  %x
 * short int               %d	,  %x
 * unsigned short int      %u	,  %x
 * int                     %d	,  %x
 * unsigned int            %u	,  %x
 * long                    %ld	,  %lx
 * unsigned long           %lu	,  %lx
 * long long               %lld	,  %llx
 * unsigned long long      %llu	,  %llx
 * size_t                  %zu	,  %zx
 * ssize_t                 %zd	,  %zx
 * s8                      %d	,  %x
 * u8                      %u	,  %x
 * s16                     %d	,  %x
 * u16                     %u	,  %x
 * s32                     %d	,  %x
 * u32                     %u  	,  %x
 * s64                     %lld	,  %llx
 * u64                     %llu	,  %llx
 *
 */


// format: printk(LOG_LEVEL "MESSAGE %SPECIFIER", value);

static int __init pk_entry(void) {
	printk(KERN_INFO "----PRINTK!----\n");

	printk(KERN_EMERG "Emergency!! (%s)\n", KERN_EMERG); 
	pr_alert("ALERT!!\n");
	pr_crit("Critical %d\n", 34);
	printk(KERN_ERR "ERR!! (%s)\n", KERN_ERR); 
	pr_warn("Just a Warning...\n");
	pr_notice("NOTICE\n");
	pr_info("info about kolonel\n");
	pr_debug("kdb to the rescure\n");

	return 0;
}

static void __exit pk_exit(void) {
	printk(KERN_INFO "----!KNTIRP----\n");
}


module_init(pk_entry);
module_exit(pk_exit);

MODULE_DESCRIPTION("Learning printk.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
