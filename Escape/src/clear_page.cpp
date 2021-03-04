#include<Siv3D.hpp>
#include"Header.h"


int GameSystem::clear_page(int room) {
	String clear_message;
	clear_message = U"Room" + Format(room) + U" CLEAR !!";
	double font_l = (double)clear_message.length() / 2.0;
	double title_x = (double)window_w / 2.0 - (double)title.fontSize() * font_l;
	double title_y = (double)window_h / 2.0 - (double)title.height() / 2.0;

	if (!flag_sub_window) {
		for (int i = 0; i < clear_message.length(); i++) {
			title(clear_message[i]).draw(title_x + i * title.fontSize() + margin / 2, title_y + margin / 2);
			title(clear_message[i]).draw(title_x + i * title.fontSize() - margin / 2, title_y - margin / 2);
			title(clear_message[i]).draw(title_x + i * title.fontSize(), title_y, HSV(360 / (font_l * 2) * (i + 1), 1.0, 1.0));
			
		}
	


		if (SimpleGUI::ButtonAt(U"スタートページ", Vec2(window_w / 4, window_h / 8 * 7 + margin), window_w / 5)) {
			{
				se_bottun.play();
				return 0;
			}
		}
		if (SimpleGUI::ButtonAt(U"部屋選択へ", Vec2(window_w / 4 * 2, window_h / 8 * 7 + margin), window_w / 5)) {
			{
				se_bottun.play();
				return 2;
			}
		}
		if (SimpleGUI::ButtonAt(U"終了", Vec2(window_w / 4 * 3, window_h / 8 * 7 + margin), window_w / 5)) {
			{
				
				return -1;
			}
		}
	}

	return -2;

}
