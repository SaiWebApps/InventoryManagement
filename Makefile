FILES=purchase.cpp history.cpp main.cpp
OPTFLAGS=-O3

all:
	g++ ${OPTFLAGS} ${FILES}

clean:
	rm a.out
