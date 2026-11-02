
#include "ft_printf.h"

void	ft_puthex(int n, char c)
{
	char	p[16];
	char	*hex = "0123456789abcdef";
	char	*HEX = "0123456789ABCDEF";
	int		i;
	
	i = 0;
	if(c == 'x')
	{
		while (n > 0)
		{		
			p[i] = hex[n % 16];
			n = n / 16;
		}
		ft_putstr(p);
	}
	else if(c == 'X')
	{
		while (n > 0)
		{		
			p[i] = HEX[n % 16];
			n = n / 16;
		}
		ft_putstr(p);
	}
		
}
