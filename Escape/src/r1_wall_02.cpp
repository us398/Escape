#include<Siv3D.hpp>
#include"Header.h"


void Room01::wall_02() {
	Circle button[3];
	Rect meter[3];
	int button_size = window_w / 36;
	Rect back_ground(0, 0, window_w / 4 * 3, window_h);
	int margin_tmp = 1;

	if (flag[3] == 1) {
		back_ground(wall_02_02).draw();
	}
	else {
		back_ground.draw(Palette::Black);
		for (int i = 0; i < 3; i++) {
			button[i].x = window_w / 8 * (i + 2);
			button[i].y = window_h / 3 * 2;
			button[i].r = button_size;
			meter[i].x = button[i].x - button_size;
			meter[i].h = window_h / 3;
			meter[i].w = button_size * 2;
			meter[i].y = window_h / 4 + (2 - wall_02_num[i]) * meter[i].h / 2 + margin_tmp;
			meter[i].draw(Palette::Blue);
		}
		back_ground(wall_02_01).draw();
		for (int i = 0; i < 3; i++) {
			if (button[i].leftPressed()) {
				
				button[i].draw(ColorF(0.0, 0.0, 0.0, 0.5));
			}
			if (button[i].leftClicked()) {
				se_bottun_panel.playOneShot();
				wall_02_num[i]++;
				if (wall_02_num[i] == 3) {
					wall_02_num[i] = 0;
				}
			}
		}
		if (wall_02_num[0] == 2 && wall_02_num[1] == 0 && wall_02_num[2] == 1) {
			flag[3] = 1;
		}
	}

 
	Circle c_item(window_w / 4, window_h / 8 * 7, window_h / 43);
	if (!camera) {
		if (item_list[4].status == 0) {
			c_item(item_list[4].icon(10, 10, 90, 90)).draw();
			if (c_item.leftClicked()) {
				se_item_get.playOneShot(se_volume);
				item_list[4].status = 2;
				flag_item_select = 4;
			}
		}
	}

}