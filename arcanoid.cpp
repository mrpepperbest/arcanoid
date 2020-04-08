#include <SFML/Graphics.hpp>
#include <iostream>
#include "level.h"
using namespace std; //standart namespace
using namespace sf; //SFML namespace
int C1 = amount1; //first block type counter
int C2 = amount2; //second block type counter
/*ball class*/
class ball {
public:
	float x , y, d, dx, dy; //coords, acceleration
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	/*constructor*/
	ball(String F, float X, float Y, float D) {
		dx = -0.1; dy = -0.1;
		File = F;
		x = X;
		y = Y;
		d = D; 
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, d, d));
	}
	/**/
	/*ball actions*/
	void update(float time)  //all ball changes per time tick
	{
		x += dx * time; // x cord. change
		y += dy * time; //y cord. change
		sprite.setPosition(x, y); //map position of a ball
		interactionWithMap();     //checking the collisions
	}
	void interactionWithMap() { //map interactions
		for (int i = y / 32; i < (y + d) / 32; i++) {//checking coincidences with of ball real position with block position in the table
			for (int j = x / 32; j < (x + d) / 32; j++) {
				if (BlockLVL[i][j] == '1') { //collision with first type of block
					BlockLVL[i][j] = '0'; C1--; //block destruction
					if ((x >= j * 32) && (y >= i * 32)) {
									if (dy >= 0)
									{
										dy = dy;
									}
									if (dy <= 0)
									{
										y = i * 32 + 32;
										dy = -dy;
									}
									if (dx > 0)
									{
										dx = dx;
									}
									if (dx < 0)
									{
										x = j * 32 + 32;
										dx = -dx;
									}
								}
					if ((x <= j * 32) && (y >= i * 32)) {
						if (dy >= 0)
						{
							dy = dy;
						}
						if (dy < 0)
						{
							y = i * 32 + 32;
							dy = -dy;
						}
						if (dx >= 0)
						{
							x = j * 32 - d;
							dx = -dx;
						}
						if (dx < 0)
						{
							dx = dx;
						}
					}
					else
						if ((x >= j * 32) && (y <= i * 32)) {
							if (dy >= 0)
							{
								y = i * 32 - d;
								dy = -dy;
							}
							if (dy < 0)
							{
								dy = dy;
							}
							if (dx >= 0)
							{
								dx = dx;
							}
							if (dx < 0)
							{
								x = j * 32 + 32;
								dx = -dx;
							}
						}
						else
							if ((x <= j * 32) && (y <= i * 32)) {
								if (dy >= 0)
								{
									y = i * 32 - d;
									dy = -dy;
								}
								if (dy < 0)
								{
									dy = dy;
								}
								if (dx >= 0)
								{
									x = j * 32 - d;
									dx = -dx;
								}
								if (dx < 0)
								{
									dx = dx;
								}
							}
				}
				if (BlockLVL[i][j] == '2') { //collision with second type block
						BlockLVL[i][j] = '1'; C2--; C1++; //changing second type to a first one
						if ((x >= j * 32) && (y >= i * 32)) {
							if (dy >= 0)
								{
									dy = dy;
								}
							if (dy <= 0)
								{
									y = i * 32 + 32;
									dy = -dy;
								}
							if (dx > 0)
								{
									dx = dx;
								}
							if (dx < 0)
								{
									x = j * 32 + 32;
									dx = -dx;
								}
						}
						if ((x <= j * 32) && (y >= i * 32)) {
							if (dy >= 0)
							{
								dy = dy;
							}
							if (dy < 0)
							{
								y = i * 32 + 32;
								dy = -dy;
							}
							if (dx >= 0)
							{
								x = j * 32 - d;
								dx = -dx;
							}
							if (dx < 0)
							{
								dx = dx;
							}
						}
								else
									if ((x >= j * 32) && (y <= i * 32)) {
										if (dy >= 0)
										{
											y = i * 32 - d;
											dy = -dy;
										}
										if (dy < 0)
										{
											dy = dy;
										}
										if (dx >= 0)
										{
											dx = dx;
										}
										if (dx < 0)
										{
											x = j * 32 + 32;
											dx = -dx;
										}
									}
									else
										if ((x <= j * 32) && (y <= i * 32)) {
											if (dy >= 0)
											{
												y = i * 32 - d;
												dy = -dy;
											}
											if (dy < 0)
											{
												dy = dy;
											}
											if (dx >= 0)
											{
												x = j * 32 - d;
												dx = -dx;
											}
											if (dx < 0)
											{
												dx = dx;
											}
										}
				}
			}
		}
	}
	/**/
};
/**/
/*board class*/
class board {
public:
	float x=320, y=610, w, h, dx, speed; //coords, movespeed,acceleration
	int dir,points=0; //positive or negative moving direction
	String File; 
	Image image;
	Texture texture;
	Sprite sprite;
	/*constructor*/
	board (String F, float W, float H) { 
		dx = 0; speed = 0; dir = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	/**/
	/*board actions*/
	void update(float time) 
	{//board changes per tick
		switch (dir) //checking board direction
		{
		case 0: dx = speed; break;
		case 1: dx = -speed; break;
		}
		x += dx * time; //board cord change
		speed = 0;
		sprite.setPosition(x, y); //drawing board
		InteractionWithBorders(); //checking collisions
	}
	/*collisions with borders check*/
	void InteractionWithBorders() {
		if ((x >= 0) && (x < 30)) {
			x+=1; //left border collision
		}
		if ((x >= 704-w-30) && (x <= 704-w)) {
			x-= 1; //right border collision
		}
	}
	/**/
};
/**/
/*block class*/
/*class block {
public:
	float x, y, w = 32, h = 32, hp;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	block (String F, float X, float Y, float HP) {
		File = F;
		x = X; y = Y;
		hp = HP;
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void update() {
		sprite.setPosition(x, y);
	}
	void destruction() {}
	
};
*/
/*main*/
int main()
{
	
	float endtimer = 0; //creating timer for final
	randomLvlGenerate(); //generating block table

	/*basic map settings*/
	Image block_image; 
	Texture block;
	block_image.loadFromFile("images/blocks.png");
	block.loadFromImage(block_image);
	Sprite s_block;
	s_block.setTexture(block);
	/**/
	RenderWindow window(VideoMode(704, 704), "Canceroid"); //creating a window

	/*basic endtext settings*/
	Font font;
	font.loadFromFile("arial.ttf");
	Text text("", font, 120);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	/**/
	/*creating a board and a ball*/
	board a("board_image0.png", 48, 10);
	ball b("ball0.png", 335, 630, 14);
	/**/
	Clock clock; //creating a timer
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds()dd;
		clock.restart();
		time = time / 500;
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		if ((a.y >= b.y) && ((a.y - 10) <= b.y) && (time >= 0.1) && (b.x >= a.x - a.w) && (b.x <= (a.x + a.w))) {
			b.y = b.y - 30;
			b.dx = b.dx;
			b.dy = -b.dy - 0.01 * b.dx;
			b.update(time);
		}
		if (((b.x >= 0) && (b.x <= 32)) || ((b.x >= 672) && (b.x <= 704))) {
			b.dx = -b.dx;
			b.update(time);
		}
		if ((b.y >= 0) && (b.y <= 32)) {
			b.dy = -b.dy;
			b.update(time);
		}
		/*control*/
		if ((Keyboard::isKeyPressed(Keyboard::A)) || (Keyboard::isKeyPressed(Keyboard::Left)))
		{
			a.dir = 1; a.speed = 0.2;
		}
		if ((Keyboard::isKeyPressed(Keyboard::D)) || (Keyboard::isKeyPressed(Keyboard::Right)))
		{
			a.dir = 0; a.speed = 0.2;
		}
		/**/
		/*init*/


		if ((a.y+4*b.d) <= b.y) {
			break;
		}
		if ((b.y <= (0 + 2 * b.d))) {
			b.dy = -b.dy;
			b.y = b.y + 20;

		}
		a.update(time);
		b.update(time);
		window.clear();
		/*lvl_gen*/

		for (int i = 0; i < HEIGHT_LVL; i++)
			for (int j = 0; j < WIDTH_LVL; j++)
			{
					if (BlockLVL[i][j] == '1') {
							s_block.setTextureRect(IntRect(0, 0, 32, 32));
					}
					if (BlockLVL[i][j] == '2') {
						s_block.setTextureRect(IntRect(96, 0, 32, 32));
					}
					if (BlockLVL[i][j] == '4') {
							s_block.setTextureRect(IntRect(32, 0, 32, 32));
					}
					if (BlockLVL[i][j] == '0') {
						s_block.setTextureRect(IntRect(64, 0, 32, 32));
					}
				s_block.setPosition(j * 32, i * 32);
				window.draw(s_block);
			}
		window.draw(a.sprite);
		window.draw(b.sprite);
		if ((!C1) && (!C2)) {
			text.setString("U WIN!");
			text.setPosition(160, 300);
			window.draw(text);
			window.display();
			while (endtimer <= 100000000) {
				endtimer += time;
			}
			break;

		}
		window.display();
		/**/
	}

	return 0;
}
/**/