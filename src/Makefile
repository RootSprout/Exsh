CC = gcc
SRC = main.c \
src/builtins.c\
src/executor.c\
src/lexer.c\
src/parser.c


OUT = Exsh

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)