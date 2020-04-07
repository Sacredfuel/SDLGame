#include "Enemy.h"

Enemy::Enemy()
{
	srand(time(NULL));            //seeds the data
	length = rand() % 5 + 1;      //generates anywhere between 0 and 4 enemies + 1

	storage = new enemData[length];

	for (int i = 0; i < length; i++) {
		temp.xpos = rand() % 20; //rand x between 0 and 19
		temp.ypos = rand() % 25; //rand y between 0 and 24
		temp.type = 'a';         //type a enemy, no need
		
		*(storage + i) = temp;   //dereferences the storage heap and sets it to the e1
	}
}


Enemy::~Enemy(){
	//delete []storage;
}

Enemy::enemData* Enemy::getEnemies()
{
	return storage;
}
