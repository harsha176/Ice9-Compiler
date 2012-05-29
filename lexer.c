/**
 * Lexer implementation file
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

/*Boolean data type definition*/
enum _bool_t {
    TRUE, FALSE
};

typedef enum _bool_t bool_t;

/*Pointer to the file to be processed*/
FILE *fp = NULL;

/*defining key tokens*/
token_t key_tokens[] = {
    /*key words */
    {"if", TK_KEY_IF},
    {"do", TK_KEY_DO},
    {"fa", TK_KEY_FA},
    {"break", TK_KEY_BREAK},
    {"exit", TK_KEY_EXIT},
    {"return", TK_KEY_RETURN},
    {"write", TK_KEY_WRITE},
    {"writes", TK_KEY_WRITES},
    {"else", TK_KEY_ELSE},
    {"proc", TK_KEY_PROC},
    {"true", TK_KEY_TRUE},
    {"false", TK_KEY_FALSE},
    {"read", TK_KEY_READ},
    {"end", TK_KEY_END},
    {"var", TK_KEY_VAR},

    /*Operators */
    {";", TK_SEMICOLON},
    {":=", TK_ASSIGN},
    {"->", TK_BLOCK},
    {"[]", TK_THEN},
    {"(", TK_LPAREN},
    {")", TK_RPAREN},
    {":", TK_COLON},
    {",", TK_COMMA},
    {"[", TK_LBRACKET},
    {"]", TK_RBRACKET},
    {"-", TK_MINUS},
    {"+", TK_PLUS},
    {"*", TK_STAR},
    {"/", TK_SLASH},
    {"%", TK_MOD},
    {"=", TK_EQ},
    {"!=", TK_NEQ},
    {">", TK_GT},
    {"<", TK_LT},
    {">=", TK_GE},
    {"<=", TK_LE},

    /*Internal token */
    {"error", TK_ERROR}
};

/*
 * This method checks a lexeme of type id with keyword
 * Input: candidate lexeme should end with NULL character
 * Output: appropriate token or NULL
 */
token_t *_is_keyword_token(char *lexeme)
{
    int i = 0;

    /*check if its a key token */
    for (i = 0; i < KEY_TOKENS_SIZE; i++) {
	if (!strcmp(lexeme, key_tokens[i].lexeme)) {
	    /*return the key token */
	    return key_tokens + i;
	}
    }
    return NULL;
}


/*This method intializes lexer with the file to be compiled*/
void initialzie_lexer(char *filename)
{
    fp = fopen(filename, "r");
    if (!fp) {
	perror("Failed to open input file");
	return;
    }
    //intialzie size of the tokens list
    KEY_TOKENS_SIZE = sizeof(key_tokens) / sizeof(token_t);
}

/*This method fetches next token*/
token_t *get_next_token()
{
    /*check if the file is initialized */
    if (!fp) {
	perror("Failed to initialize lexer");
	return NULL;
    }

    int ch;
    token_t *curr_token = (token_t *) malloc(sizeof(token_t));

    if (!curr_token) {
	perror("Failed to allocate memory");
	return NULL;
    }

    while ((ch = getc(fp)) != EOF && !isspace(ch)) {
	//Identify token based on state machine
	switch (ch) {
	case '+':
	    curr_token->lexeme = strdup("+");
	    curr_token->type = TK_PLUS;
	    break;
	case '-':
	    curr_token->lexeme = strdup("-");
	    curr_token->type = TK_MINUS;
	    break;
	case '*':
	    curr_token->lexeme = strdup("*");
	    curr_token->type = TK_STAR;
	    break;
	case '/':
	    curr_token->lexeme = strdup("/");
	    curr_token->type = TK_SLASH;
	    break;
	case '>':
	    if (getc(fp) == '=') {
		curr_token->lexeme = strdup(">=");
		curr_token->type = TK_GT;
	    } else {
		ungetc(ch, fp);
		curr_token->lexeme = strdup(">");
		curr_token->type = TK_GE;
	    }
	    break;
	case '<':  
	    if (getc(fp) == '=') {
		curr_token->lexeme = strdup("<=");
		curr_token->type = TK_LT;
	    } else {
		ungetc(ch, fp);
		curr_token->lexeme = strdup("<");
		curr_token->type = TK_LE;
	    }
	    break;
	 case '%':
	    curr_token->lexeme = strdup("%");
	    curr_token->type = TK_MOD;
	    break;	    
	 case '#':
	    //comment ignore it till end of line
	    while(getc(fp) != '\n');
	    continue;    
	    break;
	default:
	    //TODO integer literal
	    //if(isdigit(ch))
	    fprintf(stdout, "processing token\n");
	    curr_token = &key_tokens[KEY_TOKENS_SIZE-1];
	}
    }
    if(!feof(fp)) {
	    return NULL;
    }
    return curr_token;
}

#if 0
int main()
{
    return 0;
}
#endif
