#include "util.hpp"
#include <fstream>
#include <random>

std::random_device rnd;
std::ofstream out("log");

namespace util{
void log(std::string str)
{
	out << str << std::endl;
}

int rand(int i)
{
	return rnd()%i;
}
}
