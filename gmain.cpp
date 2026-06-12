#include"libOne.h"

void gmain()
{
	window(1920, 1080);
	
	repeat()
	{
		background(0, 0, 0);

		//info
		print((let)"w:" + width + " h:" + height);
		print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
		print((let)"delta:" + delta);
	}
}