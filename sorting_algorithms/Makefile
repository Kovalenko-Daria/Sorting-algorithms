different_sort: sort.o different_sort.o
	gcc -Wall -Werror -Wextra sort.o different_sort.o -o different_sort

different_sort.o: different_sort.c
	gcc -Wall -Werror -Wextra -c different_sort.c -o different_sort.o

sort.o: sort.c
	gcc -Wall -Werror -Wextra -c sort.c -o sort.o

.PHONY:rebuild clean all
 
rebuild:clean all

clean:
	rm -rf *.o different_sort

all: different_sort