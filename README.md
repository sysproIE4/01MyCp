# mycp2

直接システムコールを使用してファイルコピープログラムを作る．

1. 演習の手順．

  - 前回と同様
  - 授業で説明した注意点は再確認

2. 作るもの(`mycp2`プログラム)

  - ３年次に作成した`mycp`と同じように動作するファイルコピープログラム
  - 但し，`open`，`read`，`write`，`close`システムコールを使用する．
  - バッファサイズより大きなファイルのコピーもできること．
  - ファイルサイズがバッファサイズの整数倍とは限らない．
  - コマンド行引数のチェックは必須．
  - `open` システムコールエラーチェックも必須．
  - システムコールのエラーメッセージは`perror()`関数で表示する．

3. 動作テストの例<br>
  ランダムなデータを含む大きさ10KiBのファイルを作り， `mycp2`プログラムを使ってコピーする．<br>
  最後にコピーしたファイルの内容が元の10KiBのファイルと同じことを確認する．

  ```
  % dd if=/dev/urandom of=srcfile bs=1024 count=10 # ランダムな内容の
  10+0 records in                                  # 10KiBのファイルを作成する
  10+0 records out 10240 bytes transferred in 0.001528 secs (6701462 bytes/sec)
  % ./mycp2 srcfile destfile                       # mycp2 プログラムを実行する
  % cmp srcfile destfile                           # コピー元とコピー先ファイルを比較する
  %                                                # 内容が同じなら何も表示されない
  ```

4. レポートの例
  `mycp2.c`ファイルの最後のコメントとして，テスト結果を書き加える．

  ```
  #include <stdio.h>                 // perror のため
  ...
  int main(int argc, char *argv[]) {
    ...
    プログラム
    ...
    return 0;
  }

  /* 実行例
  % cc -o mycp2 mycp2.c                            <-- エラーも警告も出ない
  % echo aaa > a.txt                               <-- 内容が"aaa\n"のファイル作成
  % ./mycp2                                        <-- コマンド行引数がない場合
  Usage: ./mycp2 srcfile dstfile
  % ./mycp2 a.txt                                  <-- コマンド行引数が不足の場合
  Usage: ./mycp2 srcfile dstfile
  % ./mycp2 a.txt b.txt c.txt                      <-- コマンド行引数が過剰な場合
  Usage: ./mycp2 srcfile dstfile
  % ./mycp2 z.txt a.txt                            <-- コピー元が存在しない場合
  z.txt: No such file or directory
  % ./mycp2 a.txt /a.txt                           <-- コピー先が書き込み禁止の場合
  /a.txt: Permission denied
  % ./mycp2 a.txt b.txt                            <-- b.txt にコピーしてみる
  % cat b.txt                                      <-- b.txt の内容を確認
  aaa
  % echo ccc > c.txt                               <-- 内容が"ccc\n"のファイル作成
  % ./mycp2 c.txt b.txt                            <-- b.txt に上書きしてみる
  % cat b.txt                                      <-- b.txt の内容を再確認
  ccc
  % cmp c.txt b.txt                                <-- b.txt の内容を再々確認
  % dd if=/dev/urandom of=srcfile bs=1024 count=10 <-- 10KiBの長いファイルを作る
  10+0 records in
  10+0 records out
  10240 bytes transferred in 0.001695 secs (6041591 bytes/sec)
  % rm destfile
  rm: destfile: No such file or directory          <-- destfile が存在しない場合
  % ./mycp2 srcfile destfile
  % cmp srcfile destfile                           <-- 正しくコピーできている
  % dd if=/dev/urandom of=srcfile bs=1023 count=10 <-- 10KiBより少し短いファイル
  10+0 records in
  10+0 records out
  10230 bytes transferred in 0.003218 secs (3179057 bytes/sec)
  % ./mycp2 srcfile destfile                       <-- destfile が短くなる場合
  % cmp srcfile destfile                           <-- 正しくコピーできている
  */

