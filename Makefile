STD = -std=c99
OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g

hospital-corona: main.c user.c user.h patient.c patient.h validator.c validator.h
	gcc $(STD) $(OPTIONS) main.c user.c patient.c validator.c -o hospital-corona
