#include "RandomValue.h"

RandomValue::RandomValue()
{
	srand((unsigned)time(0));
}

double RandomValue::GetRandomValue()
{
	return ((double)rand()) / RAND_MAX;
}