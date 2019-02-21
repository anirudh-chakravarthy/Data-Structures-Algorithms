compRecMS: recMergeSort.c merge.h
	gcc recMergeSort.c -o rec

compIterMS: merge.h iterMergeSort.c
	gcc iterMergeSort.c -o iter

runRecMS: rec
	./rec
	rm rec

runIterMS: iter
	./iter
	rm iter