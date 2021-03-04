#include<Siv3D.hpp>
#include"Header.h"


void Room01::set_hint_list() {
	for (int i = 0; i < 5; i++) {
		flag[i] = 0;
	}
	hint_list[0] = { U"外に出よう" };
	hint_list[1] = { U"ドアを開けよう" };
	hint_list[2] = { U"足し算の結果を入力してみよう" };
	hint_list[3] = { U"陣がある壁の右下に注目" };
	hint_list[4] = { U"陣の正面の壁の紙に球の配色がかかれているよ" };
}