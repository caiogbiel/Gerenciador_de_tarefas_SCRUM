PROGRAM = ./bin/GerenciadorSCRUM.exe
CC = clang++
CFLAGS = -O0 -Wall -Ansi -pedantic -fsanitize=address -g
OBJS = ./build/evento.o ./build/gerenciador.o
ODIR = build
CDIR = src
# DEPS = include

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(CDIR)/%.cpp #$(DEPS)/%.hpp
	$(CC) -c -o $@ $<

unixC: 
	rm -f ./build/*.o ./bin/*.exe

c:
	del .\build\*.o .\bin\*.exe

run: c $(PROGRAM) 
	$(PROGRAM)
