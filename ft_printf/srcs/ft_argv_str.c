#include "../printf.h"
 

int	ft_argv_str(t_param *f, char *str)
{
	int	strlen;
	int	nullnum;
	int	bytes_num;

	nullnum = 0;
	if (f->flag == 0 && f->precision >= 0)
		f->flag = -1;
	strlen = (int)ft_strlen(str);
	bytes_num = 0;
	if (f->precision < 0)
		f->precision = strlen;
	if (strlen > f->precision)
		strlen = f->precision;
	if (strlen < f->width)
		nullnum = f->width - strlen;
	if (f->flag == 0)
		bytes_num += ft_print_sumbols('0', nullnum);
	if (f->flag == -1)
		bytes_num += ft_print_sumbols(' ', nullnum);
	bytes_num += ft_put_trimmed_str(str, strlen);
	if (f->flag == 1)
		bytes_num += ft_print_sumbols(' ', nullnum);
	return (bytes_num);
}
