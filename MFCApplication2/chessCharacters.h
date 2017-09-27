#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class chessCharacters
{
private:
	int locationarray[10][9] = {
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 }
	};
	string fen;
public:
	chessCharacters();
	int charToint(char);
	string set_fen(string);
	void set_array();
	void change_array(int, int, int, int);
	int* get_point();
	void change_one(int, int, int);
	~chessCharacters();
};



