#include<Siv3D.hpp>
#include"Header.h"


int GameSystem::start_page() {
	int button_h = window_h / 8 + margin;
	String game_title = {U"脱出ゲーム"};
	double font_l = (double)game_title.length() / 2.0;
	double title_x = (double)window_w / 2.0 - (double)title.fontSize() * font_l;
	double title_y = (double)window_h / 4.0 - (double)title.height() / 2.0;

	if (!flag_sub_window) {
		title(game_title).drawAt(window_w / 2, window_h / 4 + margin/2, ColorF(0.0, 0.0, 0.0, 0.5));
		for (int i = 0; i < game_title.length(); i++) {
			title(game_title[i]).draw(title_x+i*title.fontSize(), title_y,HSV(360/(font_l*2)*(i+1),1.0, 1.0));
		}
		

		text_gs(U"音楽・効果音：魔王魂").drawAt(window_w / 4 * 3, window_h / 16 * 15, Palette::Black);
		if (SimpleGUI::Button(U"ゲームスタート", Vec2(window_w / 3, window_h / 2), window_w / 3)) {
			{
				se_bottun.play();
				return 2;
			}
		}
		if (SimpleGUI::Button(U"遊び方", Vec2(window_w / 3, window_h / 2 + button_h), window_w / 3)) {
			{
				se_bottun.play();
				return 1;
			}
		}
		if (SimpleGUI::Button(U"終了", Vec2(window_w / 3, window_h / 2 + button_h * 2), window_w / 3)) {
			{
				
				return -1;
			}
		}
	}

	return 0;

}
