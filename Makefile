

check_numerals: numerals.o
	gcc    check_numerals.c numerals.o -o check_numerals -lcheck_pic -pthread -lrt -lm -lsubunit


numerals.o: numerals.c
	gcc -c numerals.c

clean:
	rm -rf *.o