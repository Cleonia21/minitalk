#include "libs.h"

void empty(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
}

int main(int argc, char **argv)
{
	int i;
	struct sigaction act;
	char *str;
	int serv_pid;

	memset(&act, '\0', sizeof(act));
	act.__sigaction_u.__sa_sigaction = empty;
	act.sa_flags = SA_SIGINFO;
	serv_pid = atoi(argv[1]);
	str = argv[2];
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		return (0);
	while (*str)
	{
		i = 128;
		while (i > 0)
		{
			if (i & (unsigned char)*str)
			{
				if (kill(serv_pid, SIGUSR1) == -1)
					return (0);
			}
			else
			{
				if (kill(serv_pid, SIGUSR2) == -1)
					return (0);
			}
			i /= 2;
			pause();
		}
		str++;
	}
	return (0);
}