#include<Siv3D.hpp>
#include"Header.h"


void Room02::set_hint_list() {
	for (int i = 0; i < 7; i++) {
		flag[i] = 0;
	}
	hint_list[0] = { U"外に出よう" };
	hint_list[1] = { U"ドアを開けよう" };
	hint_list[2] = { U"鍵でドアを開けよう" };
	hint_list[3] = { U"落ちている鍵を探そう" };
	hint_list[4] = { U"モニタにボタンを押す順番が描かれているよ" };
	hint_list[5] = { U"モニタを見てから月のパネルを押そう" };
	hint_list[6] = { U"太陽のパネルを押そう" };
}