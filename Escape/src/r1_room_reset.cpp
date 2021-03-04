#include<Siv3D.hpp>
#include"Header.h"


void Room01::room_reset() {

	rooms_reset();
	for (int i = 0; i < 5; i++) {
		holl[i].holl.x = -5;
		holl[i].holl.y = -5;
		holl[i].holl.r = 1;
		holl[i].flag = 0;
	}
	for (int i = 0; i < 3; i++) {
		wall_02_num[i] = 0;
	}
	wall_01_num = 0;








}