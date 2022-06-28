#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ARG_ERR "Error: argument\n"
#define FILE_ERR "Error: Operation file corrupted\n"
int ret, bgW, bgH;
char bgC, T, C;
float X, Y, r;
FILE *file;
char **zone;

int	ft_putstr(char *str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		write(1, &str[i], 1);
	}
	return 1;
}

int	check(int x, int y)
{
	float dis = sqrtf(powf(x - X, 2) + powf(y - Y, 2));
	if (r < dis)
	{
		return 0;
	}
	else if (r - dis < 1.0000)
		return 	1;
	else
		return 2;
}

int	main(int ac, char **av)
{
	if(ac != 2)
		return(ft_putstr(ARG_ERR));
	file = fopen(av[1], "r");
	if(file == NULL)
		return(ft_putstr(FILE_ERR));
	ret = fscanf(file,"%d %d %c\n", &bgW, &bgH, &bgC);
	if(ret != 3 || bgW < 1 || bgW > 300 || bgH < 1 || bgH > 300)
		return(ft_putstr(FILE_ERR));
	zone = malloc(bgH * sizeof(char *));
	for(int i = 0; i < bgH; i++)
	{
		zone[i] = malloc(bgW * sizeof(char));
		memset(zone[i], bgC, bgW);
	}
	while((ret = fscanf(file, "%c %f %f %f %c\n", &T, &X, &Y, &r, &C)) == 5)
	{
		if((T != 'c' && T != 'C'))
			return(ft_putstr(FILE_ERR));
		if (!(r > 0))
			return(ft_putstr(FILE_ERR));
		for(int y = 0; y < bgH ; y++)
		{
			for(int x = 0; x < bgW; x++)
			{
				int cond = check(x, y);
				if((cond == 2 && T == 'C') || cond == 1)
					zone[y][x] = C;
			}
		}
	}
	if(ret != -1)
		return (ft_putstr(FILE_ERR));
	for(int i = 0; i < bgH; i++)
	{
		ft_putstr(zone[i]);
		ft_putstr("\n");
	}
	return 0;
}
