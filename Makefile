PROGRAM = ./bin/GerenciadorSCRUM.exe
CC = clang++
CFLAGS = -O0 -Wall -ansi -pedantic -g -I$(DEPS) -fsanitize=address
OBJS = ./build/evento.o ./build/time.o ./build/enums.o ./build/utilities.o ./build/paginas.o ./build/arquivos.o ./build/gerenciador.o
ODIR = ./build
CDIR = ./src
DEPS = ./include

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(CDIR)/%.cpp $(DEPS)/%.hpp
	$(CC) -c -o $@ $<

$(ODIR)/gerenciador.o: $(CDIR)/gerenciador.cpp $(DEPS)/*
	$(CC) -c $(CDIR)/gerenciador.cpp -o $@

unixC: 
	rm -f ./build/*.o ./bin/*

c:
	del .\build\*.o .\bin\*

r: $(PROGRAM) 
	$(PROGRAM)
run: c $(PROGRAM) 
	$(PROGRAM)
