thread_create:  thread_create.o errExit.o
	        gcc -pthread -o thread_create thread_create.o errExit.o

thread_create.o:        thread_create.c
	        gcc -c thread_create.c

errExit.o:        errExit.c
	        gcc -c errExit.c

clean:
	    	rm *.o
		rm thread_create
