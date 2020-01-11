all: main

clean:
	rm main

################################################################################

debug:
	g++ -g main.cpp -o main -std=c++11

profile:
	g++ -O2 -g -pg main.cpp -o main -std=c++11

main:
	g++ -O2 main.cpp -o main -std=c++11
