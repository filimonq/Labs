all: lab3.out file.txt

file:
	touch file.txt
	chmod 600 file.txt

lab3.out: lab3.c
	cc lab3.c -v -o lab3.out
	chmod u+s lab3.out