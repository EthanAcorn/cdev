
KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build

CONFIG_VERBS_IOCTL=m
obj-$(CONFIG_VERBS_IOCTL):= cdev_init.o verbs_ioctl.o verbs_cmd.o

verbs_ioctl-y:= ioctl.o
verbs_cmd-y:= cmd.o
cdev_init-y:= cdev.o



modules:
	make -C ${KERNEL_DIR} M=$(PWD) modules
clean:	
	make -C ${KERNEL_DIR} M=$(PWD) clean










