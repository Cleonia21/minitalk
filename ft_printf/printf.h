#ifndef PRINTF_H
# define PRINTF_H

# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"../libft/libft.h"

typedef struct s_param
{
	char	type;
	int		flag;
	int		width;
	int		precision;
}			t_param;

typedef struct s_mod
{
	int		null_num;
	int		space_before;
	int		space_after;
	int		sign;
	int		numlen;
}			t_mod;

char		ft_convert_to_six(unsigned int a, int reg);
char		*ft_check_arg(char *str);
int			ft_argv_char(t_param *options, char c);
int			ft_argv_num(t_param *f, int radix, int reg, unsigned int num);
int			ft_argv_pointer(t_param *f, char *value);
int			ft_argv_str(t_param *f, char *str);
int			ft_print_sumbols(char c, int num);
int			ft_printf(const char *str, ...);
int			ft_put_trimmed_str(char *str, int len);
int			ft_type_redirection(t_param *f, va_list param);
int			ft_putchar(char c);
int			ft_numlen(unsigned int num, unsigned int radix);
const char	*ft_crop_space(const char *str, int *bytes_num);
const char	*ft_precision(const char *str, t_param *options, va_list param);
const char	*ft_width(const char *str, t_param *options, va_list param);
const char	*ft_flag(const char *str, t_param *options);

#endif