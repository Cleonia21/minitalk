#include "../printf.h"
 

int	ft_argv_char(t_param *options, char c)
{
	if (options->flag == 0)
		ft_print_sumbols('0', options->width - 1);
	if (options->flag == -1)
		ft_print_sumbols(' ', options->width - 1);
	ft_print_sumbols(c, 1);
	if (options->flag == 1)
		ft_print_sumbols(' ', options->width - 1);
	if (options->width > 0)
		return (options->width);
	return (1);
}
