#pragma once

#include <vector>

#include "RandomValue.h"

class Experiment
{
protected:
	RandomValue Generator;
	int lightbulbs;		 // общее число лампочек
	int damagedBulbs;	 // перегоревшие лампочки
	int selectedBulbs;	 // число выбранных лампочек
	int result_min;		 // максимально возможный результат эксперимента
	int result_max;		 // минимально возможный результат эксперимента

	std::vector<int> results;		   // все возможные результаты текущего эксперимента
	std::vector<double> probabilities; // теоретические вероятности, соответствующие результатам

	int GetOneBulb();	 // взять лампочку, возвращает 1 если перегоревшая
	int C(int n, int k); // число сочетаний (C из n по k)
	void SetUpResults(); // рассчитать возможные исходы и вероятности текущего эксперимента

public:
	Experiment();
	Experiment(int n, int m, int r);

	int GetAmountOfLightbulbs() { return lightbulbs; }
	int GetAmountOfDamaged() { return damagedBulbs; }
	int GetAmountOfSelected() { return selectedBulbs; }
	void SetAmountOfLightbulbs(int const n) { lightbulbs = n; }
	void SetAmountOfDamaged(int const m) { damagedBulbs = m; }
	void SetAmountOfSelected(int const r) { selectedBulbs = r; }

	// характеристики эксперимента
	double GetExpectedValue(); // мат. ожидание при текущих параметрах
	double GetDispersion();	   // дисперсия 
	int GetMinResult() { return result_min;  }
	int GetMaxResult() { return result_max;  }

    std::vector<int> GetResults() { return results; }
    std::vector<double> GetProbabilities() { return probabilities; }
	
	// теоретическая вероятность получить k бракованных лампочек
	double GetProbability(int const k); 
	int RunExperiment();	 // возвращает результат эксперимента:
						     // случайное число бракованных лампочек из числа выбранных
};
