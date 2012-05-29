#include <stdio.h>
#include "lexer.h"

//extern token_t key_tokens[10];
//extern int KEY_TOKENS_SIZE;

void test_lexer(char* filename) {
	initialzie_lexer(filename);

        token_t* curr_token;

	fprintf(stdout, "%s\t%s\n", "TOKEN", "LEXEME");
	fprintf(stdout, "============================\n");

	//TODO
	while((curr_token = get_next_token())->type != TK_ERROR) {
	     if(curr_token != NULL) {	
             	fprintf(stdout, "%d\t%s\n", curr_token->type, curr_token->lexeme); 
	     } else {
		fprintf(stdout, "end of file reached\n");
	     }
	}

	fprintf(stdout, "parsed file successfully\n");
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
	    fprintf(stdout, "Usage %s <input_file>\n");
	    return 0;
    }	    

    //lexer testcase
    test_lexer(argv[1]);

    return 0;
}
