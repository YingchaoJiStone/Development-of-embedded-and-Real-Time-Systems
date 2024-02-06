// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: xxxxxx (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

#define binary [9]

int main(int argc, char *argv[]) {

  if (argc == 6) {
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int arg3 = atoi(argv[3]);
    int arg4 = atoi(argv[4]);
    int arg5 = atoi(argv[5]);

    if ((arg1 < 0 || arg1 > 1) || (arg2 < 0 || arg2 > 4) ||
        (arg3 < 0 || arg3 > 2) || (arg4 < 0 || arg4 > 1) ||
        (arg5 < 0 || arg5 > 1)) {
      printf("Invalid argument range.");
      printf("Usage: ./code <0..1>  <0..4> <0..2> <0..1> <0..1>. \n");
      exit(1);
    } else {

      int binNum = 0;

      binNum = (binNum << 1) | arg1;

      for (int i = 2; i >= 0; i--) {
        int bit = (arg2 >> i) & 1;
        binNum = (binNum << 1) | bit;
      }

      for (int i = 1; i >= 0; i--) {
        int bit = (arg3 >> i) & 1;
        binNum = (binNum << 1) | bit;
      }

      binNum = (binNum << 1) | arg4;
      binNum = (binNum << 1) | arg5;

      printf("%X", binNum);
    }

  } else {
    printf("Arguments number error. \n");
    printf("Usage: ./code <number>  <number> <number> <number> <number>. \n");
    return 1;
  }

  return 0;
}
