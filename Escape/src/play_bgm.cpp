
#include<Siv3D.hpp>
#include"Header.h"


void GameSystem::play_bgm(int page) {
	if (bgm_clear.isPlaying()) {
		if (page != -2) {
			bgm_clear.stop();
		}
	}
	else if (bgm_any_01.isPlaying()) {
		if (page ==-2||page==3) {
			bgm_any_01.stop();
		}
	}
	else {
		switch (page)
		{
		case 0:
		case 1:
		case 2:
			bgm_any_01.play();
			break;
		case -2:
			bgm_clear.play();
			break;
		default:
			break;
		}
	}


}
