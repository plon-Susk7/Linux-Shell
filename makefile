all:
	gcc ls.c -o ls
	gcc date.c -o date
	gcc rm.c -o rm
	gcc cat.c -o cat
	gcc mkdir.c -o mkdir
	gcc -pthread -o main main.c
	./main
