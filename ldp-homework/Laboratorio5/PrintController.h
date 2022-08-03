#pragma once
#include "Controller.h"

class PrintController : public Controller
{
public:
	void show() override;
	PrintController() : Controller() {}
};

