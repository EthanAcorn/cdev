#ifdef __KENREL__
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/dma-mapping.h>
#include <linux/poll.h>
#include <linux/mutex.h>
#include <linux/kref.h>
#include <linux/compat.h>
#include <linux/sched.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/nospec.h>

#include <linux/uaccess.h>

#include <rdma/ib_mad.h>
#include <rdma/ib_user_mad.h>

#include <linux/module.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/mutex.h>
#include <linux/netdevice.h>
#include <linux/security.h>
#include <linux/notifier.h>
#include <rdma/rdma_netlink.h>
#include <rdma/ib_addr.h>
#include <rdma/ib_cache.h>
#endif

#ifndef CMD_HEADER
#define CMD_HEADER 1



enum CMD {
	ALLOC_PD,
	CREAT_QP,
	REGS_MR
};

struct cmd_header {
	unsigned int type;
	unsigned int opcode,cmd;
	unsigned char dir;
	unsigned int header_size, total_size;
	char *response;
	char playload[0];
};

struct param_create_qp {
	struct ibv_pd *pd;
	struct ibv_qp_init_attr *init_attr;	
};
#endif










