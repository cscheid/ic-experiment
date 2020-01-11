all: main

clean:
	rm main

main:
	g++ -O2 -g -pg main.cpp -o main -std=c++11
