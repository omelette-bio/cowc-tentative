#include <stdio.h>
#include <stdlib.h>

int arr[3000];
int i = 0;
int* reg = NULL;
int main()
{
	arr[i]+=1;
	i+=2;
	arr[i]+=1;
	i+=2;
	arr[i]+=1;
	i-=4;
	while ( arr[i] != 0 )
	{
		printf("%d\n", arr[i]);
		i+=2;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		i-=1;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		i+=3;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		i-=1;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		while ( arr[i] != 0 )
		{
			arr[i]-=1;
			i-=2;
			while ( arr[i] != 0 )
			{
				arr[i]-=1;
				i-=1;
				arr[i]+=1;
				i+=1;
				}
			i+=1;
			if ( reg == NULL )
			{
				reg = malloc(sizeof(int));
				if ( reg == NULL ) return 1;
				*reg = arr[i];
			}
			else
			{
				arr[i] = *reg;
				reg = NULL;
			}
			i-=1;
			if ( reg == NULL )
			{
				reg = malloc(sizeof(int));
				if ( reg == NULL ) return 1;
				*reg = arr[i];
			}
			else
			{
				arr[i] = *reg;
				reg = NULL;
			}
			i+=2;
			}
		i+=1;
		arr[i]+=1;
		i-=4;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		i+=2;
		if ( reg == NULL )
		{
			reg = malloc(sizeof(int));
			if ( reg == NULL ) return 1;
			*reg = arr[i];
		}
		else
		{
			arr[i] = *reg;
			reg = NULL;
		}
		i-=2;
		}
}
