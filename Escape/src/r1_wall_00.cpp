#include<Siv3D.hpp>
#include"Header.h"


void Room01::wall_00() {
    String panel_display_num;
    Rect back_ground(0, 0, window_w / 4 * 3, window_h);
    Rect door(window_w / 2, window_h / 2, window_w / 8, window_h / 3);
    Rect panel_up(window_w / 5, window_h / 5, window_w / 48 * 15, window_h / 24 * 15);
    Rect panel_down(door.x + door.w / 8 * 5, door.y + door.h / 2, door.w / 6, door.h / 8);
    Rect panel_button[12];
    Rect panel_monitor(panel_up.x + panel_up.w / 6, panel_up.y + panel_up.h / 8, panel_up.w / 3 * 2, panel_up.h / 8);
    Circle c_item(window_w / 3, window_h / 8 * 7, window_h / 43);

    if (flag[1] == 1) {
   
        if (flag[3] == 1) {
            back_ground(wall_00_04).draw();
        }
        else {
            back_ground(wall_00_05).draw();
        }
        if (door.leftClicked()) {
            flag[0] = 1;
        }
    }
    else if (flag[2] == 1) {
        if (camera) {
            back_ground(wall_00_02).draw();
            text(U"7654").draw(panel_monitor, Palette::White);
        }
        else {

            if (flag[3] == 1) {
                back_ground(wall_00_03).draw();
            }
            else {
                back_ground(wall_00_01).draw();
            }

            if (panel_down.leftClicked()) {
                camera = true;
            }
            else if (door.leftClicked()) {
                se_unlock.playOneShot(se_volume);
                flag[1] = 1;
            }
        }
    }
    else{
        if (camera) {
            back_ground(wall_00_02).draw();
            for (int i = 0; i < 12; i++) {
                panel_button[i].w = panel_up.w / 3;
                panel_button[i].h = panel_up.h / 16 * 3;
                panel_button[i].x = panel_up.x + panel_button[i].w * (i % 3);
                panel_button[i].y = panel_up.y + panel_up.h - panel_button[i].h * ((int)(i / 3) + 1);
 
                if (panel_button[i].leftClicked()) {
                    se_bottun_panel.playOneShot(se_volume);
                    if (i >= 3) {
                        if (wall_01_num <= 999) {
                            wall_01_num = wall_01_num * 10 + i - 2;
                        }
                    }
                    else if (i == 1) {
                        if (wall_01_num < 10000) {
                            wall_01_num = wall_01_num * 10;
                        }
                    }
                    else if (i == 0) {
                        wall_01_num = wall_01_num / 10;
                    }
                    else {
                        wall_01_num = 0;
                    }
                }

            }
            if (back_ground.leftClicked() && (!panel_up.leftClicked())) {
                se_lock.playOneShot(se_volume);
            }

            panel_display_num = Format(wall_01_num);
            text(panel_display_num).draw(panel_monitor, Palette::White);
        }
        else {
            if (flag[3] == 1) {
                back_ground(wall_00_03).draw();
            }
            else {
                back_ground(wall_00_01).draw();
            }
  
            if (panel_down.leftClicked()) {
                camera = true;
            }
            if (door.leftClicked()) {
                se_lock.playOneShot(se_volume);
            }
        }
        if (wall_01_num == 7654) {
            flag[2] = 1;
            se_unlock.playOneShot(se_volume);
        }
    }


    if (!camera) {
        if (item_list[0].status == 0) {
            c_item(item_list[0].icon(10, 10, 90, 90)).draw();
            if (c_item.leftClicked()) {
                item_list[0].status = 2;
                flag_item_select = 0;
                se_item_get.playOneShot(se_volume);
            }
        }
    }
}