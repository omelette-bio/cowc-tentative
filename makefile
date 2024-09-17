all : build

build :
	clang token_manip.c parser.c analyser_semantique.c main.c
