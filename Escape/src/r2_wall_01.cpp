#include<Siv3D.hpp>
#include"Header.h"


void Room02::wall_01() {
	Rect back_ground(0, 0, window_w / 4 * 3, window_h);
	Circle button[6];
	

	back_ground(wall_01_01).draw();
	for (int i = 0; i < 6; i++) {
		button[i].x = window_w / 4 + window_w / 8 * (i % 3);
		button[i].y = window_h / 3 + window_h / 3 * (i / 3);
		button[i].r = window_w / 24;
		if (button[i].leftPressed()) {
			button[i].draw(ColorF(0.0, 0.0, 0.0, 0.5));
		}
		if (button[i].leftClicked()) {
			se_bottun_panel.playOneShot(se_volume);
			if (flag[3] == 0) {
				if (i == 3 && flag_wall_01 == -1) {
					wall_01_num = 1;
				}
				if (i == 1 && flag_wall_01 == 3 && wall_01_num == 1) {
					wall_01_num = 2;
				}
				if (i == 5 && flag_wall_01 == 1 && wall_01_num == 2) {
					wall_01_num = 3;
				}
				if (i == 4 && flag_wall_01 == 5 && wall_01_num == 3) {
					wall_01_num = 4;
				}
				if (i == 0 && flag_wall_01 == 4 && wall_01_num == 4) {
					wall_01_num = 5;
				}
				if (wall_01_num == 5) {
					flag[4] = 1;
					se_item_drop.play();
				}

				flag_wall_01 = i;
			}
		}

	}



	



}
