#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int checker(char *bs, int b)
{
	int	f;
	int	k;

	f = 0;
	if (b < 2 || !(bs[f]))
			return (0);
	while (bs[f])
	{
		if (bs[f] <= 32 || bs[f] == 45 || bs[f] == 43)
			return (0);
		k = f + 1;
		while (bs[k])
		{
			if (bs[k] == bs[f])
				return (0);
			k++;
		}
		f++;
	}
	return (1);

}

void ft_putnbr_base(int nbr, char *base)
{
	int	b;
	int	f;
	int	e;

	long num;

	num = (long)nbr;
	b = 0;
	f = 0;
	while (base[b])
		b++;
	e = checker(base, b);
	if (e == 1)
	{
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-');
		}
		if (num >= b)
		{
			ft_putnbr_base(num / b, base);
			ft_putnbr_base(num % b, base);
		}
		else
			ft_putchar(base[num]);
	}
}

int main()
{
	ft_putnbr_base(-2147483648, "0123456789abcdef");
}
