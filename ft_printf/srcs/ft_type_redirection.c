#include "../printf.h"
 

int	ft_type_redirection(t_param *f, va_list param)
{
	if (f->type == 'c')
		return (ft_argv_char(f, va_arg(param, int)));
	if (f->type == 'p')
		return (ft_argv_pointer(f, va_arg(param, char *)));
	if (f->type == 's')
		return (ft_argv_str(f, ft_check_arg(va_arg(param, char *))));
	if (f->type == 'x')
		return (ft_argv_num(f, 16, 0, va_arg(param, unsigned int)));
	if (f->type == 'X')
		return (ft_argv_num(f, 16, 32, va_arg(param, unsigned int)));
	if (f->type == 'i' || f->type == 'd')
		return (ft_argv_num(f, 10, -1, va_arg(param, unsigned int)));
	if (f->type == 'u')
		return (ft_argv_num(f, 10, 1, va_arg(param, unsigned int)));
	return (ft_argv_char(f, f->type));
}
