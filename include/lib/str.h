/* lib/str.h */
#ifndef LIB_STR
#define LIB_STR

#include <stddef.h>

typedef char char_t;

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, oldSize, newSize)                            \
  (type*)reallocate(pointer, sizeof(type) * (oldSize), sizeof(type) * (newSize))

#define FREE_ARRAY(type, pointer, oldSize)                                     \
  reallocate(pointer, sizeof(type) * (oldSize), 0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

typedef struct {
  char_t* data;
  size_t size;
  size_t capacity;
} String;

String String_create(char char_str[]);

void String_init(String* string);

void String_free(String* string);

void String_write_char(String* string, char ch);

void String_write_chars(String* string, char chars[]);

void String_append(String* dest, String* src);

String String_concat(String* str1, String* str2);

void String_printf(String* string, char fmt_str[]);

#endif /* LIB_STR */
