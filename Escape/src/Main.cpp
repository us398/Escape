
# include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include"Header.h"

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));





	GameSystem gs;
	Room01 r01;
	Room02 r02;


	int page = 0;
	int room = 0;
	bool flag_page_change = false;


	while (System::Update())
	{
		
		gs.set_size();

		gs.play_bgm(page);
		switch (page)
		{
		case 0://start page
			if (flag_page_change) {
				switch (room)
				{
				case 1:
					gs.bgm_volume=r01.bgm_volume;
					gs.se_volume=r01.se_volume;
					break;
				case 2:
					gs.bgm_volume = r02.bgm_volume;
					gs.se_volume = r02.se_volume;
					break;
				default:
					break;
				}
				flag_page_change = false;
			}
			room = 0;
			page=gs.start_page();
			gs.display_ui_bottun();
			gs.set_audio_vlume();
			break;
		case 1://how to play
			page = gs.how_to_play();
			break;
		case 2://selsect room
			if (flag_page_change) {
				switch (room)
				{
				case 1:
					gs.bgm_volume = r01.bgm_volume;
					gs.se_volume = r01.se_volume;
					break;
				case 2:
					gs.bgm_volume = r02.bgm_volume;
					gs.se_volume = r02.se_volume;
					break;
				default:
					break;
				}
				flag_page_change = false;
			}
			room = gs.select_room();
			gs.display_ui_bottun();
			gs.set_audio_vlume();
			if (room >= 1) {//どれかの部屋を選んだら
				page = 3;
				switch (room)
				{
				case 1:
					r01.room_reset();
					r01.set_item_list();
					r01.set_hint_list();
					r01.bgm_volume = gs.bgm_volume;
					r01.se_volume = gs.se_volume;
					r01.set_audio_volume();
					break;
				case 2:
					r02.room_reset();
					r02.set_item_list();
					r02.set_hint_list();
					r02.bgm_volume = gs.bgm_volume;
					r02.se_volume = gs.se_volume;
					r02.set_audio_volume();
					break;
				default:
					break;
				}
			}
			else if(room == 0) {
				page = room;
			}
			break;
		case 3://game
			
			switch (room)
			{
			case 1:
				page = r01.play_game();
				break;
			case 2:
				page = r02.play_game();
				break;
			default:
				break;
			}
			if (page != 3) {
				flag_page_change = true;
			}
			break;
		case -1://exit
			System::Exit();
			break;
		case -2://clear
			if (flag_page_change) {
				switch (room)
				{
				case 1:
					gs.bgm_volume = r01.bgm_volume;
					gs.se_volume = r01.se_volume;
					break;
				case 2:
					gs.bgm_volume = r02.bgm_volume;
					gs.se_volume = r02.se_volume;
					break;
				default:
					break;
				}
				flag_page_change = false;
			}
			page=gs.clear_page(room);
			gs.display_ui_bottun();
			gs.set_audio_vlume();
			break;
		default:
			break;
		}



	}
}
