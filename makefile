all : build

build :
	clang token_manip.c parser.c analyser_semantique.c gen_code.c main.c -o cow2c
