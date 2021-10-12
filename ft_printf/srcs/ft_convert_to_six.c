#include "../printf.h"

char	ft_convert_to_six(unsigned int a, int reg)
{
	if (a == 10)
		return ('a' - reg);
	if (a == 11)
		return ('b' - reg);
	if (a == 12)
		return ('c' - reg);
	if (a == 13)
		return ('d' - reg);
	if (a == 14)
		return ('e' - reg);
	if (a == 15)
		return ('f' - reg);
	return (a + '0');
}
