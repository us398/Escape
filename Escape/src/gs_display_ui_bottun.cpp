
#include<Siv3D.hpp>
#include"Header.h"


void GameSystem::display_ui_bottun() {
	int ui_button_x = window_w / 32 * 25;

	if (!flag_sub_window) {
		if (SimpleGUI::Button(U"‰¹", Vec2(ui_button_x + window_w / 16 * 2 + margin, window_h / 32), window_w / 16)) {
			se_bottun.play();
			flag_sub_window = true;
		}
	}
	else {
		Rect(window_w / 16, window_h / 4, window_w / 8 * 5, window_h / 2).draw();
		SimpleGUI::Slider(U"BGM", bgm_volume, Vec2(window_w / 8, window_h / 8 * 3), window_w / 8, window_w / 8 * 3);
		if (SimpleGUI::Slider(U"SE", se_volume, Vec2(window_w / 8, window_h / 8 * 4), window_w / 8, window_w / 8 * 3)) {
			se_bottun.playOneShot(se_volume);
		}
		if (SimpleGUI::ButtonAt(U"•Â‚¶‚é", Vec2(window_w / 8 * 3, window_h / 16 * 11))) {
			se_bottun.play();
			flag_sub_window = false;
		}

	}


}
