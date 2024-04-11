#include<stdio.h>
#include<map>
using namespace std;

int subnet[32][4]=
{
	{  1<<7, 0, 0, 0},
	{  3<<6, 0, 0, 0},
	{  7<<5, 0, 0, 0},
	{ 15<<4, 0, 0, 0},
	{ 31<<3, 0, 0, 0},
	{ 63<<2, 0, 0, 0},
	{127<<1, 0, 0, 0},
	{255   , 0, 0, 0},

	{255,   1<<7, 0, 0},
	{255,   3<<6, 0, 0},
	{255,   7<<5, 0, 0},
	{255,  15<<4, 0, 0},
	{255,  31<<3, 0, 0},
	{255,  63<<2, 0, 0},
	{255, 127<<1, 0, 0},
	{255, 255   , 0, 0},

	{255, 255,   1<<7, 0},
	{255, 255,   3<<6, 0},
	{255, 255,   7<<5, 0},
	{255, 255,  15<<4, 0},
	{255, 255,  31<<3, 0},
	{255, 255,  63<<2, 0},
	{255, 255, 127<<1, 0},
	{255, 255, 255   , 0},

	{255, 255, 255,   1<<7},
	{255, 255, 255,   3<<6},
	{255, 255, 255,   7<<5},
	{255, 255, 255,  15<<4},
	{255, 255, 255,  31<<3},
	{255, 255, 255,  63<<2},
	{255, 255, 255, 127<<1},
	{255, 255, 255, 255   },
};

typedef __int64 LL;
int n, k;
int ip[100005][4];

int possible(int id)
{
	int i;
	LL z;

	map<LL, int> M;

	for(i = 0; i < n; i++)
	{
		z = (subnet[id][0] & ip[i][0]);
		z = (z<<8) + (subnet[id][1] & ip[i][1]);
		z = (z<<8) + (subnet[id][2] & ip[i][2]);
		z = (z<<8) + (subnet[id][3] & ip[i][3]);

		M[z] = 1;
	}

	return (M.size() == k);
}

int main()
{
	int i;

	scanf("%d %d", &n, &k);

	for(i = 0; i < n; i++)
	{
		scanf("%d.%d.%d.%d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
	}

	for(i = 0; i < 31; i++)
	{
		if(possible(i))
		{
			printf("%d.%d.%d.%d\n", subnet[i][0], subnet[i][1], subnet[i][2], subnet[i][3]);
			break;
		}
	}

	if(i == 31)
		printf("-1\n");

	return 0;
}