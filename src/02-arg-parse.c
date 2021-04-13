/* macros __init, __initdata, __exit
MODULE_() */

#include <linux/kernel.h>
#include <linux/module.h>
// #include <linux/stat.h> for macros such as S_IRWXU S_IRUSR S_IWUSR S_IXUSR
#include <linux/moduleparam.h>			// for module param types


/* int */
static int param1; 
module_param(param1, int, 0644);			// module_parama (name of var, type, permission for param)
MODULE_PARM_DESC(param1, "Int Param1");			// see /sys/module/02_arg_parse
module_param_named(paramOne, param1, int, 0);		// wont be visible in sys
MODULE_PARM_DESC(paramOne, "Int ParamOne");		// see /sys/module/02_arg_parse


/* array of ints */
static int int_arr[1];					// insmod intarr=1,2,3,4 (no spaces)
static int inp1;
module_param_array(int_arr, int, &inp1, 0444);		// mpa(pointer, type, total inputted, perm)


/* string literal */
static char *str_literal="---";
module_param(str_literal, charp, 0444);			// insmod str1="string"


/* array of strings */ 
static char *str_arr[5];					// 5 strings
static int inp2;
module_param_array(str_arr, charp, &inp2, 0444);			// insmod str2="string1","string2",...
MODULE_PARM_DESC(str_arr, "array of strings");


static int __init arg_init(void) {
	pr_info("Int: %d\n", param1);
	pr_info("int_array[2]: %d. Got: %d.\n", int_arr[0], inp1);
	pr_info("Str Literal: %s\n", str_literal);
	pr_info("str_arr[2]: %s. Got: %d.\n", str_arr[2], inp2);
	return 0;
}


static void __exit arg_exit(void) {
}

module_init(arg_init);
module_exit(arg_exit);

MODULE_DESCRIPTION("Arg passig to modules.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
