#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARG_ERR "Error: argument\n"
#define FILE_ERR "Error: Operation file corrupted\n"
int ret, bgW, bgH;
char bgC, T, C;
float X, Y, W, H;
char **zone;
FILE	*file;

int	ft_putchar(char *str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		write(1, &str[i], 1);
	}
	return 1;
}

int	check(int x, int y)
{
	if (x < X || y <  Y || (X + W) < x || (Y + H) < y)
		return 0;
	else if (x - X < 1 || y - Y < 1 || (X + W) - x < 1 || (Y + H) - y < 1)
		return 1;
	return 2;
}

int main (int ac, char **av)
{
	if(ac != 2)
		return(ft_putchar(ARG_ERR));
	file = fopen(av[1], "r");
	if(file == NULL)
		return(ft_putchar(FILE_ERR));
	ret = fscanf(file, "%d %d %c\n", &bgW, &bgH ,&bgC);
	if(ret != 3 || bgW > 300 || bgW < 1 || bgH > 300 || bgH < 1)
		return(ft_putchar(FILE_ERR));	
	zone = malloc(bgH * sizeof(char *));
	for(int i= 0; i < bgH; i++)
	{
		zone[i] = malloc(bgW * sizeof(char));
		memset(zone[i], bgC, bgW);
	}
	while((ret = fscanf(file, "%c %f %f %f %f %c\n", &T, &X ,&Y ,&W, &H, &C)) == 6)
	{
		if((T != 'r' && T != 'R') || W < 1 || H < 1)
			return(ft_putchar(FILE_ERR));
		for(int y = 0; y < bgH; y++)
		{
			for(int x = 0 ; x < bgW; x++)
			{
				int cond = check(x, y);
				if((cond == 2 && T == 'R') || cond == 1)
					zone[y][x] = C;
			}
		}
	}
	if (ret != -1)
		return(ft_putchar(FILE_ERR));
	for(int i = 0 ; i < bgH; i++)
	{
		ft_putchar(zone[i]);
		ft_putchar("\n");
	}
}