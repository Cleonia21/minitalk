#include "libs.h"

void print_sig(int sig)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	if (sig == SIGUSR2)
		write(1, "1", 1);
}

int main()
{
	ft_printf("server pid: %d\n", getpid());

	while (1)
	{
		signal(SIGUSR1, print_sig);
		signal(SIGUSR2, print_sig);
		pause();
	}
}