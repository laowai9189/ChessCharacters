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
		return false;//Ŀ����Դ��ͬ
	from_id = *(p + 9 * from_y + from_x);
	to_id = *(p + 9 * to_y + to_x);
	if ((from_id > -1 && from_id<7) && (to_id>-1 && to_id < 7))
		return false;
	if ((from_id > 6 && from_id < 14) && (to_id>6 && to_id < 14))
		return false;
	switch (from_id)
	{
	case 4://�ڽ�
		if (to_id == 13)//�Ƿ�����Ͻ�����
		{
			if (from_x != to_x)
				return false;
			for (i = from_y + 1; i < to_y; i++)
				if (*(p + 9 * i + from_x) != -1)
					return false;
		}
		else {
			if (to_y > 2 || to_x > 5 || to_x < 3)
				return false;//Ŀ����ھŹ�֮��
			if (abs(from_y - to_y) + abs(to_x - from_x)>1)
				return false;
		}
		break;
	case 12://����
		if (to_y < 7 || to_x > 5 || to_x < 3)
			return false;//ʿ���Ź�
		if (abs(from_y - to_y) != 1 || abs(to_x - from_x) != 1)
			return false;//ʿ��б��
		break;
	case 3://��ʿ
		if (to_y > 2 || to_x > 5 || to_x < 3)
			return false;//ʿ���Ź�
		if (abs(from_y - to_y) != 1 || abs(to_x - from_x) != 1)
			return false;//ʿ��б��
		break;
	case 11://����
		if (to_y < 5)
			return false;//�಻�ܹ���
		if (abs(from_x - to_x) != 2 || abs(from_y - to_y) != 2)
			return false;//��������
		if (*(p + 9 * (from_y + to_y) / 2 + (from_x + to_x) / 2) != -1)
			return false;//���۱���ס��
		break;
	case 2://����
		if (to_y > 4)
			return false;//���ܹ���
		if (abs(from_x - to_x) != 2 || abs(from_y - to_y) != 2)
			return false;//��������
		if (*(p + 9 * (from_y + to_y) / 2 + (from_x + to_x) / 2) != -1)
			return false;//���۱���ס��
		break;
	case 6://����
		if (to_y < from_y)
			return false;//�䲻��ͷ
		if (from_y < 5 && from_y == to_y)
			return false;//�����ǰֻ��ֱ��
		if (to_y - from_y + abs(to_x - from_x)>1)
			return false;//��ֻ��һ��ֱ��
		break;
	case 7://���
		if (to_y > from_y)
			return false;//������ͷ
		if (from_y > 4 && from_y == to_y)
			return false;//������ǰֻ��ֱ��
		if (from_y - to_y + abs(to_x - from_x)>1)
			return false;//��ֻ��һ��ֱ��
		break;
	case 13://��˧
		if (to_id == 4)//�Ƿ�����Ͻ�����
		{
			if (from_x != to_x)
				return false;//��˧����ͬһ��
			for (i = from_y - 1; i > to_y; i--)
				if (*(p + 9 * i + from_x) != -1)
					return false;//�м��б����
		}
		else {
			if (to_y < 7 || to_x > 5 || to_x < 3)
				return false;//Ŀ����ھŹ�֮��
			if (abs(from_y - to_y) + abs(to_x - from_x)>1)
				return false;//��˧ֻ��һ��ֱ��
		}
		break;
	case 0://�ڳ�
	case 9://�쳵
		if (from_y != to_y&&from_x != to_x)
			return false;//����ֱ��
		if (from_y == to_y)
		{//����
			if (from_x < to_x)
			{//����
				for (i = from_x + 1; i < to_x; i++)
					if (*(p + 9 * from_y + i) != -1)
						return false;
			}
			else {//����
				for (i = to_x + 1; i < from_x; i++)
					if (*(p + 9 * from_y + i) != -1)
						return false;
			}
		}
		else {//����
			if (from_y < to_y)
			{//����
				for (j = from_y + 1; j < to_y; j++)
					if (*(p + 9 * j + from_x) != -1)
						return false;
			}
			else {//����
				for (j = to_y + 1; j < from_y; j++)
					if (*(p + 9 * j + from_x) != -1)
						return false;
			}
		}
		break;
	case 1://����
	case 10://����
		if (!((abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2) || (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1)))
			return false;//��������
		if (to_x - from_x == 2)
		{//��������
			i = from_x + 1;
			j = from_y;
		}
		else if (from_x - to_x == 2) {//��������
			i = from_x - 1;
			j = from_y;
		}
		else if (to_y - from_y == 2) {//������
			i = from_x;
			j = from_y + 1;
		}
		else if (from_y - to_y == 2) {//������
			i = from_x;
			j = from_y - 1;
		}
		if (*(p + 9 * j + i) != -1)
			return false;//������
		break;
	case 5://����
	case 8://����
		if (from_y != to_y&&from_x != to_x)
			return false;//����ֱ��
						 //�ڲ�����ʱ������·���в���������
		if (*(p + 9 * to_y+to_x) == -1)
		{//������ʱ
			if (from_y == to_y)
			{//����
				if (from_x < to_x)
				{//����
					for (i = from_x + 1; i < to_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							return false;
				}
				else {//����
					for (i = to_x + 1; i < from_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							return false;
				}
			}
			else {//����
				if (from_y < to_y)
				{//����
					for (j = from_y + 1; j < to_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							return false;
				}
				else {//����
					for (j = to_y + 1; j < from_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							return false;
				}
			}
		}
		//����ʱ
		else {
			int count = 0;
			if (from_y == to_y)
			{//����
				if (from_x < to_x)
				{//����
					for (i = from_x + 1; i < to_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							count++;//�������������
					if (count != 1)
						return false;//���Ǹ�һ���ӣ����ܳ�
				}
				else {//����
					for (i = to_x + 1; i < from_x; i++)
						if (*(p + 9 * from_y + i) != -1)
							count++;//�����������
					if (count != 1)
						return false;//���Ǹ�һ���ӣ����ܳ�
				}
			}
			else {//����
				if (from_y < to_y)
				{//����
					for (j = from_y + 1; j < to_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							count++;//�����������
					if (count != 1)
						return false;//���Ǹ�һ���ӣ����ܳ�
				}
				else {//����
					for (j = to_y + 1; j < from_y; j++)
						if (*(p + 9 * j + from_x) != -1)
							count++;//�����������
					if (count != 1)
						return false;//���Ǹ�һ���ӣ����ܳ�
				}
			}
		}
		break;
	default:
		return false;
	}
	return true;//�������㣬����TRUE
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
	case 13://��˧
	case 4://�ڽ�
		   //ѭ�����Ź�֮����Щδ֪���Ե���
		   //ɨ�����߾Ź���������������
		for (y = 0; y < 3; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))//�ܷ��ߵ�
					add_point(x, y);//�ɴﵽ��λ�ü�������
		//��ü��Ź�֮������Щδ֪�ɵ���
		//ɨ�����߾Ź���������������
		for (y = 7; y < 10; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))//�ܷ��ߵ�
					add_point(x, y);//�ɵ����λ�ü�������
		break;
	case 12://����
		//ѭ�����Ź�֮����Щλ�ÿɵ���
		for (y = 7; y < 10; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//�ɵ����λ�ü�������
		break;
	case 3://��ʿ
		//ѭ�����Ź�֮����Щλ�ÿɵ���
		for (y = 0; y < 3; y++)
			for (x = 3; x < 6; x++)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//�ɵ����λ�ü�������
		break;
	case 11://����
	case 2://����
		//����
		x = X + 2;
		y = Y + 2;
		if (x < 9 && y < 10 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//����
		x = X + 2;
		y = Y - 2;
		if (x < 9 && y >= 0 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//����
		x = X - 2;
		y = Y + 2;
		if (x >= 0 && y < 10 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//����
		x = X - 2;
		y = Y - 2;
		if (x >= 0 && y >= 0 && can_touch(p, X, Y, x, y))
			add_point(x, y);
		break;
	case 10://����
	case 1://����
		//������·��Ƿ�����
		x = X + 2;
		y = Y + 1;
		if ((x < 9 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������Ϸ��ܷ���
		x = X + 2;
		y = Y - 1;
		if ((x < 9 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������·��ܷ���
		x = X - 2;
		y = Y + 1;
		if ((x >= 0 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������Ϸ��ܷ���
		x = X - 2;
		y = Y - 1;
		if ((x >= 0 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������·��Ƿ�����
		x = X + 1;
		y = Y + 2;
		if ((x < 9 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������·��Ƿ�����
		x = X - 1;
		y = Y + 2;
		if ((x >= 0 && y < 10) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������Ϸ��Ƿ�����
		x = X + 1;
		y = Y - 2;
		if ((x < 9 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		//������Ϸ��Ƿ�����
		x = X - 1;
		y = Y - 2;
		if ((x >= 0 && y >= 0) && can_touch(p, X, Y, x, y))
			add_point(x, y);
		break;
	case 9://�쳵
	case 0://�ڳ�
		//������ҵ�λ���Ƿ�����
		x = X + 1;
		y = Y;
		while (x < 9)
		{
			if (*(p + 9 * y + x) == -1)//�հ�
				add_point(x, y);
			else {//������һ������
				if(can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//�����λ�ò�������
			}
			x++;
		}
		//��������λ���Ƿ�����
		x = X - 1;
		y = Y;
		while (x >= 0)
		{
			if (*(p + 9 * y + x) == -1)//�հ�
				add_point(x, y);
			else {//������һ������
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//�����λ�ò�������
			}
			x--;
		}
		//������µ�λ���Ƿ�����
		x = X;
		y = Y + 1;
		while (y < 10)
		{
			if (*(p + 9 * y + x) == -1)//�հ�
				add_point(x, y);
			else {//������һ������
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//�����λ�ò�������
			}
			y++;
		}
		//������ϵ�λ���Ƿ�����
		x = X;
		y = Y - 1;
		while (y >= 0)
		{
			if (*(p + 9 * y + x) == -1)//�հ�
				add_point(x, y);
			else {//������һ������
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);
				break;//�����λ�ò�������
			}
			y--;
		}
		break;
	case 7://���
		//�鿴��ǰ�Ƿ񵽵�
		y = Y - 1;
		x = X;
		if (y >= 0)
			if (can_touch(p, X, Y, x, y))
				add_point(x, y);//û���ף�����
		if (Y < 5)
		{//���ѹ���
			y = Y;
			x = X + 1;//����
			if (x < 9)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//δ���ұߣ�����
			x = X - 1;//����
			if (x >= 0)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//δ����ߣ�����
		}
		break;
	case 6://����
		//�鿴��ǰ�Ƿ񵽵�
		y = Y + 1;
		x = X;
		if (y < 10)//�Ƿ��ѳ���
			if (can_touch(p, X, Y, x, y))
				add_point(x, y);//û����
		if (Y > 4)
		{//���ѹ���
			y = Y;
			x = X + 1;//����
			if (x < 9)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//δ���ұߣ�����
			x = X - 1;//����
			if (x >= 0)
				if (can_touch(p, X, Y, x, y))
					add_point(x, y);//δ����ߣ�����
		}
		break;
	case 5://����
	case 8://����
		//�鿴���ҷ���Ŀ���λ��
		x = X + 1;
		y = Y;
		flag = false;
		while (x < 9)
		{
			if (*(p + 9 * y + x)==-1)
			{//�հ�λ��
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//������
				if (!flag)
					flag = true;//�ǵ�һ������
				else {//�ǵڶ�������
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
						break;
				}
			}
			x++;//��������
		}
		//�鿴������Ŀ��ߵ�λ��
		x = X - 1;
		flag = false;
		while (x >= 0)
		{
			if (*(p + 9 * y + x) == -1)
			{//�հ�λ��
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//������
				if (!flag)
					flag = true;//�ǵ�һ������
				else {//�ǵڶ�������
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			x--;//��������
		}
		//�鿴���·���Ŀ��ߵ�λ��
		x = X;
		y = Y + 1;
		flag = false;
		while (y < 10)
		{
			if (*(p + 9 * y + x) == -1)
			{//�հ�λ��
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//������
				if (!flag)
					flag = true;//�ǵ�һ������
				else {//�ǵڶ�������
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			y++;//��������
		}
		//�鿴���Ϸ���Ŀ��ߵ�λ��
		y = Y - 1;
		flag = false;
		while (y >= 0)
		{
			if (*(p + 9 * y + x) == -1)
			{//�հ�λ��
				if (!flag)
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
			}
			else {//������
				if (!flag)
					flag = true;//�ǵ�һ������
				else {//�ǵڶ�������
					if (can_touch(p, X, Y, x, y))
						add_point(x, y);
					break;
				}
			}
			y--;//��������
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