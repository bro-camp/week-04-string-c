/* main.c */

#include "lib/str.h"
#include <stdio.h>

void test_string_write_functions();
void test_string_printf();
void test_string_append();
void test_string_create();
void test_string_concat();

int main() {
  test_string_write_functions();
  test_string_printf();
  test_string_append();
  test_string_create();
  test_string_concat();

  return 0;
}

void test_string_write_functions() {
  String string;
  String_init(&string);

  String_write_chars(&string, "Hello, world");
  String_write_char(&string, '!');
  String_write_chars(&string, "\n");

  int i;
  for (i = 0; i < string.size; ++i) {
    printf("%c", string.data[i]);
  }

  // DEALLOCATIONS
  String_free(&string);
  return;
}

void test_string_printf() {
  String string;
  String_init(&string);

  String_write_chars(&string, "Hello, world");
  String_write_char(&string, '!');
  String_write_chars(&string, "!!");

  String_printf(&string, "[%s]\n");

  // DEALLOCATIONS
  String_free(&string);
  return;
}

void test_string_append() {
  String str1;
  String str2;

  String_init(&str1);
  String_init(&str2);

  String_write_chars(&str1, "Hello,");
  String_write_chars(&str2, " world!");

  String_printf(&str1, "str1: \"%s\"\n");
  String_printf(&str2, "str2: \"%s\"\n");

  String_append(&str1, &str2);

  String_printf(&str1, "st1 after appending: \"%s\"\n");

  // DEALLOCATIONS
  String_free(&str1);
  String_free(&str2);
  return;
}

void test_string_create() {
  String string = String_create("Hello, World!");

  String_printf(&string, "\"%s\"\n");

  // DEALLOCATIONS
  String_free(&string);
  return;
}

void test_string_concat() {
  String str1;
  String str2;
  String str;

  String_init(&str1);
  String_init(&str2);
  String_init(&str);

  String_write_chars(&str1, "Hello,");
  String_write_chars(&str2, " world!");

  String_printf(&str1, "str1: \"%s\"\n");
  String_printf(&str2, "str2: \"%s\"\n");

  str = String_concat(&str1, &str2);

  String_printf(&str, "str after concatenating: \"%s\"\n");

  // DEALLOCATIONS
  String_free(&str1);
  String_free(&str2);
  String_free(&str);
  return;
}
