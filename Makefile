CC = g++
CFLAGS = -D_GLIBCXX_DEBUG -I./ -I$(INCLUDES_CPP)

all: pro2.exe
pro2.exe : ListaPaises.o mini_red.o pro2.o  mini_industria.o sector.o
	$(CC) $(CFLAGS) -o pro2.exe pro2.o mini_red.o ListaPaises.o mini_industria.o sector.o
sector.o : sector.cpp sector.hpp dep.hpp
	$(CC) $(CFLAGS) -c sector.cpp
pro2.o : pro2.cpp mini_red.hpp mini_industria.hpp ListaPaises.hpp
	$(CC) $(CFLAGS) -c pro2.cpp
mini_red.o : mini_red.cpp mini_red.hpp ListaPaises.hpp
	$(CC) $(CFLAGS) -c mini_red.cpp
mini_industria.o : mini_industria.hpp mini_industria.cpp ListaPaises.hpp
	$(CC) $(CFLAGS) -c mini_industria.cpp
ListaPaises.o : ListaPaises.hpp ListaPaises.cpp
	$(CC) $(CFLAGS) -c ListaPaises.cpp

