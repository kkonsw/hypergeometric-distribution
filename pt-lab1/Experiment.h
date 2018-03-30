#pragma once
#include "RandomValue.h"

class Experiment
{
protected:
	RandomValue Generator;
	int lightbulbs;		 // общее число лампочек
	int damagedBulbs;	 // перегоревшие лампочки
	int selectedBulbs;	 // число выбранных лампочек

	int GetOneBulb();	 // взять лампочку, возвращает 1 если перегоревшая
	int C(int n, int k); // число сочетаний (C из n по k)
public:
	Experiment();
	Experiment(int n, int m, int r);

	int GetAmountOfLightbulbs() { return lightbulbs; }
	int GetAmountOfDamaged() { return damagedBulbs; }
	int GetAmountOfSelected() { return selectedBulbs; }
	void SetAmountOfLightbulbs(int const n) { lightbulbs = n; }
	void SetAmountOfDamaged(int const m) { damagedBulbs = m; }
	void SetAmountOfSelected(int const r) { selectedBulbs = r; }
	
	// теоретическая вероятность получить k бракованных лампочек
	double GetProbability(int const k); 
	int RunExperiment();	 // возвращает результат эксперимента:
						     // случайное число бракованных лампочек из числа выбранных
	
};
