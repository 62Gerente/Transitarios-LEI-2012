#include "fhash.h"

int fchar_Hash(void *elem, int nrelem) {
	long long int sum = 1;
	int x;
	for(x=0; ((char *)elem)[x] != '\0'; x++) {
		sum = sum*2 + ((char *)elem)[x];
	}
	
	return sum % nrelem;
}

int flong_Hash(void *elem, int nrelem) {
	
	long int* l = ((long int*) elem);
	
	return (*l) % nrelem;
}
