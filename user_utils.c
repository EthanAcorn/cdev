#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 			// FOR write
#include <sys/ioctl.h> 			// FOR ioctl

#include "cmd_header.h"
#define CHRDEV "/dev/verbsxx12"

struct cmd_header *cmdhdr;
struct param_create_qp *para_create_qp = NULL;
int main(){

	int fd ,ret; 
	char buf[45];
	memset(buf , 0 ,sizeof buf);

	cmdhdr = (struct cmd_header *)malloc(sizeof(struct param_create_qp) + sizeof( struct cmd_header));
	if(!cmdhdr) { perror("malloc");return -1;}
	cmdhdr->header_size = sizeof(struct cmd_header);
	cmdhdr->total_size = sizeof(struct param_create_qp) + sizeof( struct cmd_header);

	memset(cmdhdr, 0 ,sizeof cmdhdr);
	fd = open(CHRDEV,O_RDWR,0666);
	if(fd < 0) { sprintf(buf , "open failed ,fd %d \n",fd); write(1,buf,45 ) ; return -12;}

	cmdhdr->type = CREAT_QP;
	para_create_qp  = (struct param_create_qp *)cmdhdr->playload ;	
	ret = ioctl(fd , cmdhdr->type , cmdhdr);
	perror("sys/ioctl.h:");
	printf("para_cerate_qp %p %p \n",para_create_qp,&para_create_qp);
	return ret;
}







