#pragma once
#include <stdlib.h>
#include <time.h>
#include <tuple>

class Enemy {
public:
	struct enemData {
		int xpos;
		int ypos;
		char type;
	};
	Enemy();
	~Enemy();
	enemData* getEnemies();
	int length;
private:
	enemData temp;
	enemData* storage;

};