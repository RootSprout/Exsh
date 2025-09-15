#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/executor.h"

#ifdef USE_LIBREADLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main() {
	char line[1024];
	const char *prompt = "Exsh$ ";

	while (1) {
#ifdef USE_LIBREADLINE
		strncpy(line, readline(prompt), 1024);
		add_history(line);
#else
		printf(prompt);
		if (!fgets(line, sizeof(line), stdin)) break;
#endif
		int ntokens;
		char **tokens = tokenize(line, &ntokens);
		if (ntokens == 0) continue;

		Command *cmds = parse_tokens(tokens, ntokens);
		execute_commands(cmds);
		free_cmd(cmds);
	}

	return EXIT_SUCCESS;
}
