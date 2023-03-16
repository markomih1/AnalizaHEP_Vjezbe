CC=g++
CFLAGS=-I. $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)
DEPS = Analyzer1.h

%.o: %.cpp $(DEPS)
	$(CC) $(LDFLAGS) -c -o $@ $< $(CFLAGS)

analyzer1: analyze1.o Analyzer1.o
	$(CC) $(LDFLAGS) -o analyze1 analyze1.o Analyzer1.o

clean:
	rm -rf *.o analyze1
