/* lib/str.c */
#include "lib/str.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1);
  return result;
}

String String_create(char char_str[]) {
  String string;
  String_init(&string);
  String_write_chars(&string, char_str);
  return string;
}

void String_init(String* string) {
  string->data = NULL;
  string->size = 0;
  string->capacity = 0;
}

void String_free(String* string) {
  FREE_ARRAY(char_t, string->data, string->capacity);
  String_init(string);
}

void String_write_char(String* string, char ch) {
  if (string->capacity < string->size + 1) {
    int old_capacity = string->capacity;
    string->capacity = GROW_CAPACITY(old_capacity);
    string->data
        = GROW_ARRAY(char_t, string->data, old_capacity, string->capacity);
  }

  string->data[string->size] = ch;
  ++(string->size);
}

void String_write_chars(String* string, char chars[]) {
  int i;
  char_t ch;
  for (i = 0; (ch = chars[i]) != '\0'; ++i) {
    String_write_char(string, ch);
  }
}

void String_append(String* dest, String* src) {
  int i;
  for (i = 0; i < src->size; ++i) {
    String_write_char(dest, src->data[i]);
  }
}

String String_concat(String* str1, String* str2) {
  String string;
  String_init(&string);

  int i;
  for (i = 0; i < str1->size; ++i) {
    String_write_char(&string, (char)str1->data[i]);
  }
  for (i = 0; i < str2->size; ++i) {
    String_write_char(&string, (char)str2->data[i]);
  }

  return string;
}

void String_printf(String* string, char fmt_str[]) {
  char* str = NULL;
  str = (char*)malloc((sizeof(char) * string->size) + 1);
  int i;
  for (i = 0; i < string->size; ++i) {
    str[i] = string->data[i];
  }

  str[string->size] = '\0';

  printf(fmt_str, str);

  free(str);
}
