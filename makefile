all : build

build :
	clang token_manip.c parser.c main.c
