#pragma once
#include<Siv3D.hpp>
#define ITEMNUM 15 //アイテムの個数
#define FLAGNUM 7 //ギミック関係のフラグ・ヒントの数
#define ROOMNUM 2 //部屋の数



class GameSystem {
	//ページ遷移用の値　-2：ゲームクリア、-1:ゲーム終了、0:スタートページ、1:遊び方、2:Room選択、3:ゲーム
private:
	String room_name[ROOMNUM];
	//表示位置の計算用変数
	int window_h;
	int window_w;
	int margin;
	Font title{ 40 };
	Font text_gs{ 20 };
	//素材
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
	void play_bgm(int);//引数：ページ遷移用の値　-2: ゲームクリア、0:スタートページ、1:遊び方、2:Room選択
	//表示位置の計算用変数の設定
	void set_size();
	//返り値：ページ遷移用の値
	int start_page();
	int how_to_play();
	int clear_page(int);//引数：部屋(mainのroom)
	//返り値：部屋選択用の値
	int select_room();



};

struct Item {
	String flavour;
	String name;
	Texture icon;
	int status;//-1:存在しない、0:未入手、1:入手済み、2:選択中、3:使用済み
};
struct Sound {
	String filename;
	int attribute;
};


class Rooms {
protected:
	Item item_list[ITEMNUM];
	String hint_list[FLAGNUM];
	int flag[FLAGNUM];//flag[0]はクリアのフラグ（必ず初期値0）　-1:存在しない、0:false、1:ture

	int wall_num;//表示中の壁（0～3）
	bool camera;//矢印の表示パターン　0:通常、1:ズーム
	Font title{ 20 };
	Font text{ 15 };
		//表示位置の計算用変数
	int window_h;
	int window_w;
	int margin;
	int flag_item_select;//初期値:-1、選択中アイテムのインデックス
		//素材
	const Texture image_how_to_play{ U"material/common/how_to_play.png" };
	const Audio se_ui_button{ U"material/common/se_bottun_01.mp3" };
	const Audio se_item_get{ U"material/common/se_item_01.mp3" };
private:

	int sub_window_kind;//初期値:-1、サブウィンドウの種類　0:アイテム 1:遊び方 2:ヒント 3:音量設定 4,6:遷移確認

public:
	bool flag_sub_window;
	double bgm_volume;
	double se_volume;
	Rooms();
	int play_game();

	void set_size();//表示位置の計算用変数の設定
	
	void rooms_reset();//Roomsの変数の初期化
	void vector();//矢印の選択、壁の遷移
	void item();//アイテムの表示、選択等
	int sub_window();//返り値：ページ遷移時のみページ遷移用の値、他の場合は3　引数：サブウィンドウの種類　0:アイテム 1:遊び方 2:ヒント 3:音量設定 4,5:遷移確認
	void ui_button();//アイテム、ページ遷移以外のボタンの表示等	
	int display_game_ui();//ページ遷移のボタンの表示等　返り値：ページ遷移用の値

	virtual void set_item_list() = 0;
	virtual void set_audio_volume() = 0;
	virtual void set_hint_list() = 0;
	virtual void wall_00()=0;
	virtual void wall_01()=0;
	virtual void wall_02()=0;
	virtual void wall_03()=0;
	virtual void room_reset()=0;//部屋の初期化
	virtual void play_bgm(int) = 0;


};


struct Holl
{
	Circle holl;
	int flag;//-1:何もない、1～4:何かしらはまってる(item_listのインデックス+1)
};
class Room01 : public Rooms {
private:
	//ギミック用変数
	int wall_02_num[3];
	int wall_01_num;
	Holl holl[5];

	//素材
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
	void set_item_list();//item_listの初期化（対応付け）
	void set_audio_volume();
	void set_hint_list();//hintの初期化
	void room_reset();//部屋の初期化
	void play_bgm(int);//引数：ページ遷移用の値　-2: ゲームクリア、0:スタートページ、1:遊び方、2:Room選択
	//其々壁毎のギミック
	void wall_00();
	void wall_01();
	void wall_02();
	void wall_03();





};


class Room02 : public Rooms {
private:
	//ギミック用変数
	bool night;//false:昼、true:夜
	int wall_01_num;
	int flag_wall_01;//-1:未選択、0～5:前に選択したボタン

	//素材
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
	void set_item_list();//item_listの初期化（対応付け）
	void set_audio_volume();
	void set_hint_list();//hintの初期化
	void room_reset();//部屋の初期化
	void play_bgm(int);//引数：ページ遷移用の値　-2: ゲームクリア、0:スタートページ、1:遊び方、2:Room選択
	//其々壁毎のギミック
	void wall_00();
	void wall_01();
	void wall_02();
	void wall_03();





};