#include"libOne.h"

void gmain()
{
	window(1920, 1080, full);

	repeat()
	{
		background(250,200,250);

		//debug info
		fill(255,255,255);
		print((let)width + " " + height);
		print((let)mouseX + " " + mouseY);
		print(delta);
	}
}