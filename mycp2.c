#include <stdio.h>                 // perror のため
#include <stdlib.h>                // exit のため
#include <fcntl.h>                 // open のため
#include <unistd.h>                // read,write,close のため
#define  BSIZ 1000                 // バッファサイズ

int main(int argc, char *argv[]) {
  int fd1;                         // コピー元用のFD
  int fd2;                         // コピー先用のFD
  ssize_t len;                     // 実際に読んだバイト数
  char buf[BSIZ];                  // バッファ

  // ここにプログラムを書き加えて完成させる．

  close(fd1);
  close(fd2);
  return 0;                        // 正常終了
}
