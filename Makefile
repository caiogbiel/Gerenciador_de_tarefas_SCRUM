PROGRAM = GerenciadorSCRUM.exe
CC = g++
CFLAGS = -O0 -Wall -Ansi -pedantic
OBJS = #adicionar arquivos objeto: projeto.o etc

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)

#projeto.o:
#	$(CC) -c projeto.cpp

unixC: 
	rm -f *.o *.exe

c:
	del *.o *.exe

run: c all
	$(PROGRAM)
