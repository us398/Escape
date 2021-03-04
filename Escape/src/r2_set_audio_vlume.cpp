

#include<Siv3D.hpp>
#include"Header.h"


void Room02::set_audio_volume() {

		bgm_01.setVolume(bgm_volume);

		se_ui_button.setVolume(se_volume);
		se_item_get.setVolume(se_volume);
		
		se_unlock.setVolume(se_volume);
		se_bottun_panel.setVolume(se_volume);
		se_lock.setVolume(se_volume);
		se_item_drop.setVolume(se_volume);
}