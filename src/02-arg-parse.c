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
static int inp;
module_param_array(int_arr, int, &inp, 0444);		// mpa(pointer, type, total inputted, perm)

/* string literal */
static char *str1="---";
module_param(str1, charp, 0444);			// insmod str1="string"

/* array of chars /
static char str1[] = "str1";
module_param_string(sturrig, str1, 5, 0444);		// 
MODULE_PARM_DESC(str1, "array");
*/

static int __init arg_init(void) {
	pr_info("Param1: %d\n", param1);
	pr_info("int_array[2]: %d. Got: %d.\n", int_arr[0], inp);
	pr_info("Str1: %s\n", str1);
	return 0;
}


static void __exit arg_exit(void) {
}

module_init(arg_init);
module_exit(arg_exit);

MODULE_DESCRIPTION("Arg passig to modules.");
MODULE_AUTHOR("Ruchit Patel");
MODULE_LICENSE("GPL");
