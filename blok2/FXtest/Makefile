CC = g++
CFLAGS = -Wall -I/usr/local/include

OBJ= FXtest.o TestSine.o Bitcrusher.o 
all: FXtest

FXtest: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
