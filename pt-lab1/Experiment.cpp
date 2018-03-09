#include "Experiment.h"

Experiment::Experiment()
{
	lightbulbs = 0;
	damagedBulbs = 0;
	selectedBulbs = 0;
}

Experiment::Experiment(int n, int m, int r)
{
	lightbulbs = n;
	damagedBulbs = m;
	selectedBulbs = r;
}

int Experiment::GetOneBulb()
{
	double p = 0;
	double u = Generator.GetRandomValue(); // получаем случайное значение на [0, 1]

	// p - вероятность достать плохую лампочку
	p = (double)GetAmountOfDamaged() / (double)GetAmountOfLightbulbs();

	if (u < p) return 1;
	else return 0;
}

int Experiment::RunExperiment()
{	
	int result = 0;
	int count = 0;

	for (int i = 0; i < selectedBulbs; i++)
	{
		result = GetOneBulb();
		if (result == 1) {
			damagedBulbs--;
			count++;
		}
		lightbulbs--;
	}

	return count;
}
