build:
	gcc -g main.c

run:
	./a.out

right:
	BPFTRACE_STRLEN=200 ./right.bt

wrong:
	BPFTRACE_STRLEN=200 ./wrong.bt

clean:
	rm -f a.out
