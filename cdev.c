#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>
#include <linux/cdev.h>

#define __KENREL__
#include "cmd_header.h"


#define testz(var) do{if(!var) pr_err("[%s.%d]var %s is zero",__FILE__,__LINE__,#var);return -1;}while(0)
#define testnz(var) do{if(!var) pr_err("[%s.%d]var %s is non zero",__FILE__,__LINE__,#var);return -1;}while(0)

static int  verbs_open(struct inode *node ,struct file* filep);
static long verbs_ioctl(struct file *filp, unsigned int , unsigned long args);

int major = 25;
int minor = 12;
static dev_t devno;
struct cdev cdev = { .owner = THIS_MODULE } ;

struct file_operations fops_vx = {
	.open = verbs_open,
//	.write = verbs_write,
	.compat_ioctl = verbs_ioctl,
	.unlocked_ioctl = verbs_ioctl
};

struct class  *verbs_class;


//	ret = register_chrdev_region(devno, 1 , "verbsX");

static int __init char_device_init(void){

	int ret = 0;
	struct device *dev = NULL;
	pr_info("cdev init \n");
	verbs_class = class_create(THIS_MODULE , "verbs_controller");
	alloc_chrdev_region( &devno, minor , 1 , "verbsxx");
//	if (!verbs_class) return ret;
	testz(verbs_class);

	major = MAJOR(devno);
	
	pr_info("major %d \n",major);
	
		
//	device_initialize(dev);
	ret = cdev_add(&cdev, devno ,1);	
//	ret = cdev_device_add(&cdev , dev);
	testnz(ret);

	dev = device_create(verbs_class, NULL ,devno , NULL , "verbsxx%d" ,12 );
	testz(dev);	

	cdev_init(&cdev , &fops_vx);
	return 0;
}


static void __exit cdev_exit(void){

	
	pr_info("cdev exit");
	cdev_del(&cdev);
	unregister_chrdev_region(devno , 1 );
	
}


static int verbs_open(struct inode *inode, struct file *filp){
	
	pr_info("verbs open");
	dump_stack();
	return 0;
}

static long verbs_ioctl(struct file *filp, unsigned int cmd, unsigned long args){

	dump_stack();
	int n;
	struct param_create_qp *qp = NULL;
	struct cmd_header *cmd_hdr = NULL;
	void *buffer = kmalloc(126,GFP_KERNEL);
	if(!buffer) return -12;
	memset(buffer , 0 ,sizeof buffer);
	pr_info("%d %d \n",cmd,CREAT_QP);
	switch(cmd) {
		case ALLOC_PD:
			pr_info("ALLOC_PD\n"); 
			break;	
		case CREAT_QP:
			n = copy_from_user(buffer,args,sizeof(struct cmd_header) + sizeof(struct param_create_qp));
			cmd_hdr = (struct cmd_header *)buffer;
			pr_info("copy counts %d type %d header_size %d total_size %d \n",n, cmd_hdr->type , cmd_hdr->header_size , cmd_hdr->total_size);
			struct	cmd_header *cmdhdr = (struct cmd_header *)buffer;
			qp = (struct param_create_qp *)cmdhdr->playload;
			pr_info("qp %p \n",qp);
			break;
		case REGS_MR:
			pr_info("REGS_MR\n");
			break;

	}

	return 0;
}


module_init(char_device_init);
module_exit(cdev_exit);
MODULE_LICENSE("GPL");


