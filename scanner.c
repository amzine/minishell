#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "shell.h"
#include "scanner.h"

char *tok_buf = NULL;
int tok_buffsize = 0;
int tok_buffindex = -1;

struct token_s eof_token = 
{
    .text_len = 0

};
 
void add_to_buf(char c)
{
    tok_buf[tok_buffindex++] = c;

    if (tok_buffindex >= tok_buffsize)
    {
        char *tmp = realloc(tok_buf , tok_buffsize * 2);

        if (!tmp)
        {
            errno = ENOMEM;
            return;
        }
        
        tok_buf = tmp;
        tok_buffsize *= 2;
    }
}

tkn_s *create_token(char *str)
{
    tkn_s *tok = malloc(sizeof(tkn_s));
    if (!tok)
        return NULL;
    
    memset(tok, 0 ,sizeof(tkn_s));
    tok->text_len = strlen(str);

    char *nstr = malloc(tok->text_len + 1);

    if (!nstr)
    {
        free(tok);
        return NULL;
    }
    strcpy(nstr,str);
    tok->text = nstr;

    return tok;
}

void    free_token(tkn_s *tok)
{
    if (tok->text)
    {
        free(tok->text);
    }
    free(tok);
}

tkn_s *tokenize(src_a *src)
{
    int endloop = 0;

    if (!src || !src->buffer || !src->bufsize)
    {
        errno = ENODATA;
        return &eof_token;
    }
    
    if (!tok_buf)
    {
        tok_buffsize = 1024;
        tok_buf = malloc(tok_buffsize);
        if (!tok_buf)
        {
            errno = ENOMEM;
            return &eof_token;
        }
    }

    tok_buffindex = 0;
    tok_buf[0] = '\0';
    
    char nc = next_char(src);

    if (nc == ERRCHAR || nc == EOF)
    {
        return &eof_token;
    }
    while ((nc = next_char(src)) != EOF)
    {
        
    }
    
    
    
}



