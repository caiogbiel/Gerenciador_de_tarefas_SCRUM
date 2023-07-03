PROGRAM = ./bin/GerenciadorSCRUM.exe
CC = clang++
CFLAGS = -O0 -Wall -ansi -pedantic -g -I$(DEPS) -fsanitize=address
OBJS = ./build/evento.o ./build/time.o ./build/gerenciador.o ./build/utilities.o
ODIR = ./build
CDIR = ./src
DEPS = ./include

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(CDIR)/%.cpp $(DEPS)/%.hpp
	$(CC) -c -o $@ $<
	
$(ODIR)/gerenciador.o: $(CDIR)/gerenciador.cpp $(DEPS)/*
	$(CC) -c $(CDIR)/gerenciador.cpp -o $@

# $(ODIR)/evento.o: $(DEPS)/evento.hpp
# 	$(CC) -c $(CDIR)/evento.cpp -o $@

# $(ODIR)/time.o: $(DEPS)/time.hpp
# 	$(CC) -c $(CDIR)/time.cpp -o $@

unixC: 
	rm -f ./build/*.o ./bin/*

c:
	del .\build\*.o .\bin\*

run: c $(PROGRAM) 
	$(PROGRAM)
