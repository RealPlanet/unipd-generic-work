#include "Controller.h"
#include <iostream>

void Controller::on()
{
	bVisible = true;
}

void Controller::off()
{
	bVisible = false;
}

void Controller::set_level(int newLevel)
{
	currentLevel = newLevel;
}

void Controller::show()
{
	std::cout << currentLevel;
}

Controller::Controller()
{
	bVisible = true;
	currentLevel = 0;
}
