CFLAGS = -std=gnu99
OBJ =  states.o display.o lifesim.o

all: lifesim
lifesim: $(OBJ)
	$(CC) -o lifesim $(OBJ)

states.o: defref.h common.h nodes.h states.h display.h
display.o: defref.h common.h display.h
lifesim.o: defref.h nodes.h states.h display.h

clean:
	@rm *.o
clean_all:
	@make clean
	@rm lifesim
