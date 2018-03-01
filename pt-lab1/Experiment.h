#pragma once
#include "RandomValue.h"

class Experiment
{
protected:
	RandomValue Generator;
	int lightbulbs;		// общее число лампочек
	int damagedBulbs;	// перегоревшие лампочки
	int selectedBulbs;	// число выбранных лампочек
public:
	Experiment();
	Experiment(int m, int n, int r);

	int GetAmountOfLightbulbs() { return lightbulbs; }
	int GetAmountOfDamaged() { return damagedBulbs; }
	int GetAmountOfSelected() { return selectedBulbs; }
	void SetAmountOfLightbulbs(int const m) { lightbulbs = m; }
	void SetAmountOfDamaged(int const n) { damagedBulbs = n; }
	void SetAmountOfSelected(int const r) { selectedBulbs = r; }

	int GetOneBulb(); // взять лампочку, возвращает 1 если перегоревшая
	int RunExperiment();
};
