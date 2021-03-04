#pragma once
#include<Siv3D.hpp>
#define ITEMNUM 15 //�A�C�e���̌�
#define FLAGNUM 7 //�M�~�b�N�֌W�̃t���O�E�q���g�̐�
#define ROOMNUM 2 //�����̐�



class GameSystem {
	//�y�[�W�J�ڗp�̒l�@-2�F�Q�[���N���A�A-1:�Q�[���I���A0:�X�^�[�g�y�[�W�A1:�V�ѕ��A2:Room�I���A3:�Q�[��
private:
	String room_name[ROOMNUM];
	//�\���ʒu�̌v�Z�p�ϐ�
	int window_h;
	int window_w;
	int margin;
	Font title{ 40 };
	Font text_gs{ 20 };
	//�f��
	const Texture image_how_to_play{ U"material/common/how_to_play.png" };
	const Audio bgm_clear{ U"material/common/bgm_02.mp3" ,Arg::loop = true };
	const Audio bgm_any_01{ U"material/common/bgm_01.mp3" ,Arg::loop = true };
	const Audio se_bottun{ U"material/common/se_bottun_01.mp3" };

	bool flag_sub_window;
public:
	double bgm_volume;
	double se_volume;

	GameSystem();
	void set_audio_vlume();
	void display_ui_bottun();
	void play_bgm(int);//�����F�y�[�W�J�ڗp�̒l�@-2: �Q�[���N���A�A0:�X�^�[�g�y�[�W�A1:�V�ѕ��A2:Room�I��
	//�\���ʒu�̌v�Z�p�ϐ��̐ݒ�
	void set_size();
	//�Ԃ�l�F�y�[�W�J�ڗp�̒l
	int start_page();
	int how_to_play();
	int clear_page(int);//�����F����(main��room)
	//�Ԃ�l�F�����I��p�̒l
	int select_room();



};

struct Item {
	String flavour;
	String name;
	Texture icon;
	int status;//-1:���݂��Ȃ��A0:������A1:����ς݁A2:�I�𒆁A3:�g�p�ς�
};
struct Sound {
	String filename;
	int attribute;
};


class Rooms {
protected:
	Item item_list[ITEMNUM];
	String hint_list[FLAGNUM];
	int flag[FLAGNUM];//flag[0]�̓N���A�̃t���O�i�K�������l0�j�@-1:���݂��Ȃ��A0:false�A1:ture

	int wall_num;//�\�����̕ǁi0�`3�j
	bool camera;//���̕\���p�^�[���@0:�ʏ�A1:�Y�[��
	Font title{ 20 };
	Font text{ 15 };
		//�\���ʒu�̌v�Z�p�ϐ�
	int window_h;
	int window_w;
	int margin;
	int flag_item_select;//�����l:-1�A�I�𒆃A�C�e���̃C���f�b�N�X
		//�f��
	const Texture image_how_to_play{ U"material/common/how_to_play.png" };
	const Audio se_ui_button{ U"material/common/se_bottun_01.mp3" };
	const Audio se_item_get{ U"material/common/se_item_01.mp3" };
private:

	int sub_window_kind;//�����l:-1�A�T�u�E�B���h�E�̎�ށ@0:�A�C�e�� 1:�V�ѕ� 2:�q���g 3:���ʐݒ� 4,6:�J�ڊm�F

public:
	bool flag_sub_window;
	double bgm_volume;
	double se_volume;
	Rooms();
	int play_game();

	void set_size();//�\���ʒu�̌v�Z�p�ϐ��̐ݒ�
	
	void rooms_reset();//Rooms�̕ϐ��̏�����
	void vector();//���̑I���A�ǂ̑J��
	void item();//�A�C�e���̕\���A�I��
	int sub_window();//�Ԃ�l�F�y�[�W�J�ڎ��̂݃y�[�W�J�ڗp�̒l�A���̏ꍇ��3�@�����F�T�u�E�B���h�E�̎�ށ@0:�A�C�e�� 1:�V�ѕ� 2:�q���g 3:���ʐݒ� 4,5:�J�ڊm�F
	void ui_button();//�A�C�e���A�y�[�W�J�ڈȊO�̃{�^���̕\����	
	int display_game_ui();//�y�[�W�J�ڂ̃{�^���̕\�����@�Ԃ�l�F�y�[�W�J�ڗp�̒l

	virtual void set_item_list() = 0;
	virtual void set_audio_volume() = 0;
	virtual void set_hint_list() = 0;
	virtual void wall_00()=0;
	virtual void wall_01()=0;
	virtual void wall_02()=0;
	virtual void wall_03()=0;
	virtual void room_reset()=0;//�����̏�����
	virtual void play_bgm(int) = 0;


};


struct Holl
{
	Circle holl;
	int flag;//-1:�����Ȃ��A1�`4:��������͂܂��Ă�(item_list�̃C���f�b�N�X+1)
};
class Room01 : public Rooms {
private:
	//�M�~�b�N�p�ϐ�
	int wall_02_num[3];
	int wall_01_num;
	Holl holl[5];

	//�f��
	const Texture wall_00_01{ U"material/room01/room_01_wall_00_01.png" };
	const Texture wall_00_02{ U"material/room01/room_01_wall_00_02.png" };
	const Texture wall_00_03{ U"material/room01/room_01_wall_00_03.png" };
	const Texture wall_00_04{ U"material/room01/room_01_wall_00_04.png" };
	const Texture wall_00_05{ U"material/room01/room_01_wall_00_05.png" };
	const Texture wall_01_01{ U"material/room01/room_01_wall_01_01.png" };
	const Texture wall_01_02{ U"material/room01/room_01_wall_01_02.png" };
	const Texture wall_02_01{ U"material/room01/room_01_wall_02_01.png" };
	const Texture wall_02_02{ U"material/room01/room_01_wall_02_02.png" };
	const Texture wall_03_01{ U"material/room01/room_01_wall_03_01.png" };
	const Texture wall_03_02{ U"material/room01/room_01_wall_03_02.png" };

	const Texture ball_r{ U"material/room01/room_01_item_ball_r.png" };
	const Texture ball_v{ U"material/room01/room_01_item_ball_v.png" };
	const Texture ball_y{ U"material/room01/room_01_item_ball_y.png" };
	const Texture ball_g{ U"material/room01/room_01_item_ball_g.png" };
	const Texture ball_b{ U"material/room01/room_01_item_ball_b.png" };

	const Audio bgm_01{U"material/room01/bgm_03.mp3",Arg::loop = true };
	const Audio se_lock{U"material/room01/se_door_lock_01.mp3"};
	const Audio se_unlock{ U"material/room01/se_door_unlock_02.mp3" };
	const Audio se_bottun_panel{ U"material/room01/se_bottun_02.mp3" };
	const Audio se_ball{ U"material/room01/se_grap_01.mp3" };

public:
	Room01();
	void set_item_list();//item_list�̏������i�Ή��t���j
	void set_audio_volume();
	void set_hint_list();//hint�̏�����
	void room_reset();//�����̏�����
	void play_bgm(int);//�����F�y�[�W�J�ڗp�̒l�@-2: �Q�[���N���A�A0:�X�^�[�g�y�[�W�A1:�V�ѕ��A2:Room�I��
	//���X�ǖ��̃M�~�b�N
	void wall_00();
	void wall_01();
	void wall_02();
	void wall_03();





};


class Room02 : public Rooms {
private:
	//�M�~�b�N�p�ϐ�
	bool night;//false:���Atrue:��
	int wall_01_num;
	int flag_wall_01;//-1:���I���A0�`5:�O�ɑI�������{�^��

	//�f��
	const Texture wall_00_01{ U"material/room02/room_02_wall_00_01.png" };
	const Texture wall_00_02{ U"material/room02/room_02_wall_00_02.png" };
	const Texture wall_00_03{ U"material/room02/room_02_wall_00_03.png" };
	const Texture wall_00_04{ U"material/room02/room_02_wall_00_04.png" };
	
	const Texture wall_01_01{ U"material/room02/room_02_wall_01_01.png" };

	const Texture wall_02_01{ U"material/room02/room_02_wall_02_01.png" };
	const Texture wall_02_02{ U"material/room02/room_02_wall_02_02.png" };

	const Texture wall_03_01{ U"material/room02/room_02_wall_03_01.png" };
	const Texture wall_03_02{ U"material/room02/room_02_wall_03_02.png" };
	const Texture wall_03_03{ U"material/room02/room_02_wall_03_03.png" };


	const Texture key{ U"material/room02/room_02_item_key.png" };


	const Audio bgm_01{ U"material/room02/bgm_04.mp3",Arg::loop = true };
	const Audio se_lock{ U"material/room02/se_door_lock_02.mp3" };
	const Audio se_unlock{ U"material/room02/se_door_unlock_01.mp3" };
	const Audio se_bottun_panel{ U"material/room02/se_bottun_03.mp3" };
	const Audio se_item_drop{ U"material/room02/se_grap_01.mp3" };

public:
	Room02();
	void set_item_list();//item_list�̏������i�Ή��t���j
	void set_audio_volume();
	void set_hint_list();//hint�̏�����
	void room_reset();//�����̏�����
	void play_bgm(int);//�����F�y�[�W�J�ڗp�̒l�@-2: �Q�[���N���A�A0:�X�^�[�g�y�[�W�A1:�V�ѕ��A2:Room�I��
	//���X�ǖ��̃M�~�b�N
	void wall_00();
	void wall_01();
	void wall_02();
	void wall_03();





};