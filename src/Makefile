CC = gcc
SRC = main.c \
src/builtins.c\
src/executor.c\
src/lexer.c\
src/parser.c

USE_LIBREADLINE = -DUSE_LIBREADLINE -lreadline
# comment above line to remove 'readline' dependency

CFLAGS = -Wall -Wextra -fPIC $(USE_LIBREADLINE)

OUTDIR = build
OUT = $(OUTDIR)/Exsh

$(OUT): $(SRC)
	mkdir -p $(OUTDIR)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -rf build
