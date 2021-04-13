/* macros __init, __initdata, __exit
MODULE_() */

#include <linux/kernel.h>
#include <linux/module.h>
// #include <linux/stat.h> for macros such as S_IRWXU S_IRUSR S_IWUSR S_IXUSR
#include <linux/moduleparam.h>			// for module param types

static int  param1; 
module_param(param1, int, 0644);			// module_parama (name of var, type, permissions for /sys/mod/mod)
MODULE_PARM_DESC(param1, "Int Param1");			// see /sys/module/02_arg_parse
module_param_named(paramOne, param1, int, 0);
MODULE_PARM_DESC(paramOne, "Int ParamOne");		// see /sys/module/02_arg_parse

// static char *str = "str1";

static int __init arg_init(void) {
	pr_info("Param1: %d\n", param1);
	return 0;
}

static void __exit arg_exit(void) {
}

module_init(arg_init);
module_exit(arg_exit);

MODULE_DESCRIPTION("Arg passig to modules.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
