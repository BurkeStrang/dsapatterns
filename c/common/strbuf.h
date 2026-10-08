// StrBuf is a growable string, used where Go would use strings.Builder or a
// []rune that is appended to.
#ifndef DSAPATTERNS_COMMON_STRBUF_H
#define DSAPATTERNS_COMMON_STRBUF_H

#include <stdlib.h>
#include <string.h>

// A zeroed StrBuf is an empty string.
typedef struct
{
    char *data; // always ends with '\0' once anything has been added
    int len;
    int cap;
} StrBuf;

static inline void strbuf_reserve
(
    StrBuf *buf,
    int extra
)
{
    int needed = buf->len + extra + 1;
    if (needed > buf->cap)
    {
        buf->cap = needed < 16 ? 16 : needed * 2;
        buf->data = realloc(buf->data, (size_t)buf->cap);
    }
}

// strbuf_push appends one character.
static inline void strbuf_push
(
    StrBuf *buf,
    char c
)
{
    strbuf_reserve(buf, 1);
    buf->data[buf->len++] = c;
    buf->data[buf->len] = '\0';
}

// strbuf_append appends a whole string.
static inline void strbuf_append
(
    StrBuf *buf,
    const char *text
)
{
    int text_len = (int)strlen(text);
    strbuf_reserve(buf, text_len);
    memcpy(buf->data + buf->len, text, (size_t)text_len + 1);
    buf->len += text_len;
}

// strbuf_pop removes and returns the last character.
static inline char strbuf_pop
(
    StrBuf *buf
)
{
    char c = buf->data[--buf->len];
    buf->data[buf->len] = '\0';
    return c;
}

// strbuf_take hands the finished string to the caller, who must free it, and
// leaves the buffer empty.
static inline char *strbuf_take
(
    StrBuf *buf
)
{
    strbuf_reserve(buf, 0);
    buf->data[buf->len] = '\0';
    char *text = buf->data;
    *buf = (StrBuf){0};
    return text;
}

static inline void strbuf_free
(
    StrBuf *buf
)
{
    free(buf->data);
    *buf = (StrBuf){0};
}

#endif
