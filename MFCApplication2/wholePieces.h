#pragma once
#include <iostream>
#include <vector>
#include "pieceCharacters.h"
#include "chessCharacters.h"

class wholePieces
{
public:
	wholePieces(int*);
	void set_value(int*);//���ø�������ֵ
	void set_move_value(int*);//�趨�߷����ͻ���������
	void make_step(int*);//�������ӽ����߷�����
	void threat(pieceCharacters, pieceCharacters);
	void attack(pieceCharacters, pieceCharacters);
	pieceCharacters track(int, int);//������������λ���ӣ�������������ĸ����ת��
	pieceCharacters* track_point(int, int);
	void threat_b(pieceCharacters);
	void threat_b(int, int);//���Ժڷ�����в
	void threat_r(pieceCharacters);
	void threat_r(int, int);//���Ժ췽����в
	void attack_b(int, int);
	void attack_r(int, int);
	double map_threat(int, int);
	wstring map_threat(pieceCharacters);
	wstring map_protect(chessCharacters, int, int);
	int map_allpro(chessCharacters, int, int);
	double map_attack(int, int);
	int th_bx();//���������в���ӵ�����
	int th_by();
	int th_rx();
	int th_ry();
	~wholePieces();
private:
	pieceCharacters k[1], r[2], n[2], c[2], b[2], a[2], p[6], K[1], R[2], N[2], C[2], B[2], A[2], P[6];
	pieceCharacters *d = r, *e = n, *f = b, *g = a, *h = k, *l = c, *m = p, *M = P, *L = C, *D = R, *E = N, *F = B, *G = A, *H = K;
	vector<pieceCharacters> th_b;//�ڷ���в��������
	vector<pieceCharacters> th_r;//�췽��в��������
	vector<pieceCharacters> att_b;//���ڣ��ڷ�������������
	vector<pieceCharacters> att_r;//�ڴ�죬�췽������������
};

