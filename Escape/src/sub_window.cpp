#include<Siv3D.hpp>
#include"Header.h"


int Rooms::sub_window() {
	int left_x = window_w / 32 + margin;
	int right_x = window_w / 32 * 23 - margin;
	int back_y = window_h / 32 * 31;
	int size = window_w / 23;

	int size_item = window_w / 16;
	int button_x = window_w / 4 * 3 + window_w / 32 - margin;
	int button_size = size_item + margin;
	int button_y = window_h / 8;
	int curve_size = size_item / 6;

	int ui_button_x = window_w / 32 * 25;

	int sub_window_w = window_w / 8 * 5;
	int sub_window_x = window_w / 16;
	int tmp = -2;

	Rect(window_w / 4 * 3, 0, window_w / 4, window_h).draw(ColorF(0.5, 0.5, 0.0, 1.0));
	RoundRect((window_w / 32) + window_w / 4 * 3, (window_h / 16) * 13 + margin, window_w / 16 * 3, window_h / 16, margin).draw(Palette::White);
	RoundRect((window_w / 32) + window_w / 4 * 3, (window_h / 16) * 14 + margin * 2, window_w / 16 * 3, window_h / 16, margin).draw(Palette::White);


	for (int i = 0; i < ITEMNUM; i++) {
		if (item_list[i].status == -1) {
			break;
		}
		else {
			RoundRect rect(button_x + button_size * (i % 3), button_y + button_size * (int)(i / 3), size_item, size_item, curve_size);
			rect.draw();
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

		RoundRect(ui_button_x - margin, window_h / 32, window_w / 16, window_h / 16, margin).draw(Palette::White);
		RoundRect(ui_button_x + window_w / 16, window_h / 32, window_w / 16, window_h / 16, margin).draw(Palette::White);
		RoundRect(ui_button_x + window_w / 16 * 2 + margin, window_h / 32, window_w / 16, window_h / 16, margin).draw(Palette::White);



	
	if (camera == 1) {//アップ時
		Triangle((left_x + right_x) / 2, back_y, size, 60_deg).draw(Palette::Blue);
	}
	else {//通常時
		Triangle(left_x, window_h / 2, size, 30_deg).draw(Palette::Blue);
		Triangle(right_x, window_h / 2, size, -30_deg).draw(Palette::Blue);
	}
	Rect(0, 0, window_w / 4 * 3, window_h).draw(ColorF(0.0, 0.3, 0.5, 1.0));
	Rect(0, 0, window_w , window_h).draw(ColorF(0.0, 0.0, 0.0, 0.5));




	double radio= 1.0;
	double radio_2 = 1.0;
	//サブウィンドウ表示
	//サブウィンドウの種類　0:アイテム 1:遊び方 2:ヒント 3:音量設定
	switch (sub_window_kind)
	{
	case 0://アイテムの詳細ウィンドウ
		Rect sub_sub_window(window_w / 16, window_h / 8, window_w / 8 * 5, window_h / 3 * 2);
		Rect icon(sub_sub_window.x + sub_sub_window.w / 4, sub_sub_window.y + sub_sub_window.h / 4, sub_sub_window.w / 2, sub_sub_window.h / 2);
		Rect text_box_0(sub_sub_window.x + sub_sub_window.w / 8, sub_sub_window.y + sub_sub_window.h / 8 * 6, sub_sub_window.w / 8 * 6, sub_sub_window.h / 8);

		sub_sub_window.draw();

		radio = (double)item_list[flag_item_select].icon.width() / (double)item_list[flag_item_select].icon.height();
		if (radio >= 1.0) {
			tmp = icon.h;
			icon.h = (double)icon.w / radio;
			icon.y = sub_sub_window.y + sub_sub_window.h / 4 + (sub_sub_window.h / 2 - icon.h) / 2;
			if (icon.h > tmp) {
				radio_2 = (double)tmp / (double)icon.h;
				icon.h = icon.h * radio_2;
				icon.w = icon.w * radio_2;
				icon.x = sub_sub_window.x + (sub_sub_window.w - icon.w) / 2;
				icon.y = sub_sub_window.y + sub_sub_window.h / 4 + (sub_sub_window.h / 2 - icon.h) / 2;
			}
		}
		else {
			tmp = icon.w;
			icon.w = (double)icon.h * radio;
			icon.x = sub_sub_window.x + sub_sub_window.w / 4;
			if (icon.w > tmp) {
				radio_2 = (double)tmp / (double)icon.w;
				icon.h = icon.h * radio_2;
				icon.w = icon.w * radio_2;
				icon.x = sub_sub_window.x + (sub_sub_window.w - icon.w) / 2;
				icon.y = sub_sub_window.y + sub_sub_window.h / 4 + (sub_sub_window.h / 2 - icon.h) / 2;
			}
		}
		icon(item_list[flag_item_select].icon).draw();
		title(item_list[flag_item_select].name).drawAt(sub_sub_window.x + sub_sub_window.w / 2, sub_sub_window.y + sub_sub_window.h / 8, ColorF(0.0, 0.0, 0.0, 1.0));
		text(item_list[flag_item_select].flavour).draw(text_box_0, ColorF(0.0, 0.0, 0.0, 1.0));
		if (SimpleGUI::ButtonAt(U"閉じる", Vec2(window_w / 8 * 3, window_h / 16 * 11))) {
			se_ui_button.play();
			flag_sub_window = false;
			sub_window_kind = -1;
			item_list[flag_item_select].status = 1;
			flag_item_select = -1;
			
		}
		break;

	case 1://遊び方
		Rect(window_w / 16, window_h / 16, window_w / 8 * 7, window_h / 8*7).draw();
		Rect(window_w / 16+margin, window_h / 16+margin, window_w / 8 * 7-2*margin, window_h / 8 * 6-2*margin)(image_how_to_play).draw();
		if (SimpleGUI::ButtonAt(U"閉じる", Vec2(window_w / 2, window_h / 16 * 14))) {
			se_ui_button.play();
			flag_sub_window = false;
			sub_window_kind = -1;
		}
		break;
	case 2://ヒント
		Rect(window_w / 16, window_h / 4, window_w / 8 * 5, window_h / 2).draw();
		Rect text_box_2(window_w / 16 * 2, window_h / 8 * 3, window_w / 8 * 4, window_h / 4);

		title(U"ヒント").drawAt(window_w / 8 * 3, window_h / 16 * 5, ColorF(0.0, 0.0, 0.0, 1.0));
		for (int i = 1; i < FLAGNUM; i++) {
			if (flag[i] == 1||flag[i]==-1) {
				text(hint_list[i - 1]).draw(text_box_2, ColorF(0.0, 0.0, 0.0, 1.0));
				break;
			}else if(i==FLAGNUM-1){
				text(hint_list[i]).draw(text_box_2, ColorF(0.0, 0.0, 0.0, 1.0));
			}
		}
		if (SimpleGUI::ButtonAt(U"閉じる", Vec2(window_w / 8 * 3, window_h / 16 * 11))) {
			se_ui_button.play();
			flag_sub_window = false;
			sub_window_kind = -1;
		}

		break;
	case 3://音量調整
		Rect(window_w / 16, window_h / 4, window_w / 8 * 5, window_h / 2).draw();
		SimpleGUI::Slider(U"BGM", bgm_volume, Vec2(window_w / 8, window_h / 8 * 3), window_w / 8, window_w / 8 * 3);
		if (SimpleGUI::Slider(U"SE", se_volume, Vec2(window_w / 8, window_h / 8 * 4), window_w / 8, window_w / 8 * 3)) {
				se_ui_button.playOneShot(se_volume);
		}

		if (SimpleGUI::ButtonAt(U"閉じる", Vec2(window_w / 8 * 3, window_h / 16 * 11))) {
			
			flag_sub_window = false;
			sub_window_kind = -1;
			se_ui_button.play();
		}

		break;
	case 4:
	case 6://ページ遷移
		Rect(sub_window_x, window_h / 4, sub_window_w, window_h / 2).draw();

		if (sub_window_kind == 4) {
			title(U"スタートページに戻りますか？").drawAt(sub_window_w / 2 + sub_window_x, window_h / 8 * 3, ColorF(0.0, 0.0, 0.0, 1.0));
		}
		else {
			title(U"部屋選択画面に戻りますか？").drawAt(sub_window_w / 2 + sub_window_x, window_h / 8 * 3, ColorF(0.0, 0.0, 0.0, 1.0));
		}
		text(U"※遊んでいたデータは失われます").drawAt(sub_window_w / 2 + sub_window_x, window_h / 2,Palette::Red);
		if (SimpleGUI::ButtonAt(U"はい", Vec2(sub_window_w / 4 + sub_window_x, window_h / 16 * 11))) {
			se_ui_button.play();
			flag_sub_window = false;
			tmp = sub_window_kind;
			sub_window_kind = -1;
			return tmp - 4;
		}
		if (SimpleGUI::ButtonAt(U"いいえ", Vec2(sub_window_w / 4 * 3 + sub_window_x, window_h / 16 * 11))) {
			se_ui_button.play();
			flag_sub_window = false;
			sub_window_kind = -1;
		}
		break;

	default:
		break;
	}


	return 3;
}