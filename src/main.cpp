#include <iostream>
#include "GameLoopMain.hpp"

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	GameLoopMain loop;
	loop.main();
}