#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <string>

const int CACHE_LINE_SIZE = 64;

int main(int argc, char *argv[])
{
  int size_mb = strtol(argv[1], NULL, 0);
  int size_bytes = size_mb * 1024 * 1024;
  int cache_lines = size_bytes / CACHE_LINE_SIZE;

  assert(size_mb < 2048);
  
  for (int i = 0; i < cache_lines; i++) {
    printf("0x%08x READ %d\n", i*CACHE_LINE_SIZE, i);
  }
}
