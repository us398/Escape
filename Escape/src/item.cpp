#include<Siv3D.hpp>
#include"Header.h"


void Rooms::item() {
	int size = window_w / 16;
	int button_x = window_w / 4 * 3+window_w/32-margin;
	int button_size = size + margin;
	int button_y = window_h / 8;
	int curve_size = size / 6;

	

	for (int i = 0; i < ITEMNUM; i++) {
		if (item_list[i].status == -1) {
			break;
		}
		else {
			RoundRect rect( button_x + button_size * (i % 3) , button_y + button_size * (int)(i / 3) ,size,size,curve_size);
			rect.draw();


			if (item_list[i].status == 2) {
				if (flag_item_select == i) {
	
					if (rect.leftClicked()) {
						flag_sub_window = true;
						sub_window_kind = 0;
					}
				}
			}



			//-1:存在しない、0:未入手、1:入手済み、2:選択中、3:使用済み
			if (item_list[i].status >= 1) {
				rect(item_list[i].icon).draw();
			}
			if (item_list[i].status == 1) {
					if (rect.leftClicked()) {
						flag_item_select = i;
						item_list[i].status = 2;
					}
			}
			if (item_list[i].status == 2) {
				if (flag_item_select == i) {
					rect.drawFrame(0, 3, Palette::Red);

				}
			}
			if (item_list[i].status == 3) {
				rect.draw(ColorF(0.0, 0.0, 0.0, 0.5));
			}

		}

	}
	for (int i = 0; i < ITEMNUM; i++) {
		if (item_list[i].status == 2) {
			if (flag_item_select != i) {
				item_list[i].status = 1;
			}
		}
	}




	







	
}