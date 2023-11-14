#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{

	while (true)
	{
		Game game(Game::HUMANVHUMAN);

		if (!game.run())
		{
			break;
		}
	}

	return 0;
}
