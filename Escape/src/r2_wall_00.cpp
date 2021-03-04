#include<Siv3D.hpp>
#include"Header.h"


void Room02::wall_00() {
    Rect back_ground(0, 0, window_w / 4 * 3, window_h);
    Rect door(window_w / 2, window_h / 2, window_w / 8, window_h / 3);

    flag_wall_01 = -1;


   if (flag[1] == 1) {
   
        if (!night) {
            back_ground(wall_00_04).draw();
        }
        else {
            back_ground(wall_00_03).draw();
        }
        if (door.leftClicked()) {
            flag[0] = 1;
        }
    }
   else if (flag[2] == 1) {
       if (!night) {
           back_ground(wall_00_02).draw();
       }
       else {
           back_ground(wall_00_01).draw();
       }
       if (door.leftClicked()) {
               flag[1] = 1;
               se_unlock.play();
       }
   }else{
       if (!night) {
           back_ground(wall_00_02).draw();
       }
       else {
           back_ground(wall_00_01).draw();
       }
       if (door.leftClicked()) {
           if (item_list[0].status == 2) {
               flag[2] = 1;
               item_list[0].status = 3;
               flag_item_select = -1;
               se_unlock.play();
           }
           else {
               se_unlock.playOneShot(se_volume);
           }
       }
    }



}