#include <unistd.h>

void	rush(int col, int row);
void	first_type(int y, int col);
void	normal_type(int y, int col);
void	last_type(int y, int col);

void	rush(int col, int row)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < row)
	{
		while(y < col)
		{
		if ( x == 0 )
			first_type(y, col);
		else if ( x == row - 1)
			last_type(y, col);
		else
			normal_type(y, col);
		y++;
		}
	x++;
	y = 0;
	ft_putchar('\n');
	}
}

void	first_type(int y, int col)
{
	if (y == 0)
		ft_putchar('A');
	else if (y == col - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	normal_type(int y, int col)
{
	if (y == 0)
		ft_putchar('B');
	else if (y == col -1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	last_type(int y, int col)
{
	if (y == 0)
		ft_putchar('C');
	else if (y == col -1)
		ft_putchar('C');
	else
		ft_putchar('B');
}
