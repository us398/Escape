#include<Siv3D.hpp>
#include"Header.h"


int Rooms::display_game_ui() {
	int ui_window_x = window_w / 4 * 3;
	int page=3;

		Rect(ui_window_x, 0, window_w / 4, window_h).draw(ColorF(0.5, 0.5, 0.0, 1.0));
	
	
		if (SimpleGUI::Button(U"部屋選択", Vec2((window_w / 32) + ui_window_x, (window_h / 16) * 13 + margin), window_w / 16 * 3)) {
			{
				se_ui_button.play();
				sub_window_kind = 6;
				flag_sub_window = true;
			}
		}

		if (SimpleGUI::Button(U"スタートページ", Vec2((window_w / 32) + ui_window_x, (window_h / 16) * 14 + margin * 2), window_w / 16 * 3)) {
			{
				se_ui_button.play();
				sub_window_kind = 4;
				flag_sub_window = true;

			}
		}

	
	return page;

}
