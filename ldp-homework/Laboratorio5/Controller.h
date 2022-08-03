#pragma once
class Controller
{
public:
	virtual void on();
	virtual void off();
	virtual void set_level(int newLevel);
	virtual void show();
	Controller();
protected:
	bool bVisible;
	int currentLevel;
};

