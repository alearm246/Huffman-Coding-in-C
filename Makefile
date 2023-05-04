all: final

final: main.o linkedlist.o
	gcc main.o linkedlist.o -o final

main.o: main.c
	gcc -c main.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

clean:
	rm main.o linkedlist.o final