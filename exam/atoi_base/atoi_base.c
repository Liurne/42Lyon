
#include <stdio.h>

char *ft_tolower(char *str)
{
	int i;

	i = 0;
	while (str && str[i]) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A') + 'a';
		i++;
	}
	return (str);
}

char verif_base(char *nbr, int base)
{
	int i;
	int j;
	int isOk;
	char	hexabase[17];

	i = 0;
	isOk = 1;
	hexabase =  "0123456789abcdef";
	if (base  < 2  || base > 16)
		return (0);
	while (nbr && nbr[i] && isOk)
	{
		j = 0;
		isOk = 0;
		while(j < base)
		{
			if(nbr[i] == hexabase[j])
				isOk = 1;
			j++;
		}
		i++;
	}
	return (isOk);
}

int	atoi_base(char *nbr, int base)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	nbr = tolower(nbr);
	if(!verif_base(nbr, base))
		return ()
}
int main(void)
{

	return (0);
}