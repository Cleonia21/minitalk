#include "../printf.h"
 

static void	ft_m_num(unsigned int num, unsigned int radix, int reg, int *b_num)
{
	if (num > radix - 1)
	{
		ft_m_num(num / radix, radix, reg, b_num);
	}
	b_num += ft_putchar(ft_convert_to_six(num % radix, reg));
}

static void	ft_flag_sumbols(t_param *f, t_mod *m)
{
	if (f->precision > m->numlen)
		m->null_num = f->precision - m->numlen;
	if (f->width > m->numlen + m->null_num + m->sign)
	{
		if (f->flag == 1)
			m->space_after = f->width - m->null_num - m->numlen + m->sign;
		if (f->flag == 0)
		{
			if (f->precision >= 0)
				m->space_before = f->width - m->null_num - m->numlen + m->sign;
			else
				m->null_num = f->width - m->numlen + m->sign;
		}
		if (f->flag == -1)
			m->space_before = f->width - m->null_num - m->numlen + m->sign;
	}
}

static t_mod	ft_initialization(int a)
{
	t_mod	mod;

	mod.null_num = a;
	mod.numlen = a;
	mod.sign = a;
	mod.space_after = a;
	mod.space_before = a;
	return (mod);
}

static unsigned int	ft_convert_num(unsigned int num, t_mod *mod)
{
	if ((int)num < 0)
	{
		num = (int)num * -1;
		mod->sign = -1;
	}
	return (num);
}

int	ft_argv_num(t_param *f, int radix, int reg, unsigned int num)
{
	t_mod	mod;
	int		bytes_num;

	mod = ft_initialization(0);
	if (reg == -1)
		num = ft_convert_num(num, &mod);
	mod.numlen = ft_numlen(num, radix);
	ft_flag_sumbols(f, &mod);
	bytes_num = ft_print_sumbols(' ', mod.space_before);
	if (mod.sign == -1)
		bytes_num += ft_putchar('-');
	bytes_num += ft_print_sumbols('0', mod.null_num);
	if (num != 0 || f->precision != 0)
	{
		ft_m_num(num, radix, reg, &bytes_num);
		bytes_num += mod.numlen;
	}
	else if (f->width > 0)
		bytes_num += ft_putchar(' ');
	bytes_num += ft_print_sumbols(' ', mod.space_after);
	return (bytes_num);
}
