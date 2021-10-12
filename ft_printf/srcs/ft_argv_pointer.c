#include "../printf.h"
 

static int	ft_len_address(unsigned char *s)
{
	int	len_address;
	int	i;

	len_address = 18;
	i = 7;
	while (s[i] == 0)
	{
		len_address -= 2;
		i--;
	}
	if (s[i] < 16)
		len_address--;
	return (len_address);
}

static int	ft_null_pointer(t_param *f)
{
	int	len_address;
	int	bytes_num;

	len_address = 3;
	bytes_num = 0;
	if (f->precision == 0)
		len_address--;
	if (len_address < f->width && f->flag != 1)
	{
		ft_print_sumbols(' ', f->width - len_address);
		bytes_num = f->width - len_address;
	}
	ft_put_trimmed_str("0x0", len_address);
	if (len_address < f->width && f->flag == 1)
	{
		ft_print_sumbols(' ', f->width - len_address);
		bytes_num = f->width - len_address;
	}
	return (bytes_num + len_address);
}

static int	ft_put_address(unsigned char *s)
{
	int	bytes_num;
	int	i;

	bytes_num = 0;
	i = 7;
	while (s[i] == 0)
		i--;
	if (s[i] < 16)
	{
		bytes_num += ft_printf("%x", s[i]);
		i--;
	}
	while (i >= 0)
	{
		bytes_num += ft_printf("%.2x", s[i]);
		i--;
	}
	return (bytes_num);
}

int	ft_argv_pointer(t_param *f, char *value)
{
	unsigned char	*s;
	int				len_address;
	int				bytes_num;

	bytes_num = 0;
	if (!value)
		bytes_num = ft_null_pointer(f);
	else
	{
		s = (unsigned char *)&value;
		len_address = ft_len_address(s);
		if (len_address < f->width && f->flag != 1)
			bytes_num += ft_print_sumbols(' ', f->width - len_address);
		ft_put_trimmed_str("0x", -1);
		bytes_num += ft_put_address(s) + 2;
		if (len_address < f->width && f->flag == 1)
			bytes_num += ft_print_sumbols(' ', f->width - len_address);
	}
	return (bytes_num);
}
