use_definedandmacro:  use_definedandmacro.o
	        gcc -o use_definedandmacro use_definedandmacro.o

use_definedandmacro.o:        use_definedandmacro.c
	        gcc -DMESSAGE_FROM_MK=\"Hello!\" -c use_definedandmacro.c

clean:
	    	rm *.o
		rm use_definedandmacro
