#include<Siv3D.hpp>
#include"Header.h"


int GameSystem::select_room() {
	int button_h = window_h / 8 + margin;
	String room_name;

	title(U"•”‰®‚ð‘I‚ñ‚Å‚Ë").drawAt(window_w / 2, window_h / 8, Palette::Black);
	if (!flag_sub_window) {
		for (int i = 0; i < ROOMNUM; i++) {
			room_name = U"Room" + Format(i + 1);
			if (SimpleGUI::Button(room_name, Vec2(window_w * ((i % 3) * 5 + 1) / 15, window_h * (6 + (i/3)) / 24 + margin), window_w / 5)) {
				{
					se_bottun.playOneShot(se_volume);
					return i + 1;
				}
			}
		}


		if (SimpleGUI::Button(U"–ß‚é", Vec2(window_w / 8 * 3, window_h / 8 * 7 + margin), window_w / 4)) {
			{
				se_bottun.play();
				return 0;
			}
		}
	}

	return -1;

}
