#include"libOne.h"
#include"DRAW.h"

void D_title()
{
	//ロゴ描画
	fill(70, 255, 255);
	print("title");

	//info
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
}

void D_play()
{
	//ロゴ描画
	fill(255, 255, 70);
	print("play");

	//info
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
}

void D_over()
{
	//ロゴ描画
	fill(255, 70, 255);
	print("over");

	//info
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
}