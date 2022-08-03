#include "LevelController.h"

void LevelController::set_level(int newLevel)
{
	/*
		Ipotizzo che la classe Shape definisce un metodo nell interfaccia che consente di settare le tre variabili di un colore (r,g,b)
		allo stesso numero (livello)
	*/

	controlledShape.setColorLevel(newLevel);
}

LevelController::LevelController(Shape _S)
{
	bVisible = true;
	currentLevel = 0;

	controlledShape = _S;
}
