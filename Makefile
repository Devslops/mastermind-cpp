CFLAGS = -g -pedantic -Wall -Wextra

mastermind : main.o fonctions.o 
	g++ -g -o mastermind main.o fonctions.o

main.o : main.cpp
	g++ -c $(CFLAGS) main.cpp
fonctions.o : fonctions.cpp
	g++ -c $(CFLAGS) fonctions.cpp

clean:
	rm *.o mastermind
