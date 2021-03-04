#include<Siv3D.hpp>
#include"Header.h"


int GameSystem::how_to_play() {
	

	Rect(window_w/16+margin,window_h/16+margin,window_w/8*7-2*margin,window_h/4*3-2*margin)(image_how_to_play).draw();
	if (SimpleGUI::Button(U"–ß‚é", Vec2(window_w/8*3,window_h/8*7+margin), window_w / 4)) {
		{
			se_bottun.play();
			return 0;
		}
	}
	
	return 1;

}
