PROGRAM = ./bin/GerenciadorSCRUM.exe
CC = clang++
CFLAGS = -O0 -Wall -ansi -pedantic -g -I$(DEPS) -fsanitize=address
CPROD = O0 -Wall -ansi -pedantic -I$(DEPS)
OBJS = ./build/evento.o ./build/time.o ./build/enums.o ./build/gerenciador.o ./build/utilities.o ./build/paginas.o
ODIR = ./build
CDIR = ./src
DEPS = ./include

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(CDIR)/%.cpp $(DEPS)/%.hpp
	$(CC) -c -o $@ $<

$(ODIR)/gerenciador.o: $(CDIR)/gerenciador.cpp $(DEPS)/*
	$(CC) -c $(CDIR)/gerenciador.cpp -o $@

Prod: $(OBJS)
	$(CC) $(CPROD) -o $(PROGRAM) $^

unixC: 
	rm -f ./build/*.o ./bin/*

c:
	del .\build\*.o .\bin\*

r: $(PROGRAM) 
	$(PROGRAM)
run: c $(PROGRAM) 
	$(PROGRAM)
