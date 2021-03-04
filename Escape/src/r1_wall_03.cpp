#include<Siv3D.hpp>
#include"Header.h"


void Room01::wall_03() {
	Rect back_ground(0, 0, window_w / 4 * 3, window_h);
	Rect paper(window_w / 40*19 , window_h / 20*8, window_w / 9, window_h / 5);

	if (!camera) {
		back_ground(wall_03_01).draw();
		
		if (paper.leftClicked()) {
			camera = true;
		}
	}
	else {
		back_ground(wall_03_02).draw();
	}


	Circle c_item_2(window_w / 4, window_h / 8 * 7, window_h / 43);
	Circle c_item_3(window_w / 8 * 5, window_h / 8 * 7, window_h / 43);
	if (!camera) {
		if (item_list[2].status == 0) {
			c_item_2(item_list[2].icon(10, 10, 90, 90)).draw();
			if (c_item_2.leftClicked()) {
				se_item_get.playOneShot(se_volume);
				item_list[2].status = 2;
				flag_item_select = 2;
			}
		}
		if (item_list[3].status == 0) {
			c_item_3(item_list[3].icon(10, 10, 90, 90)).draw();
			if (c_item_3.leftClicked()) {
				se_item_get.playOneShot(se_volume);
				item_list[3].status = 2;
				flag_item_select = 3;
			}
		}
	}
}