suggest_err:          suggest_err.o error_functions.o
	gcc -pthread -o suggest_err suggest_err.o error_functions.o

error_functions.o:    error_functions.c
	gcc -c error_functions.c

suggest_err.o:        suggest_err.c
	gcc -c suggest_err.c

clean:
	rm *.o
	rm suggest_err
