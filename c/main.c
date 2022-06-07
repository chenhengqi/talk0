#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

void print(const char *str)
{
	printf("%s", str);
}

int main()
{
	struct stat statbuf;
	void *mmapped;
	int fd, err;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0) {
		perror("open");
		return -1;
	}

	err = fstat(fd, &statbuf);
	if (err) {
		perror("fstat");
		return -1;
	}

	mmapped = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mmapped == MAP_FAILED) {
		perror("mmap");
		return -1;
	}

	print(mmapped);
	return 0;
}
