#include "RandomValue.h"

// инициализация датчика псевдослучайных чисел в конструкторе
RandomValue::RandomValue()
{
	srand((unsigned)time(0));
}

double RandomValue::GetRandomValue()
{
    // возвращает значение случайной величины U 
    // с равномерным законом распределения на [0,1]. 
	return ((double)rand()) / RAND_MAX;
}