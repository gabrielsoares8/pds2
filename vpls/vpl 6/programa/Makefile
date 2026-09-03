CC = g++
CFLAGS = -Wall -Iinclude

all: vpl_execution

vpl_execution: build/Ponto.o build/Circulo.o build/main.o
	$(CC) build/Ponto.o build/Circulo.o build/main.o -o vpl_execution

build/Ponto.o: src/entidades/Ponto.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c src/entidades/Ponto.cpp -o build/Ponto.o

build/Circulo.o: src/entidades/Circulo.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c src/entidades/Circulo.cpp -o build/Circulo.o

build/main.o: src/main.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c src/main.cpp -o build/main.o

clean:
	rm -rf build vpl_execution