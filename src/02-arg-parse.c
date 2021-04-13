/* macros __init, __initdata, __exit
MODULE_() */

#include <linux/kernel.h>
#include <linux/module.h>
// #include <linux/stat.h> for macros such as S_IRWXU S_IRUSR S_IWUSR S_IXUSR
#include <linux/moduleparam.h>			// for module param types

/* int */
static int  param1; 
module_param(param1, int, 0644);			// module_parama (name of var, type, permission for param)
MODULE_PARM_DESC(param1, "Int Param1");			// see /sys/module/02_arg_parse
module_param_named(paramOne, param1, int, 0);		// wont be visible in sys
MODULE_PARM_DESC(paramOne, "Int ParamOne");		// see /sys/module/02_arg_parse

/* string literal */
static char *str1;
module_param(str1, charp, 0444);

/* array of chars /
static char str1[] = "str1";
module_param_string(sturrig, str1, 5, 0444);		// 
MODULE_PARM_DESC(str1, "array");
*/

static int __init arg_init(void) {
	pr_info("Param1: %d\n", param1);
	pr_info("Str1[2]: %s\n", str1);
	return 0;
}


static void __exit arg_exit(void) {
}

module_init(arg_init);
module_exit(arg_exit);

MODULE_DESCRIPTION("Arg passig to modules.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
