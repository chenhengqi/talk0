#include "main.h"

int main()
{
	Bar bar;
	printf("sizeof(struct Bar): %lu\n", sizeof(bar));
	printf("bar.data: %d\n", bar.data);
	for (int i = 0; i < 4; i++) {
		auto p = (int *)((char *)&bar + (i * 4));
		printf("0x%0x: %d\n", p, *p);
	}
	return 0;
}
