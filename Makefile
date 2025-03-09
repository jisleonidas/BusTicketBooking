CC=gcc
SRCFILES=constants.c  func.c  init.c  main.c  util.c
OBJFILES=constants.o  func.o  init.o  main.o  util.o

main: $(OBJFILES)
	$(CC) -o main $(OBJFILES)

$(OBJFILES): $(SRCFILES)
	$(CC) -c $(SRCFILES)

.PHONY=clean
clean:
	rm *.o
	rm main
