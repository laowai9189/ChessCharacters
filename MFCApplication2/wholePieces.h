#pragma once
#include <iostream>
#include <vector>
#include "pieceCharacters.h"
#include "chessCharacters.h"

class wholePieces
{
public:
	wholePieces(int*);
	void set_value(int*);//设置各种属性值
	void set_move_value(int*);//设定走法数和机动性评分
	void make_step(int*);//所有棋子进行走法演绎
	void threat(pieceCharacters, pieceCharacters);
	void attack(pieceCharacters, pieceCharacters);
	pieceCharacters track(int, int);//根据两个数定位棋子，棋子数字与字母数组转化
	pieceCharacters* track_point(int, int);
	void threat_b(pieceCharacters);
	void threat_b(int, int);//来自黑方的威胁
	void threat_r(pieceCharacters);
	void threat_r(int, int);//来自红方的威胁
	void attack_b(int, int);
	void attack_r(int, int);
	double map_threat(int, int);
	wstring map_threat(pieceCharacters);
	wstring map_protect(chessCharacters, int, int);
	int map_allpro(chessCharacters, int, int);
	double map_attack(int, int);
	int th_bx();//返回造成威胁棋子的坐标
	int th_by();
	int th_rx();
	int th_ry();
	~wholePieces();
private:
	pieceCharacters k[1], r[2], n[2], c[2], b[2], a[2], p[6], K[1], R[2], N[2], C[2], B[2], A[2], P[6];
	pieceCharacters *d = r, *e = n, *f = b, *g = a, *h = k, *l = c, *m = p, *M = P, *L = C, *D = R, *E = N, *F = B, *G = A, *H = K;
	vector<pieceCharacters> th_b;//黑方威胁棋子向量
	vector<pieceCharacters> th_r;//红方威胁棋子向量
	vector<pieceCharacters> att_b;//红打黑，黑方被攻击的棋子
	vector<pieceCharacters> att_r;//黑打红，红方被攻击的棋子
};

