#include "compar.h"

int compar_int (void* int1,void* int2)
{
	int i1 = *((int*) int1), i2 = *((int*) int2);
	
	if (i1>i2)
		return 1;
	else if (i2>i1) return -1;
		 else return 0;
}

int compar_float (void* f1,void* f2)
{
	int fl1 = *((float*) f1), fl2 = *((float*) f2);
	
	if (fl1>fl2)
		return 1;
	else if (fl2>fl1) return -1;
		 else return 0;
}

int compar_char (void* c1, void* c2)
{
	return strcmp(c1,c2);
}

int compar_long (void* long1, void* long2)
{
	int l1 = *((long int*) long1), l2 = *((long int*) long2);
	
	if (l1>l2)
		return 1;
	else if (l2>l1) return -1;
		 else return 0;
}
