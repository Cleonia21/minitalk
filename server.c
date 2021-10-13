#include "libs.h"

typedef struct s_server
{
	unsigned char c;
	int counter;
}				t_server;

t_server server;

void	ft_one(int sig, siginfo_t *info, void *context)
{
	write(1, "1", 1);
	(void)sig;
	(void)context;
	server.c += server.counter;
	server.counter /= 2;
	if (server.counter == 0)
	{
		write(1, "2", 1);
		write(1, &server.c, 1);
		server.c = 0;
		server.counter = 128;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(0);
}

void	ft_zero(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	server.counter /= 2;
	if (server.counter == 0)
	{
		write(1, &server.c, 1);
		server.c = 0;
		server.counter = 128;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(0);
}

int main(void)
{
	struct sigaction act_one;
	struct sigaction act_zero;

	memset(&act_one, '\0', sizeof(act_one));
	memset(&act_zero, '\0', sizeof(act_zero));
	act_one.__sigaction_u.__sa_sigaction = ft_one;
	act_zero.__sigaction_u.__sa_sigaction = ft_zero;
	act_one.sa_flags = SA_SIGINFO;
	act_zero.sa_flags = SA_SIGINFO;
	printf("server pid: %d\n", getpid());
	server.c = 0;
	server.counter = 128;
	if (sigaction(SIGUSR1, &act_one, NULL) < 0)
		return (0);
	if (sigaction(SIGUSR2, &act_zero, NULL) < 0)
		return (0);
	while (1)
	{
		pause();
	}
	return (0);
}