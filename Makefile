all: final

final: main.o linkedlist.o priorityqueue.o
	gcc main.o linkedlist.o priorityqueue.o -o final
	final.exe

main.o: main.c
	gcc -c main.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

priorityqueue.o: priorityqueue.c
	gcc -c priorityqueue.c

clean:
	rm main.o linkedlist.o priorityqueue.o final