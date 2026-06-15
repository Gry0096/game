#pragma once

struct CIRCLE_A
{
	float px, py, vx, vy, radius, enl;
};

void A_init(struct CIRCLE_A* a);
void A_play(struct CIRCLE_A* a);
void A_over(struct CIRCLE_A* a);
void A_draw(struct CIRCLE_A* a);
