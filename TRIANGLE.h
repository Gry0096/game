#pragma once

struct TRIANGLE
{
	float adj;//底辺
	float opp;//高さ
	float hyp_sqrd;//斜辺_二乗
	float dis_sqrd;
};

void T_init(struct TRIANGLE* t);
void T_play(struct TRIANGLE* t, struct CIRCLE_A* a, struct CIRCLE_B* b);