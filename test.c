#include <signal.h>
#include <stdio.h>

int	main(void)
{
	int n1 = SIGUSR1;
	int n2 = SIGUSR2;

	printf("%d\n", n1);
	printf("%d\n", n2);


	return (0);
}
