#include<Siv3D.hpp>
#include"Header.h"


void Room02::play_bgm(int page) {
	
	if (bgm_01.isPlaying()) {
		if (page != 3) {
			bgm_01.stop();
		}
	}
	else {
		if (page == 3) {
			bgm_01.play();
		}
	}

}