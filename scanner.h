#if !defined(SCANNER_H)
#define SCANNER_H

#define EOF -1
#define ERRCHAR 0
#define INIT_SRC_POS -2

typedef struct source_s
{
    char *buffer;   /*the input text */
    long bufsize;   /*size of the input text*/   
    long curpos;    /*absolute char position in source */
}src_a;

typedef struct token_s
{
    src_a *src;     /*source of input */
    int text_len;   /* length of token text */
    char *text;     /* token text */
}tkn_s;

/* the special EOF toke , wich indicates the end of input */
extern tkn_s eof_token;


char    next_char(src_a *src);
void    unget_char(src_a *src);
char    peek_char(src_a *src);
void    skip_white_spaces(src_a *src);

/*token function*/

tkn_s *tokenize(src_a *src);
void    free_token(tkn_s *tok);


#endif
