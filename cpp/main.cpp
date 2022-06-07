#include "main.h"

int main()
{
	Logger l;
	l.setLevel(Logger::Level::WARN);

	Bar bar1;
	bar1.data = 111;
	l.debug(&bar1);

	Bar bar2;
	bar2.data = 222;
	l.debug(&bar2);

	return 0;
}
