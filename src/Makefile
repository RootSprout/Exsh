CC = gcc
SRC = main.c \
src/builtins.c\
src/executor.c\
src/lexer.c\
src/parser.c

OUTDIR = build
OUT = $(OUTDIR)/Exsh

$(OUT): $(SRC)
	mkdir -p $(OUTDIR)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -rf build
