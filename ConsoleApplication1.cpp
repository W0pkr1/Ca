#include "step_funcs.h"
int main()
{
	gillder_test();
	int number_of_steps = 30;
	std::vector<bool> d1(h * w);

	generate(d1.begin(), d1.end(), rg::gen);

	table t1(h, w, d1);

	std::ofstream handler("data/conway.txt");
	t1.write_table_out(handler);

	for (int i = 0; i < number_of_steps; ++i)
	{
		// One step
		t1.do_game();

		//Write out results
		t1.write_table_out(handler);
	}

	handler.close();

	std::ofstream cfg("cfg.txt");
	cfg << number_of_steps << ' ' << w << ' ' << h;
	cfg.close();

}