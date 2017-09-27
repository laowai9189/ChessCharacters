#include "stdafx.h"
#include "chessCharacters.h"
#include "pieceCharacters.h"
#include <iostream>


pieceCharacters::pieceCharacters()
{
}


pieceCharacters::~pieceCharacters()
{
}

void pieceCharacters::set_type(int t)
{
	type = t;
}

void pieceCharacters::set_cname()
{
	switch (type)
	{
	case 0:
		cname = "r";
		break;
	case 1:
		cname = "n";
		break;
	case 2:
		cname = "b";
		break;
	case 3:
		cname = "a";
		break;
	case 4:
		cname = "k";
		break;
	case 5:
		cname = "c";
		break;
	case 6:
		cname = "p";
		break;
	case 7:
		cname = "P";
		break;
	case 8:
		cname = "C";
		break;
	case 9:
		cname = "R";
		break;
	case 10:
		cname = "N";
		break;
	case 11:
		cname = "B";
		break;
	case 12:
		cname = "A";
		break;
	case 13:
		cname = "K";
		break;
	default:
		break;
	}
}

string pieceCharacters::get_cname()
{
	set_cname();
	return cname;
}

void pieceCharacters::set_ascii()
{
	switch (type)
	{
	case 0:
		ascname = 114;
		break;
	case 1:
		ascname = 110;
		break;
	case 2:
		ascname = 98;
		break;
	case 3:
		ascname = 97;
		break;
	case 4:
		ascname = 107;
		break;
	case 5:
		ascname = 99;
		break;
	case 6:
		ascname = 112;
		break;
	case 7:
		ascname = 80;
		break;
	case 8:
		ascname = 67;
		break;
	case 9:
		ascname = 82;
		break;
	case 10:
		ascname = 78;
		break;
	case 11:
		ascname = 66;
		break;
	case 12:
		ascname = 65;
		break;
	case 13:
		ascname = 75;
		break;
	default:
		break;
	}
}

int pieceCharacters::get_ascii()
{
	set_ascii();
	return ascname;
}

void pieceCharacters::piece_exist(bool e)
{
	exist = e;
}

bool pieceCharacters::get_exist()
{
	return exist;
}

void pieceCharacters::set_point(int x, int y)
{
	X = x; Y = y;
}

int pieceCharacters::return_x()
{
	return X;
}

int pieceCharacters::return_y()
{
	return Y;
}

string pieceCharacters::return_location()
{
	string a = "(";
	string b = ",";
	string c = ")";
	char XX = X + 48;
	char YY = Y + 48;
	location = a + XX + b + YY + c;
	return location;
}

wstring pieceCharacters::sTot()
{
	string str = return_location();
	wstring ws(str.length(), L' ');
	copy(str.begin(), str.end(), ws.begin());
	return ws;
}

int pieceCharacters::return_type()
{
	return type;
}

ostream &operator<<(ostream &os, const pieceCharacters &pc)
{
	//os << pc.exist;
	os << "(" << pc.X << "," << pc.Y << ")";
	//os << pc.control_value;
	return os;
}

void pieceCharacters::set_control(int c)
{
	control_value = c;
}

int pieceCharacters::return_control()
{
	return control_value;
}

void pieceCharacters::add_point(int x, int y)
{
	to_pos tp;
	tp.tx = x;
	tp.ty = y;
	target.push_back(tp);
}

bool pieceCharacters::can_touch(int* p, int from_x, int from_y, int to_x, int to_y)
{
	int i, j;
	int from_id, to_id;
	if (from_y == to_y&&from_x == to_x)
		return false;//目的与源相同
	from_id = *(p + 9 * from_y + from_x);
	to_id = *(p + 9 * to_y + to_x);
	if ((from_id > -1 && from_id<7) && (to_id>-1 && to_id < 7))
		return false;
	if ((from_id > 6 && from_id < 14) && (to_id>6 && to_id < 14))
		return false;
	switch (from_id)
	{
	case 4://黑将
		if (to_id == 13)//是否出现老将见面
		{
			if (from_x != to_x)
				return false;
			for (i = from_y + 1; i < to_y; i++)
				if (*(p + 9 * i + from_x) != -1)
					return false;
		}
		else {
			if (to_y > 2 || to_x > 5 || to_x < 3)
				return false;//目标点在九宫之外
			if (abs(from_y - to_y) + abs(to_x - from_x)>1)
				return false;
		}
		break;
	case 12://红仕
		if (to_y < 7 || to_x > 5 || to_x < 3)
			return false;//士出九宫
		if (abs(from_y - to_y) != 1 || abs(to_x - from_x) != 1)
			return false;//士走斜线
		break;
	case 3://黑士
		if (to_y > 2 || to_x > 5 || to_x < 3)
			return false;//士出九宫
		if (abs(from_y - to_y) != 1 || abs(to_x - from_x) != 1)
			return false;//士走斜线
		break;
	case 11://红相
		if (to_y < 5)
			return false;//相不能过河
		if (abs(from_x - to_x) != 2 || abs(from_y - to_y) != 2)
			return false;//相走田字
		if (*(p + 9 * (from_y + to_y) / 2 + (from_x + to_x) / 2) != -1)
			return false;//相眼被塞住了
		break;
	case 2://黑象
		if (to_y > 4)
			return false;//象不能过河
		if (abs(from_x - to_x) != 2 || abs(from_y - to_y) != 2)
			return false;//象走田字
		if (*(p + 9 * (from_y + to_y) / 2 + (from_x + to_x) / 2) != -1)
			return false;//象眼被塞住了
		break;
	case 6://黑卒
		if (to_y < from_y)
			return false;//卒不回头
		if (from_y < 5 && from_y == to_y)
			return false;//卒过河前只能直走
		if (to_y - from_y + abs(to_x - from_x)>1)
			return false;//卒只走一步直线
		break;
	case 7://红兵
		if (to_y > from_y)
			return false;//兵不回头
		if (from_y > 4 && from_y == to_y)
			return false;//兵过河前只能直走
		if (from_y - to_y + abs(to_x - from_x)>1)
			return false;//兵只走一步直线
		break;
	case 13://红帅
		if (to_id == 4)//是否出现老将见面
		{
			if (from_x != to_x)
				return false;//将帅不在同一列
			for (i = from_y - 1; i > to_y; i--)
				if (*(p + 9 * i + from_x) != -1)
					return false;//中间有别的子
		}
		else {
			if (to_y < 7 || to_x > 5 || to_x < 3)
				return false;//目标点在九宫之外
			if (abs(from_y - to_y) + abs(to_x - from_x)>1)
				return false;//将帅只走一步直线
		}
		break;
	case 0://黑车
	case 9://红车
		if (from_y != to_y&&from_x != to_x)
			return false;//车走直线
		if (from_y == to_y)
		{//横向
			if (from_x < to_x)
			{//向右
				for (i = from_x + 1; i < to_x; i++)
					if (*(p + 9 * from_y + i) != -1)
						return false;
			}
			else {//向左
				for (i = to_x + 1; i < from_x; i++)
					if (*(p + 9 * from_y + i) != -1)
						return false;
			}
		}
		else {//纵向
			if (from_y < to_y)
			{//向下
				for (j = from_y + 1; j < to_y; j++)
					if (*(p + 9 * j + from_x) != -1)
						return false;
			}
			else {//向上
				for (j = to_y + 1; j < from_y; j++)
					if (*(p + 9 * j + from_x) != -1)
						return false;
			}
		}
		break;
	case 1://黑马
	case 10://红马
		if (!((abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2) || (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1)))
			return false;//马走日字
		if (to_x - from_x == 2)
		{//横向右走
			i = from_x + 1;
			j = from_y;
		}
		else if (from_x - to_x == 2) {//横向左走
			i = from_x - 1;
			j = from_y;
		}
		else if (to_y - from_y == 2) {//纵向下
			i = from_x;
			j = from_y + 1;
		}
		else if (from_y - to_y == 2) {//纵向上
			i = from_x;
			j = from_y - 1;
		}
		if (*(p + 9 * j + i) != -1)
			return false;//绊马腿
		break;
	case 5://黑炮
	case 8://红炮
		if (from_y != to_y&&from_x != to_x)
			return false;//炮走直线
						 //炮不吃子时经过的路线中不能有棋子
		if (*(p + 9 * to_y+to_x) == -1)
		{//不吃子时
			if (from_y == to_y)
			{//横向
				if (from_x < to_x)
				{//向右
					for (i = from_x + 1; i < to_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							return false;
				}
				else {//向左
					for (i = to_x + 1; i < from_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							return false;
				}
			}
			else {//纵向
				if (from_y < to_y)
				{//向下
					for (j = from_y + 1; j < to_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							return false;
				}
				else {//向上
					for (j = to_y + 1; j < from_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							return false;
				}
			}
		}
		//吃子时
		else {
			int count = 0;
			if (from_y == to_y)
			{//横向
				if (from_x < to_x)
				{//向右
					for (i = from_x + 1; i < to_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							count++;//计算隔几个棋子
					if (count != 1)
						return false;//不是隔一个子，不能吃
				}
				else {//向左
					for (i = to_x + 1; i < from_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							count++;//计算隔几个子
					if (count != 1)
						return false;//不是隔一个子，不能吃
				}
			}
			else {//纵向
				if (from_y < to_y)
				{//向下
					for (j = from_y + 1; j < to_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							count++;//计算隔几个子
					if (count != 1)
						return false;//不是隔一个子，不能吃
				}
				else {//向上
					for (j = to_y + 1; j < from_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							count++;//计算隔几个子
					if (count != 1)
						return false;//不是隔一个子，不能吃
				}
			}
		}
		break;
	default:
		return false;
	}
	return true;//条件满足，返回TRUE
}

void pieceCharacters::get_touch(int* p)
{
	int pos_count = 0;
	int chess_id;
	bool flag;
	int x, y;
	chess_id = *(p + 9 * Y + X);
	switch (chess_id)
	{
	case 13://红帅
	case 4://黑将
		   //循环检查九宫之内那些未知可以到达
		   //扫面两边九宫包含了照像的情况
		for (y = 0; y < 3; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))//能否走到
					add_point(x, y);//可达到的位置加入数组
		//虚幻检查九宫之内有哪些未知可到达
		//扫面两边九宫包含了照像的情况
		for (y = 7; y < 10; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))//能否走到
					add_point(x, y);//可到达的位置加入数组
		break;
	case 12://红仕
		//循环检查九宫之内那些位置可到达
		for (y = 7; y < 10; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//可到达的位置加入数组
		break;
	case 3://黑士
		//循环检查九宫之内那些位置可到达
		for (y = 0; y < 3; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//可到达的位置加入数组
		break;
	case 11://红相
	case 2://黑象
		//右下
		x = X + 2;
		y = Y + 2;
		if (x < 9 && y < 10 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//右上
		x = X + 2;
		y = Y - 2;
		if (x < 9 && y >= 0 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//左下
		x = X - 2;
		y = Y + 2;
		if (x >= 0 && y < 10 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//左上
		x = X - 2;
		y = Y - 2;
		if (x >= 0 && y >= 0 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		break;
	case 10://红马
	case 1://黑马
		//检查右下方是否能走
		x = X + 2;
		y = Y + 1;
		if ((x < 9 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查右上方能否走
		x = X + 2;
		y = Y - 1;
		if ((x < 9 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查左下方能否走
		x = X - 2;
		y = Y + 1;
		if ((x >= 0 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查左上方能否走
		x = X - 2;
		y = Y - 1;
		if ((x >= 0 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查右下方是否能走
		x = X + 1;
		y = Y + 2;
		if ((x < 9 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查左下方是否能走
		x = X - 1;
		y = Y + 2;
		if ((x >= 0 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查右上方是否能走
		x = X + 1;
		y = Y - 2;
		if ((x < 9 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//检查走上方是否能走
		x = X - 1;
		y = Y - 2;
		if ((x >= 0 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		break;
	case 9://红车
	case 0://黑车
		//检查向右的位置是否能走
		x = X + 1;
		y = Y;
		while (x < 9)
		{
			if (*(p + 9 * y + x) == -1)//空白
				add_point(x, y);
			else {//碰到第一个棋子
				if(can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//后面的位置不能走了
			}
			x++;
		}
		//检查向左的位置是否能走
		x = X - 1;
		y = Y;
		while (x >= 0)
		{
			if (*(p + 9 * y + x) == -1)//空白
				add_point(x, y);
			else {//碰到第一个棋子
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//后面的位置不能走了
			}
			x--;
		}
		//检查向下的位置是否能走
		x = X;
		y = Y + 1;
		while (y < 10)
		{
			if (*(p + 9 * y + x) == -1)//空白
				add_point(x, y);
			else {//碰到第一个棋子
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//后面的位置不能走了
			}
			y++;
		}
		//检查向上的位置是否能走
		x = X;
		y = Y - 1;
		while (y >= 0)
		{
			if (*(p + 9 * y + x) == -1)//空白
				add_point(x, y);
			else {//碰到第一个棋子
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//后面的位置不能走了
			}
			y--;
		}
		break;
	case 7://红兵
		//查看向前是否到底
		y = Y - 1;
		x = X;
		if (y >= 0)
			if (can_touch(p, X, Y, x, y))
				add_point(x, y);//没到底，可走
		if (Y < 5)
		{//如已过河
			y = Y;
			x = X + 1;//向右
			if (x < 9)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//未到右边，可走
			x = X - 1;//向左
			if (x >= 0)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//未到左边，可走
		}
		break;
	case 6://黑卒
		//查看向前是否到底
		y = Y + 1;
		x = X;
		if (y < 10)//是否已沉底
			if (can_touch(p, X, Y, x, y))
				add_point(x, y);//没到底
		if (Y > 4)
		{//如已过河
			y = Y;
			x = X + 1;//向右
			if (x < 9)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//未到右边，可走
			x = X - 1;//向左
			if (x >= 0)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//未到左边，可走
		}
		break;
	case 5://黑炮
	case 8://红炮
		//查看向右方向的可走位置
		x = X + 1;
		y = Y;
		flag = false;
		while (x < 9)
		{
			if (*(p + 9 * y + x)==-1)
			{//空白位置
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//有棋子
				if (!flag)
					flag = true;//是第一个棋子
				else {//是第二个棋子
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
						break;
				}
			}
			x++;//继续向右
		}
		//查看向左方向的可走的位置
		x = X - 1;
		flag = false;
		while (x >= 0)
		{
			if (*(p + 9 * y + x) == -1)
			{//空白位置
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//有棋子
				if (!flag)
					flag = true;//是第一个棋子
				else {//是第二个棋子
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			x--;//继续向左
		}
		//查看向下方向的可走的位置
		x = X;
		y = Y + 1;
		flag = false;
		while (y < 10)
		{
			if (*(p + 9 * y + x) == -1)
			{//空白位置
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//有棋子
				if (!flag)
					flag = true;//是第一个棋子
				else {//是第二个棋子
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			y++;//继续向下
		}
		//查看向上方向的可走的位置
		y = Y - 1;
		flag = false;
		while (y >= 0)
		{
			if (*(p + 9 * y + x) == -1)
			{//空白位置
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//有棋子
				if (!flag)
					flag = true;//是第一个棋子
				else {//是第二个棋子
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			y--;//继续向上
		}
		break;
	default:
		break;
	}
}

void pieceCharacters::move_num()
{
	move = target.size();
}

int pieceCharacters::get_move()
{
	return move;
}

void pieceCharacters::mobility()
{
	int value;
	switch (type)
	{
	case 6:
	case 7:
		value = 15;
		break;
	case 3:
	case 12:
		value = 1;
		break;
	case 2:
	case 11:
		value = 1;
		break;
	case 0:
	case 9:
		value = 6;
		break;
	case 1:
	case 10:
		value = 12;
		break;
	case 5:
	case 8:
		value = 6;
		break;
	case 4:
	case 13:
		value = 0;
		break;
	default:
		break;
	}
	mob_value = value*get_move();
}

int pieceCharacters::return_move()
{
	return mob_value;
}

void pieceCharacters::show_vector()
{
	vector<to_pos>::const_iterator i;
	for (i = target.begin(); i != target.end(); ++i)
	{
		cout << (*i).tx << "," << (*i).ty << endl;
	}
}

bool pieceCharacters::close(int x, int y)
{
	vector<to_pos>::const_iterator i;
	for (i = target.begin(); i != target.end(); ++i)
	{
		if ((*i).tx == x && (*i).ty == y)
			return true;
	}
}