/**
 *  This module is a lexical analyzer for ice9 language
 *
 */
#ifndef LEXER_H
#define LEXER_H

/*All the token types*/
enum __token_type_t{
	TK_ID,
	TK_STR,
	TK_INT,
	TK_KEY_IF,
	TK_KEY_DO,
	TK_KEY_FA,
	TK_KEY_BREAK,
	TK_SEMICOLON,
	TK_KEY_EXIT,
	TK_KEY_RETURN,
	TK_ASSIGN,
	TK_KEY_WRITE,
	TK_KEY_WRITES,
	TK_BLOCK,
	TK_KEY_ELSE,
	TK_THEN,
	TK_PROC,
	TK_LPAREN,
	TK_RPAREN,
	TK_KEY_END,
	TK_COMMA,
        TK_KEY_VAR,
	TK_COLON,
	TK_LBRACKET,
	TK_RBRACKET,
	TK_KEY_TRUE,
	TK_KEY_FALSE,
	TK_KEY_READ,
	TK_MINUS,
	TK_HOOK,
	TK_PLUS,
	TK_STAR,
	TK_SLASH,
	TK_MOD,
	TK_EQ,
	TK_NEQ,
	TK_GT,
	TK_LT,
	TK_LE,
	TK_GE
};

typedef enum __token_type_t token_type_t;

/**
 * Token definition
 */
struct __token_t {
   char* lexeme;
   token_type_t type;
};

typedef struct __token_t token_t;

/*This method fetches the next token*/
token_t get_next_token();

/*This method gets the current line no*/
int get_line_no();

#endif
