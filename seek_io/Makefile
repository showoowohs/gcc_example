seek_io:  seek_io.o error_functions.o get_num.o
	gcc -o seek_io seek_io.o error_functions.o get_num.o

get_num.o:    get_num.c
	gcc -c get_num.c


error_functions.o:    error_functions.c
	gcc -c error_functions.c

seek_io.o:        seek_io.c
	gcc -c seek_io.c

clean:
	rm *.o
	rm seek_io
