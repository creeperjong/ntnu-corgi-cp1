all:array_sort.o determinant.o minesweeper.o regression.o poly.o
	gcc hw0501.c array_sort.o -o hw0501 
	gcc hw0502.c determinant.o -o hw0502
	gcc hw0503.c poly.o -o hw0503
	gcc hw0504.c regression.o -o hw0504 -lm
	gcc hw0505.c minesweeper.o -o hw0505
array_sort:
	gcc -c array_sort.c -o array_sort.o
determinant:
	gcc -c determinant.c -o determinant.o
poly:
	gcc -c poly.c -o poly.o
regression:
	gcc -c regression.c -o regression.o 
minesweeper:
	gcc -c minesweeper.c -o minesweeper.o
clean:
	rm -rf *.o hw0501 hw0502 hw0503 hw0504 hw0505