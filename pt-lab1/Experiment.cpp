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

int Experiment::C(int n, int k)
{
	if (k == 0 || k == n)
		return 1;
	return C(n - 1, k - 1) * n / k;
}

double Experiment::GetProbability(int const k)
{
	int n = GetAmountOfLightbulbs();
	int m = GetAmountOfDamaged();
	int r = GetAmountOfSelected();

	if ((k < 0) || (k > m)) return 0;
	else
	{
		double result = (double)(C(m, k) * C(n - m, r - k)) / (double)(C(n, r));
		return result;
	}
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
