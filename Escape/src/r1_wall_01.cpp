#include<Siv3D.hpp>
#include"Header.h"


void Room01::wall_01() {
	Rect back_ground(0, 0, window_w / 4*3, window_h);
	Circle m_circle(window_w / 8 * 3, window_h / 2, window_h / 18 * 5);
	Circle c_item(window_w / 2, window_h / 8 * 7, window_h / 43);

	if (flag[4] == 1) {
		back_ground(wall_01_02).draw();
	}
	else{
		back_ground(wall_01_01).draw();
		for (int i = 0; i < 5; i++) {
			holl[i].holl.r = m_circle.r / 12;
			if (i % 2 == 1) {
				holl[i].holl.x = m_circle.x + m_circle.r / 2 * 1.8 * (i - 2);
				holl[i].holl.y = m_circle.y - m_circle.r / 2;
			}
			else if (i != 0) {
				holl[i].holl.x = m_circle.x + m_circle.r / 2 * (i - 3);
				holl[i].holl.y = m_circle.y + m_circle.r / 2 * 1.8;
			}
			else {
				holl[i].holl.x = m_circle.x;
				holl[i].holl.y = m_circle.y - m_circle.r;
			}


		
			if (holl[i].holl.leftClicked()) {
				int tmp;
				tmp = holl[i].flag;
				holl[i].flag = flag_item_select + 1;
				flag_item_select = tmp-1;
				if (flag_item_select != -1) {
					item_list[flag_item_select].status = 2;
				}
				if (holl[i].flag != 0) {
					item_list[holl[i].flag - 1].status = 3;
				}
				se_ball.playOneShot(se_volume);


			/*	if (holl[i].flag >= 1) {
					item_list[holl[i].flag - 1].status = 2;
					flag_item_select = holl[i].flag - 1;
					holl[i].flag = 0;
					se_ball.playOneShot(se_volume);
				}
				if (flag_item_select != -1) {
					holl[i].flag = flag_item_select + 1;
					item_list[flag_item_select].status = 3;
					se_ball.playOneShot(se_volume);
					flag_item_select = -1;
				}*/
				
			}


			int flag_ball = 0;
			for(int i=0;i<5;i++){
				if (holl[i].flag >= 1) {
					holl[i].holl(item_list[holl[i].flag-1].icon(10,10,90,90)).draw();
					if (i == holl[i].flag-1) {
						flag_ball++;
					}
				}
			}
			if (flag_ball == 5) {
				flag[4] = 1;
			}
		}
	}
	if (!camera) {
		if (item_list[1].status == 0) {
			c_item(item_list[1].icon(10, 10, 90, 90)).draw();
			if (c_item.leftClicked()) {
				item_list[1].status = 2;
				flag_item_select = 1;
				se_item_get.playOneShot(se_volume);
			}
		}
	}
}
