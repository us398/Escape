#include<Siv3D.hpp>
#include"Header.h"


void Room02::wall_03() {
	Rect back_ground(0, 0, window_w / 4 * 3, window_h);
//	Rect monitor(window_w / 16*3 , window_h /4, window_w / 16 * 6, window_h / 4);

	flag_wall_01 = -1;

	if (flag[6] == 1) {
		flag[5] = 1;
		if (night) {
			back_ground(wall_03_03).draw();
		}
		else {
			back_ground(wall_03_02).draw();
		}
	}
	else {
		back_ground(wall_03_01).draw();
	}
	


}