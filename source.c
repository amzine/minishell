#include <errno.h>
#include "shell.h"
#include "scanner.h"

void unget_char(src_a *src)
{
    if (src->curpos < 0)
    {
        return ;
    }

    src->curpos--;
}

char next_char(src_a *src)
{
    if (!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }
    
    char c1 = 0;
    if (src->curpos == INIT_SRC_POS)
    {
        src->curpos = -1;
    }
    else
    {
        c1 = src->buffer[src->curpos];
    }
    if (++src->curpos >= src->bufsize)
    {
        src->curpos = src->bufsize;
        return EOF;
    }
    
    return src->buffer[src->curpos];
}

char peek_char(src_a *src)
{
    if (!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }
    
    long pos = src->curpos;

    if (pos == INIT_SRC_POS)
    {
        pos++;
    }
    pos++;

    if (pos >= src->bufsize)
    {
        return EOF;
    }
    return src->buffer[pos];
}

void    skip_white_space(src_a *src)
{
    char c;

    if (!src || !src->buffer)
    {
        return ;
    }

    while (((c == peek_char(src)) != EOF ) && (c == ' ' || c == '\t'))
    {
        next_char(src);
    } 
}