#include<Siv3D.hpp>
#include"Header.h"


void Rooms::vector() {
	int left_x = window_w/32+margin;
	int right_x = window_w / 32 * 23-margin;
	int back_y = window_h / 32 * 31;
	int size = window_w / 23;
	Triangle out( (left_x + right_x) / 2, back_y, size, 60_deg );
	Triangle left(left_x, window_h / 2, size, 30_deg);
	Triangle right(right_x, window_h / 2, size, -30_deg);


	if (camera) {//ÉAÉbÉvéû
		out.draw(out.mouseOver() ?  Palette::Gray:Palette::Blue);
		if (out.leftClicked()) {
			camera = false;
		}



	}
	else {//í èÌéû
		left.draw(left.mouseOver() ? Palette::Gray : Palette::Blue);
		right.draw(right.mouseOver() ? Palette::Gray : Palette::Blue);

		if (left.leftClicked()) {
			wall_num --;
			if (wall_num < 0) {
				wall_num = 3;
			}
			else {
				wall_num = wall_num % 4;
			}
		}
		if (right.leftClicked()) {
			wall_num = (wall_num + 1) % 4;
		}



	}



	





}