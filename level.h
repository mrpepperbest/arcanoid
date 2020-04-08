
#include <SFML\Graphics.hpp>
const int HEIGHT_LVL= 22;//размер карты высота
const int WIDTH_LVL= 22;//размер карты ширина 
const int amount1 = 1;
const int amount2 = 1;

sf::String BlockLVL[HEIGHT_LVL] = {
	"4444444444444444444444",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
	"4000000000000000000004",
};
void randomLvlGenerate() {

	int randomElementX = 0;
	int randomElementY = 0;
	srand(time(0));
	int count2 = amount2, count1 = amount1;
	while ((count2 > 0) || (count1 > 0)) {
		randomElementX = 1 + rand() % (WIDTH_LVL - 1);
		randomElementY = 1 + rand() % (HEIGHT_LVL - 10);

		if (BlockLVL[randomElementY][randomElementX] == '0') {
			if (count2) {
				BlockLVL[randomElementY][randomElementX] = '2';
				count2--;
			}
			else {
				BlockLVL[randomElementY][randomElementX] = '1';
				count1--;
			}
		}
	}
}