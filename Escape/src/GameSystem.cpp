
#include<Siv3D.hpp>
#include"Header.h"


GameSystem::GameSystem() {
	String room_name[ROOMNUM];

	for (int i = 0; i < ROOMNUM; i++) {
		room_name[i] = { U" " };
	}
	window_h=1;
	window_w=1;
	margin=1;
	flag_sub_window=false;

	bgm_volume=0.1;
	se_volume=0.1;


}
