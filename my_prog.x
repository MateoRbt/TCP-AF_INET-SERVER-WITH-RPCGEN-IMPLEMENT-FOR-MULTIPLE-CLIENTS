struct arr
{
	int y <>;
	int n;
};

struct max_min
{
	int max;
	int min;
};

struct a_prod_y
{
	int y<>;
	int n;
	float a;
};
struct ay
{
	float ay<>;
};

program MY_PROG
{
	version MY_VERS
	{
		float average (arr) = 1;
		max_min maxmin(arr) = 2;
		ay product(a_prod_y) = 3;
	} = 1;
} = 0x23450001;
