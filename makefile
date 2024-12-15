wordle: wordle.c
	gcc -o ./outputs/wordle.o wordle.c
	./outputs/wordle.o

day1half2: ./adventOfCode/day1half2.c
	gcc -o ./outputs/day1half2.o ./adventOfCode/day1half2.c
	./outputs/day1half2.o

day1half1: ./adventOfCode/day1half1.c
	gcc -o ./outputs/day1half1.o ./adventOfCode/day1half1.c
	./outputs/day1half1.o