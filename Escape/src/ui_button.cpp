#include<Siv3D.hpp>
#include"Header.h"


void Rooms::ui_button() {
	int ui_button_x = window_w / 32 * 25;

	if (SimpleGUI::Button(U"—V", Vec2(ui_button_x - margin, window_h / 32), window_w / 16)) {
		se_ui_button.play();
		flag_sub_window = true;
		sub_window_kind = 1;
	}
	if (SimpleGUI::Button(U"‰ð", Vec2(ui_button_x+window_w / 16 , window_h / 32), window_w / 16)) {
		se_ui_button.play();
		flag_sub_window = true;
		sub_window_kind = 2;
	}
	if (SimpleGUI::Button(U"‰¹", Vec2(ui_button_x+window_w / 16 * 2 + margin, window_h / 32), window_w / 16)) {
		se_ui_button.play();
		flag_sub_window = true;
		sub_window_kind = 3;
	}


}