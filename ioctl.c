#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>




static int __init verbs_ioctl_init(void) {

	int ret = 0;
	pr_info("Enter Init \n");

	return ret ;
}


static void __exit verbs_ioctl_exit(void) {


	pr_info("Exit verbs_init \n");

}




module_init(verbs_ioctl_init);
module_exit(verbs_ioctl_exit);




