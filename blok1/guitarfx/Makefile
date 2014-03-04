CC = g++
CFLAGS = -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lportaudio

OBJ= guitarfx.o audio_io.o amplifier.o tremolo.o bitcrusher.o

all: guitarfx

guitarfx: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`

