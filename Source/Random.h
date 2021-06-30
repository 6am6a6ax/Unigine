#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <vector>
#include <ctime>

#include "Config.h"

#include "Vector2f.h"

#include "Unit.h"

std::vector<Unit> Random()
{
	std::srand(std::time(nullptr));

	std::vector<Unit> result = std::vector<Unit>();
	
	for (std::size_t i = 0; i < UNIT_COUNT; i++)
	{
		Vector2f position = Vector2f(rand() % FIELD_WIDTH, rand() % FIELD_HEIGHT);
		Vector2f look = Vector2f(rand() % FIELD_WIDTH, rand() % FIELD_HEIGHT);

		result.push_back(Unit(position, look));
	}

	return result;
}

#endif
