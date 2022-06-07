#pragma once

#include <cstdio>

struct Foo
{
	virtual void foo() {}

	int data = 1215;
};

struct Bar : public Foo
{
	int data = 216;
};


struct Logger {
	enum class Level {
		DEBUG,
		WARN,
	};

	void debug(struct Bar *bar) {
		if (level == Level::DEBUG) {
			printf("bar->data: %d\n", bar->data);
		}
	}

	void warn() {}

	void setLevel(Level l) {
		level = l;
	}

private:
	Level level;
};
