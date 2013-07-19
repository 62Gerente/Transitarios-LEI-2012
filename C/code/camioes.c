#include "camioes.h"

void* da_matricula (void* c)
{
	char* matricula = ((Camiao*) c)->matricula;
	
	return matricula;
}

void* da_custokm (void* c)
{
	float* custokm = &(((Camiao*) c)->custokm);
	return custokm;
}

void* da_amatricula (void* c)
{
	char* matricula = ((ACamiao*) c)->camiao->matricula;
	return matricula;
}

void* da_acustokm (void* c)
{
	float* custokm = &(((ACamiao*) c)->camiao->custokm);
	return custokm;
}
