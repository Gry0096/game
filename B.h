#pragma once

struct CIRCLE_B
{
	float px, py, vx, vy, radius;
};

void B_init(struct CIRCLE_B* b);
void B_play(struct CIRCLE_B* b);
void B_over(struct CIRCLE_B* b);
void B_draw(struct CIRCLE_B* b);
