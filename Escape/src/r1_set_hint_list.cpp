#include<Siv3D.hpp>
#include"Header.h"


void Room01::set_hint_list() {
	for (int i = 0; i < 5; i++) {
		flag[i] = 0;
	}
	hint_list[0] = { U"�O�ɏo�悤" };
	hint_list[1] = { U"�h�A���J���悤" };
	hint_list[2] = { U"�����Z�̌��ʂ���͂��Ă݂悤" };
	hint_list[3] = { U"�w������ǂ̉E���ɒ���" };
	hint_list[4] = { U"�w�̐��ʂ̕ǂ̎��ɋ��̔z�F��������Ă����" };
}