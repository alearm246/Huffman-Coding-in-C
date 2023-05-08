all: final

final: main.o linkedlist.o priorityqueue.o huffman_tree_node.o tests.o
	gcc main.o linkedlist.o priorityqueue.o huffman_tree_node.o tests.o -o final
	final.exe

main.o: main.c
	gcc -c main.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

priorityqueue.o: priorityqueue.c
	gcc -c priorityqueue.c

huffman_tree_node.o: huffman_tree_node.c
	gcc -c huffman_tree_node.c

tests.o: tests.c
	gcc -c tests.c

clean:
	rm main.o linkedlist.o priorityqueue.o final