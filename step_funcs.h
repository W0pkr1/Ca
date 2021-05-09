#include <stdio.h>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

#include "table.h"

const int h = 50;
const int w = 50;


namespace rg
{
	//Creating a random number generator
	std::random_device rd{};
	std::mt19937 mersenne_engine{ rd() };
	std::uniform_real_distribution<float> dist{ 0, 100 };
	auto gen = []() { return dist(mersenne_engine) < 50 ? false : true; };


}

void gillder_test()
{
	std::ofstream handler("glidder/glidder.txt");
	std::vector<bool> g1 =
	{
		0,0,0,0,0,0,
		0,0,1,0,0,0,
		1,0,1,0,0,0,
		0,1,1,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0
	};

	table glidder(6, 6, g1);

	glidder.write_table_out(handler);
	for (int i = 0; i < 5; ++i)
	{
		glidder.do_game();
		glidder.write_table_out(handler);
	}
	handler.close();
}
