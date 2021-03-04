#include<Siv3D.hpp>
#include"Header.h"


void Room02::wall_02() {
	Rect back_ground(0, 0, window_w / 4 * 3, window_h);
	Circle c_item(window_w / 2, window_h / 8 * 7, window_h / 43);
	Rect moon(window_w / 4-margin/2, window_h / 5 * 2-margin/2, window_w / 8, window_h / 5);
	Rect sun(window_w / 8 * 3 - margin / 2, window_h / 5 * 2-margin/8, window_w / 8, window_h / 5);

	flag_wall_01 = -1;


	if(flag[4]==1&& item_list[0].status == 0){
		back_ground(wall_02_02).draw();
			if (c_item.leftClicked()) {
				item_list[0].status = 2;
				flag_item_select = 0;
				se_item_get.playOneShot(se_volume);
				flag[3] = 1;
			}
	}
	else {
		back_ground(wall_02_01).draw();
	}

	if (moon.leftPressed()) {
		moon.draw(ColorF(0.0, 0.0, 0.0, 0.5));
	}
	if (sun.leftPressed()) {
		sun.draw(ColorF(0.0, 0.0, 0.0, 0.5));
	}

	if (moon.leftClicked()) {
		if (flag[5] == 1) {
			night = true;
		}
		se_bottun_panel.playOneShot(se_volume);
	}
	if (sun.leftClicked()) {
		if (flag[6] == 0) {
			flag[6] = 1;
		}
		night = false;
		se_bottun_panel.playOneShot(se_volume);
	}



}