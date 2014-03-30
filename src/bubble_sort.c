#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"

void bubble_sort (void* base, size_t num, size_t width,int (*compar)(const void*,const void*))
{
	int i,j,k;
	unsigned char *ptr = base;
	unsigned char tmp[256];

	if(num < 2 || width == 0)
		return;

	for(i = num-1; i >= 0; i--)
	{
		for(j = 1; j <= i; j++)
		{
			k = compar((void *)(ptr + width * (j-1)), (void *)(ptr + width * j));

			if(k > 0)
			{
				memcpy(tmp, ptr + width*(j-1), width);
				memcpy(ptr + width*(j-1), ptr + width*j, width);
				memcpy(ptr + width * j, tmp, width);
			}
		}
	}
}
