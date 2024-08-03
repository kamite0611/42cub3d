# 始める前に

必要なライブラリ

- pkg-config `brew install pkg-config`
- libx11 `brew install libx11`

その他必要かもしれないライブラリ

- libxext `brew install libxext`
- libxrandr `brew install libxrandr`
- libxrender `brew install libxrender`

Makefile に環境依存の書き込みがあるので編集してください

```
$ pkg-config --cflags x11
$ pkg-config --libs x11
```

表示された Include および Libraries を Makefile の該当箇所に追加してください。

# Getting Started

```
$ make
$ ./cub3D
```

# 解法

https://lodev.org/cgtutor/raycasting.html

参考
