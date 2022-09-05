// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINT_SIZE(typeName) ( printf("size of %s : %zu bytes \n", #typeName, sizeof(typeName)) )
#define PRINT_POINTER_SIZE(typeName, typeObj) ( printf("size of %s* is : %zu bytes \n", #typeName, sizeof(&typeObj)))

int main() {
  // Please print the sizes of the following types:
  // int, short, long, char, float, double, unsigned int, long long
  // uint8_t, uint16_t, uint32_t, and uint64_t, uint_fast8_t,
  // uint_fast16_t, uintmax_t, intmax_t, __int128, and student

  // Here's how to show the size of one type. See if you can define a macro
  // to avoid copy pasting this code.
  /* printf("size of %s : %zu bytes \n", "int", sizeof(int)); */
  // e.g. PRINT_SIZE("int", int);
  //      PRINT_SIZE("short", short);

  // Alternatively, you can use stringification
  // (https://gcc.gnu.org/onlinedocs/cpp/Stringification.html) so that
  // you can write
  // e.g. PRINT_SIZE(int);
  //      PRINT_SIZE(short);

  PRINT_SIZE(int);
  PRINT_SIZE(short);
  PRINT_SIZE(long);
  PRINT_SIZE(char);
  PRINT_SIZE(float);
  PRINT_SIZE(double);
  PRINT_SIZE(unsigned int);
  PRINT_SIZE(long long);
  PRINT_SIZE(uint8_t);
  PRINT_SIZE(uint16_t);
  PRINT_SIZE(uint32_t);
  PRINT_SIZE(uint64_t);
  PRINT_SIZE(uint_fast8_t);
  PRINT_SIZE(uint_fast16_t);
  PRINT_SIZE(uintmax_t);
  PRINT_SIZE(intmax_t);
  PRINT_SIZE(__int128);

  // Composite types have sizes too.
  typedef struct {
    int id;
    int year;
    char firstInitial;
  } student;

  student you;
  you.id = 12345;
  you.year = 4;
  you.firstInitial = 'p';


  // Array declaration. Use your macro to print the size of this.
  int x[5];

  // You can just use your macro here instead: PRINT_SIZE("student", you);
  PRINT_SIZE(student);
  PRINT_SIZE(x);


  // print out pointer sizes to different types
  int i;
  short s;
  long l;
  char c;
  float f;
  double d;
  unsigned int ui;
  long long ll;
  uint8_t ui8;
  uint16_t ui16;
  uint32_t ui32;
  uint64_t ui64;
  uint_fast8_t uif8;
  uint_fast16_t uif16;
  uintmax_t uiMax;
  intmax_t iMax;
  __int128 i128;

  PRINT_POINTER_SIZE(int, i);
  PRINT_POINTER_SIZE(short, s);
  PRINT_POINTER_SIZE(long, l);
  PRINT_POINTER_SIZE(char, c);
  PRINT_POINTER_SIZE(float, f);
  PRINT_POINTER_SIZE(double, d);
  PRINT_POINTER_SIZE(unsigned int, ui);
  PRINT_POINTER_SIZE(long long, ll);
  PRINT_POINTER_SIZE(uint8_t, ui8);
  PRINT_POINTER_SIZE(uint16_t, ui16);
  PRINT_POINTER_SIZE(uint32_t, ui32);
  PRINT_POINTER_SIZE(uint64_t, ui64);
  PRINT_POINTER_SIZE(uint_fast8_t, uif8);
  PRINT_POINTER_SIZE(uint_fast16_t, uif16);
  PRINT_POINTER_SIZE(uintmax_t, uiMax);
  PRINT_POINTER_SIZE(intmax_t, iMax);
  PRINT_POINTER_SIZE(__int128, i128);
  PRINT_POINTER_SIZE(student, you);
  PRINT_POINTER_SIZE(&x, x);


  return 0;
}
