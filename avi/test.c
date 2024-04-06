#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int a=0;
	a = open("/home/zy/lv_port_linux_frame_buffer/avi/env8.avi",O_RDONLY);
	printf("%d\n",a);
	return 0;
}
