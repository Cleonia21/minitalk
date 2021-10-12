#include "../printf.h"
 

int	ft_printf(const char *str, ...)
{
	va_list	param;
	t_param	options;
	int		bytes_num;

	bytes_num = 0;
	va_start(param, str);
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_crop_space(str, &bytes_num);
			str = ft_flag(str, &options);
			str = ft_width(str, &options, param);
			str = ft_precision(str, &options, param);
			options.type = *str;
			bytes_num += ft_type_redirection(&options, param);
		}
		else
			bytes_num += ft_putchar(*str);
		str++;
	}
	va_end(param);
	return (bytes_num);
}
