CC=g++
CFLAGS=-I. $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)
DEPS = Generator.h

%.o: %.cpp $(DEPS)
	$(CC) $(LDFLAGS) -c -o $@ $< $(CFLAGS)

analyze: analyze.o Generator.o
	$(CC) $(LDFLAGS) -o analyze analyze.o Generator.o

clean:
	rm -rf *.o analyze
