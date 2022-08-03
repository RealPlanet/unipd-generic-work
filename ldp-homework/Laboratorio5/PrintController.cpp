#include "PrintController.h"
#include <iostream>
using namespace std;

void PrintController::show()
{
	cout << "Is visible: " << bVisible << endl;
	cout << "Current level: " << currentLevel << endl;
}
