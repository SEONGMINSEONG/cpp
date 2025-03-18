#include <stdio.h>
class GuguGame
{
private:
	int		from;
	int		to;
public:
	GuguGame() { set(1, 9); }
	~GuguGame() {}
	void set(int f, int t) { from = f; to = t; }
	void play(int dan) {
		printf("[객체지향 프로그래밍]\n");
		printf("[구구단 %d 단]\n", dan);
		for (int i = from; i <= to; i++) {
			printf("%2d x %2d = %2d\n",
				dan, i, dan*i);
		}
	}
};
void main()
{
	// 객체 지향적인 프로그래밍
	GuguGame myGame;
	myGame.play(3);
	myGame.set(2, 9);
	myGame.play(3);
}