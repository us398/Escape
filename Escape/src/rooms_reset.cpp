#include<Siv3D.hpp>
#include"Header.h"


void Rooms::rooms_reset() {
	for (int i = 0; i < ITEMNUM; i++) {
		item_list[i].flavour = U" ";
		item_list[i].name = U" ";
		item_list[i].status = -1;
	}
	for (int i = 0; i < FLAGNUM; i++) {
		hint_list[i] = U" ";
		flag[i] = -1;
	}

	flag_sub_window = false;
	sub_window_kind = -1;

	bgm_volume = 0.1;
	se_volume = 0.1;

	flag_item_select = -1;
	wall_num = 0;
	camera = false;



}