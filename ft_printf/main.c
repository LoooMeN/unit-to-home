
#include "./includes/ft_printf.h"

int			main(void)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	i = printf("Hello |%7-.5u|\n", 1234);
	n = ft_printf("Hello |%7-.5u|\n", 1234);
	printf("%d||%d\n", i, n);
	return (0);
}