#include<Siv3D.hpp>
#include"Header.h"


int Rooms::play_game() {
	int page = 3;

	set_size();



	set_audio_volume();

	if (!flag_sub_window) {


		switch (wall_num)
		{
		case 0:
			wall_00();
			break;
		case 1:
			wall_01();
			break;
		case 2:
			wall_02();
			break;
		case 3:
			wall_03();
			break;
		default:
			break;
		}

		page = display_game_ui();
		item();
		ui_button();
		vector();
	}
	else {
		page=sub_window();
	}


	if (flag[0] == 1) {
		page=-2;
	}
	play_bgm(page);
	return page;
}