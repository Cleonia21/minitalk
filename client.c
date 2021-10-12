#include "libs.h"

int main(int argc, char **argv)
{
	int serv_pid;
	char *str;

	serv_pid = ft_atoi(argv[1]);
	str = argv[2];

	while (*str)
	{
		if (*str == '0')
			kill(serv_pid, SIGUSR1);
		if (*str == '1')
			kill(serv_pid, SIGUSR2);
		str++;
		usleep(1);
	}
	//printf("server pid: {%i}\n", serv_pid);
}