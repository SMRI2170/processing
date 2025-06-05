
---

# C言語 開発環境構築と基礎知識（WSL環境向け）

##  環境構築（WSL + GCC）

### 1. WSLの準備（Ubuntu推奨）

WindowsでLinux環境を利用できるWSL（Windows Subsystem for Linux）を有効化し、Ubuntuをインストールします。

```bash
wsl --install
```

完了後、Microsoftストアから「Ubuntu」をインストールしてください。

### 2. WSL上でGCCコンパイラをインストール

Ubuntuターミナルで以下を実行し、ビルドに必要なツールを導入します。

```bash
sudo apt update
sudo apt install build-essential
```

正しくインストールできたか確認するには：

```bash
gcc --version
```

---

##  C言語プログラムの作成と実行例

### 1. ソースファイル作成（例：hello.c）

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### 2. コンパイル

```bash
gcc hello.c -o hello
```

### 3. 実行

```bash
./hello
```

---

##  C言語の基礎知識

### 🔹 変数とデータ型

* 変数は値を格納する名前付きの箱。
* データ型を必ず指定します。

```c
int a = 10;        // 整数
float b = 3.14f;   // 小数点
char c = 'A';      // 文字
```

### 🔹 配列（Arrays）

同じ型のデータを連続的に格納する構造。

```c
int nums[5] = {1, 2, 3, 4, 5};
printf("%d\n", nums[0]);  // 1 を出力
```

### 🔹 構造体と連結リスト

複数の異なるデータをまとめて管理するための型。リスト構造も構造体で作れます。

```c
// 構造体例
struct Point {
    int x;
    int y;
};

// 単方向連結リストの例
struct Node {
    int data;
    struct Node* next;
};
```

---

##  C言語学習のポイント

* **変数とデータ型**（int, float, char）
* **制御文**（if, for, while, switch）
* **関数の定義と呼び出し**
* **ポインタとアドレス演算子（&、\*）**
* **構造体とユーザー定義型**
* **ファイル操作（fopen, fread, fwriteなど）**
* **動的メモリ管理（malloc, free）**
* **Makefileを使ったビルド管理**

---

## ⚙️ Makefileで効率的にビルド管理

複数ファイルの管理に便利です。以下は基本例です。

```makefile
CC = gcc
CFLAGS = -Wall

all: main

main: main.o utils.o
	$(CC) $(CFLAGS) -o main main.o utils.o

main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o main
```

### ファイル構成例

```
project/
├── main.c
├── utils.c
├── utils.h
└── Makefile
```

### ビルドと実行

```bash
make
./main
```

---

##  デバッグとメモリ管理ツール

* **gdb（デバッガ）**

  ```bash
  sudo apt install gdb
  gdb ./main
  ```

* **デバッグ情報付きコンパイル**

  ```bash
  gcc -g main.c -o main
  ```

* **メモリリーク検出にvalgrind**

  ```bash
  sudo apt install valgrind
  valgrind ./main
  ```

---

##  参考リンク

* [C言語リファレンス (cppreference)](https://en.cppreference.com/w/c)
* [WSL 公式ドキュメント](https://learn.microsoft.com/windows/wsl/)
* [GCC 公式サイト](https://gcc.gnu.org/)
* [GNU Make マニュアル](https://www.gnu.org/software/make/manual/make.html)

---

##  推奨エディタ

* **Visual Studio Code + WSL拡張機能**（初心者におすすめ）
* **Vim**（WSL内で軽量に使えます）
* **Emacs**（C言語開発に強力）

---
