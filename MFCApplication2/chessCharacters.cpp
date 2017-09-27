#include "stdafx.h"
#include "chessCharacters.h"


chessCharacters::chessCharacters()
{
}


chessCharacters::~chessCharacters()
{
}

int chessCharacters::charToint(char c)
{
	int i = -1;
	switch (c)
	{
	case 'r': i = 0; break;
	case 'n': i = 1; break;
	case 'b': i = 2; break;
	case 'a': i = 3; break;
	case 'k': i = 4; break;
	case 'c': i = 5; break;
	case 'p': i = 6; break;
	case 'P': i = 7; break;
	case 'C': i = 8; break;
	case 'R': i = 9; break;
	case 'N': i = 10; break;
	case 'B': i = 11; break;
	case 'A': i = 12; break;
	case 'K': i = 13;
	}
	return i;
}

string chessCharacters::set_fen(string s)
{
	fen = s;
	return fen;
}

void chessCharacters::set_array()
{
	int col = 0, row = 0;

	for (auto c : fen)
	{
		if (c == ' ')
		{
			break;
		}
		if (c >= '1'&&c <= '9')
		{
			row += c - '0';
		}
		else if (c == '/')
		{
			col++;
			row = 0;
		}
		else {
			locationarray[col][row] = charToint(c);
			row++;
		}
	}
}

void chessCharacters::change_array(int from_x, int from_y, int to_x, int to_y)
{
	if (!(from_x == 0 && from_y == 0 && to_x == 0 && to_y == 0))
	{
		locationarray[to_y][to_x] = locationarray[from_y][from_x];
		locationarray[from_y][from_x] = -1;
	}
}

int* chessCharacters::get_point()
{
	int* p = &locationarray[0][0];
	return p;
}

void chessCharacters::change_one(int x, int y, int a)
{
	locationarray[y][x] = a;
}
