#include<Siv3D.hpp>
#include"Header.h"


void Room02::set_hint_list() {
	for (int i = 0; i < 7; i++) {
		flag[i] = 0;
	}
	hint_list[0] = { U"�O�ɏo�悤" };
	hint_list[1] = { U"�h�A���J���悤" };
	hint_list[2] = { U"���Ńh�A���J���悤" };
	hint_list[3] = { U"�����Ă��錮��T����" };
	hint_list[4] = { U"���j�^�Ƀ{�^�����������Ԃ��`����Ă����" };
	hint_list[5] = { U"���j�^�����Ă��猎�̃p�l����������" };
	hint_list[6] = { U"���z�̃p�l����������" };
}