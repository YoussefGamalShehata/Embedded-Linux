#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int new_fd,bright_value;
	new_fd=open("/sys/class/leds/inputinput2::capslock/brightness",O_RDWR);
	printf("My new file descriptor : %d \n",new_fd);
}
