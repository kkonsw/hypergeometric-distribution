#include "Experiment.h"

Experiment::Experiment()
{
	lightbulbs = 0;
	damagedBulbs = 0;
	selectedBulbs = 0;
	result_min = 0;
	result_max = 0;
}

Experiment::Experiment(int n, int m, int r)
{
	lightbulbs = n;
	damagedBulbs = m;
	selectedBulbs = r;
	SetUpResults();
}

int Experiment::GetOneBulb()
{
	double p = 0.0;
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

void Experiment::SetUpResults()
{
	int n = GetAmountOfLightbulbs();
	int m = GetAmountOfDamaged();
	int r = GetAmountOfSelected();
	int k_max = r; // максимально возможное число испорченных лампочек
	int k_min = 0; // минимально возможное число испорченных лампочек

	int tmp = r - n + m;

	if (tmp < 0) k_min = 0;
	else k_min = tmp;

	if (m < r) k_max = m;
	else k_max = r;

	result_min = k_min;
	result_max = k_max;

	results.clear();
	for (int k = k_min; k <= k_max; k++)
		results.push_back(k); // добавляем возможные результаты в порядке возрастания

	probabilities.clear();
	for (int& t : results)
		probabilities.push_back(GetProbability(t));
	// добавляем теоретические вероятности в соответствующем порядке
}

double Experiment::GetExpectedValue()
{
	SetUpResults();
	double sum = 0.0;

	for (int i = 0; i < results.size(); i++)
		sum += results[i] * probabilities[i];

	return sum;
}

double Experiment::GetDispersion()
{
	SetUpResults();
	double EV = GetExpectedValue();
	double sum = 0.0;

	for (int i = 0; i < results.size(); i++)
		sum += pow((results[i] - EV), 2) * probabilities[i];

	return sum;
}

double Experiment::GetProbability(int const k)
{
	int n = GetAmountOfLightbulbs();
	int m = GetAmountOfDamaged();
	int r = GetAmountOfSelected();

	if ((k < 0) || (k > m)) return 0;
	else
	{
		// формула гипергеометрического распределения
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
