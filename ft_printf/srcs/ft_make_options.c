#include "../printf.h"
 

const char	*ft_trim_flag(const char *str, int *flag)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
			*flag = '-';
		if (*str == '0' && *flag != '-')
			*flag = '0';
		str++;
	}
	return (str);
}

const char	*ft_flag(const char *str, t_param *options)
{
	int	flag;

	flag = 0;
	str = ft_trim_flag(str, &flag);
	options->flag = -1;
	if (flag == '0')
		options->flag = 0;
	if (flag == '-')
		options->flag = 1;
	return (str);
}

const char	*ft_width(const char *str, t_param *options, va_list param)
{
	options->width = 0;
	if (*str == '*')
	{
		options->width = va_arg(param, int);
		if (options->width < 0)
		{
			options->width = -options->width;
			options->flag = 1;
		}
		return (++str);
	}
	while (*str >= '0' && *str <= '9')
	{
		options->width = options->width * 10 + *str - '0';
		str++;
	}
	return (str);
}

const char	*ft_precision(const char *str, t_param *options, va_list param)
{
	options->precision = -1;
	if (*str == '.')
	{
		str++;
		options->precision = 0;
		if (*str == '*')
		{
			options->precision = va_arg(param, int);
			return (++str);
		}
		while (*str >= '0' && *str <= '9')
		{
			options->precision = options->precision * 10 + *str - '0';
			str++;
		}
	}
	return (str);
}

const char	*ft_crop_space(const char *str, int *bytes_num)
{
	str++;
	while (*str == ' ' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == '\f' || *str == '\r')
	{
		ft_putchar(*str);
		bytes_num++;
		str++;
	}
	return (str);
}
