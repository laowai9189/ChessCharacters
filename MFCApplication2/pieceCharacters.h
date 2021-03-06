#include "stdafx.h"
#include "chessCharacters.h"
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

const int position_value[14][10][9] =
{
	{//黑车
		{ 194,206,204,212,200,212,204,206,194 },
		{ 200,208,206,212,200,212,206,208,200 },
		{ 198,208,204,212,212,212,204,208,198 },
		{ 204,209,204,212,214,212,204,209,204 },
		{ 208,212,212,214,215,214,212,212,208 },
		{ 208,211,211,214,215,214,211,211,208 },
		{ 206,213,213,216,216,216,213,213,206 },
		{ 206,208,207,214,216,214,207,208,206 },
		{ 206,212,209,216,233,216,209,212,206 },
		{ 206,208,207,213,214,213,207,208,206 }
	},
	{//黑马
		{ 88, 85, 90, 88, 90, 88, 90, 85, 88 },
		{ 85, 90, 92, 93, 78, 93, 92, 90, 85 },
		{ 93, 92, 94, 95, 92, 95, 94, 92, 93 },
		{ 92, 94, 98, 95, 98, 95, 98, 94, 92 },
		{ 90, 98,101,102,103,102,101, 98, 90 },
		{ 90,100, 99,103,104,103, 99,100, 90 },
		{ 93,108,100,107,100,107,100,108, 93 },
		{ 92, 98, 99,103, 99,103, 99, 98, 92 },
		{ 90, 96,103, 97, 94, 97,103, 96, 90 },
		{ 90, 90, 90, 96, 90, 96, 90, 90, 90 }
	},
	{//黑象
		{ 0,  0, 20,  0,  0,  0, 20,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{18,  0,  0,  0, 23,  0,  0,  0, 18 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0, 20,  0,  0,  0, 20,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 }
	},
	{//黑士
		{ 0,  0,  0, 20,  0, 20,  0,  0,  0 },
		{ 0,  0,  0,  0, 23,  0,  0,  0,  0 },
		{ 0,  0,  0, 20,  0, 20,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 }
	},
	{//黑将
		{ 0,  0,  0, 11, 15, 11,  0,  0,  0 },
		{ 0,  0,  0,  2,  2,  2,  0,  0,  0 },
		{ 0,  0,  0,  1,  1,  1,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 }
	},
	{//黑炮
		{ 96, 96, 97, 99, 99, 99, 97, 96, 96 },
		{ 96, 97, 98, 98, 98, 98, 98, 97, 96 },
		{ 97, 96,100, 99,101, 99,100, 96, 97 },
		{ 96, 96, 96, 96, 96, 96, 96, 96, 96 },
		{ 95, 96, 99, 96,100, 96, 99, 96, 95 },
		{ 96, 96, 96, 96,100, 96, 96, 96, 96 },
		{ 96, 99, 99, 98,100, 98, 99, 99, 96 },
		{ 97, 97, 96, 91, 92, 91, 96, 97, 97 },
		{ 98, 98, 96, 92, 89, 92, 96, 98, 98 },
		{100,100, 96, 91, 90, 91, 96,100,100 }
	},
	{//黑卒
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 7,  0,  7,  0, 15,  0,  7,  0,  7 },
		{ 7,  0, 13,  0, 16,  0, 13,  0,  7 },
		{19, 27, 31, 44, 49, 44, 31, 27, 19 },
		{29, 36, 39, 49, 51, 49, 39, 36, 29 },
		{29, 39, 54, 64, 64, 64, 54, 39, 29 },
		{29, 39, 59, 74, 79, 74, 59, 39, 29 },
		{ 9,  9,  9, 11, 13, 11,  9,  9,  9 }
	},
	{//红兵
		{ 9,  9,  9, 11, 13, 11,  9,  9,  9 },
		{29, 39, 59, 74, 79, 74, 59, 39, 29 },
		{29, 39, 54, 64, 64, 64, 54, 39, 29 },
		{29, 36, 39, 49, 51, 49, 39, 36, 29 },
		{19, 27, 31, 44, 49, 44, 31, 27, 19 },
		{ 7,  0, 13,  0, 16,  0, 13,  0,  7 },
		{ 7,  0,  7,  0, 15,  0,  7,  0,  7 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 }
	},
	{//红炮
		{100,100, 96, 91, 90, 91, 96,100,100 },
		{ 98, 98, 96, 92, 89, 92, 96, 98, 98 },
		{ 97, 97, 96, 91, 92, 91, 96, 97, 97 },
		{ 96, 99, 99, 98,100, 98, 99, 99, 96 },
		{ 96, 96, 96, 96,100, 96, 96, 96, 96 },
		{ 95, 96, 99, 96,100, 96, 99, 96, 95 },
		{ 96, 96, 96, 96, 96, 96, 96, 96, 96 },
		{ 97, 96,100, 99,101, 99,100, 96, 97 },
		{ 96, 97, 98, 98, 98, 98, 98, 97, 96 },
		{ 96, 96, 97, 99, 99, 99, 97, 96, 96 }
	},
	{//红车
		{ 206,208,207,213,214,213,207,208,206 },
		{ 206,212,209,216,233,216,209,212,206 },
		{ 206,208,207,214,216,214,207,208,206 },
		{ 206,213,213,216,216,216,213,213,206 },
		{ 208,211,211,214,215,214,211,211,208 },
		{ 208,212,212,214,215,214,212,212,208 },
		{ 204,209,204,212,214,212,204,209,204 },
		{ 198,208,204,212,212,212,204,208,198 },
		{ 200,208,206,212,200,212,206,208,200 },
		{ 194,206,204,212,200,212,204,206,194 }
	},
	{//红马
		{ 90, 90, 90, 96, 90, 96, 90, 90, 90 },
		{ 90, 96,103, 97, 94, 97,103, 96, 90 },
		{ 92, 98, 99,103, 99,103, 99, 98, 92 },
		{ 93,108,100,107,100,107,100,108, 93 },
		{ 90,100, 99,103,104,103, 99,100, 90 },
		{ 90, 98,101,102,103,102,101, 98, 90 },
		{ 92, 94, 98, 95, 98, 95, 98, 94, 92 },
		{ 93, 92, 94, 95, 92, 95, 94, 92, 93 },
		{ 85, 90, 92, 93, 78, 93, 92, 90, 85 },
		{ 88, 85, 90, 88, 90, 88, 90, 85, 88 }
	},
	{//红相
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0, 20,  0,  0,  0, 20,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{18,  0,  0,  0, 23,  0,  0,  0, 18 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0, 20,  0,  0,  0, 20,  0,  0 }
	},
	{//红仕
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0, 20,  0, 20,  0,  0,  0 },
		{ 0,  0,  0,  0, 23,  0,  0,  0,  0 },
		{ 0,  0,  0, 20,  0, 20,  0,  0,  0 }
	},
	{//红帅
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  1,  1,  1,  0,  0,  0 },
		{ 0,  0,  0,  2,  2,  2,  0,  0,  0 },
		{ 0,  0,  0, 11, 15, 11,  0,  0,  0 },
	}
};


class pieceCharacters
{
public:
	pieceCharacters();
	void set_type(int);
	void set_cname();
	string get_cname();
	void set_ascii();
	int get_ascii();
	void piece_exist(bool);
	bool get_exist();
	void set_point(int,int);
	int return_x();
	int return_y();
	string return_location();
	wstring sTot();
	int return_type();
	friend ostream &operator<<(ostream &os, const pieceCharacters &pc);
	void set_control(int);
	int return_control();
	void add_point(int, int);
	bool can_touch(int*, int, int, int, int);
	void get_touch(int*);
	struct to_pos
	{
		int tx;
		int ty;
	};
	void move_num();//设定走法数
	int get_move();//返回走法数
	void mobility();
	int return_move();
	void show_vector();
	bool close(int,int);//判断与其中的目标点重合
	~pieceCharacters();
	int Type() const { return type; }
	int getChara_zuobiao() const { 
		return chara_zuobiao; }
	void Chara_zuobiao()
	{
		if (Y < 5)
			chara_zuobiao = 201 + Y * 10 + X;
		else
			chara_zuobiao = 101 + Y * 10 + X;
	}
private:
	int type;//棋子类型
	string cname;//棋子名称
	int ascname;//棋子的ascii代码
	bool exist = false;//棋子是否存在
	int X = -1, Y = -1;//棋子在局面棋盘中的坐标
	int chara_zuobiao;//棋子坐标的特征表示
	string location;//坐标字符串
	int control_value = 0;//棋子位置相关的价值
	int move;//走法数
	int mob_value = 0;//机动性评分
	vector<to_pos> target;
};

