# FDFとの記録。
まずは、subjectを読んでみる。

噂に聞いていたように、グラフィックをなんちゃらかんちゃら、するやつっぽい。
とりあえず、minilibxを使えるようになりたい。

## minilibxの使い方を調べる。
### minilibxのInstall方法
```
Install MinilibX

 - no installation script is provided. You may want to install
     - libmlx.a and/or libmlx_$(HOSTTYPE).a in /usr/X11/lib or /usr/local/lib
     - mlx.h in /usr/X11/include or /usr/local/include
     - man/man3/mlx*.1 in /usr/X11/man/man3 or /usr/local/man/man3
```
これがインストール方法っぽい。
libmlx.a or libmlx_$(HOSTTYPE).aを/usr/X11/lib or /usr/local/libに入れたらいいっぽい。
/usr/X11/ と /usr/local/ がわからないので、次はそれを調べてみるか。

### /usr/X11/ と /usr/local/ って何？
/usr/X11/ と /usr/local/ は、Unix系のシステムでよく使われるディレクトリのパス。
- `/usr/X11/` は、X Window Systemの関連ファイルが格納されるディレクトリ。
X Window Systemは、Unix系システムでGUIを提供するためのシステム。
今は廃止されているっぽい。

- `/usr/local/` は、システム全体で使用されるローカルのアプリケーションやライブラリが格納されるディレクトリ。
OSのupdateの影響を受けない。
とりあえず、ここに入れておけば大丈夫っぽい？

/usr/local/libにコピーしたいが、Permissonエラーが出る。なんで？
#### Permissionエラーが出る理由
/usr/local/は、root権限が必要なディレクトリだから。
どうしたら良いものか。

### とりあえず、minilibxを使えるようにする。
```
kjikuhar@c2r9s2 ~/42_FDF/test % cc sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
/usr/bin/ld: libmlx.a(mlx_init.o): in function `mlx_int_deal_shm':
mlx_init.c:(.text+0x30): undefined reference to `XShmQueryVersion'
/usr/bin/ld: mlx_init.c:(.text+0xe4): undefined reference to `XShmPixmapFormat'
/usr/bin/ld: libmlx.a(mlx_init.o): in function `mlx_init':
mlx_init.c:(.text+0x1f4): undefined reference to `XOpenDisplay'
/usr/bin/ld: mlx_init.c:(.text+0x288): undefined reference to `XInternAtom'
/usr/bin/ld: mlx_init.c:(.text+0x29f): undefined reference to `XInternAtom'
/usr/bin/ld: mlx_init.c:(.text+0x2f1): undefined reference to `XCreateColormap'
/usr/bin/ld: libmlx.a(mlx_int_get_visual.o): in function `mlx_int_get_visual':
mlx_int_get_visual.c:(.text+0x67): undefined reference to `XGetVisualInfo'
```
うーん、なんか上手く参照されていない。
Headerをもう少し見てみる。

```c
/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/
```
どうやら、`-lXext -lX11`を付ける必要があるっぽい。

```
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext -lx11 sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
/usr/bin/ld: cannot find -lx11: No such file or directory
clang: error: linker command failed with exit code 1 (use -v to see invocation)
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
/usr/bin/ld: libmlx.a(mlx_init.o): undefined reference to symbol 'XInternAtom'
/usr/bin/ld: /lib/x86_64-linux-gnu/libX11.so.6: error adding symbols: DSO missing from command line
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

よ〜わからんて！！！
chatGPTに聞いてみる。

大文字小文字間違えてただけっぽい。アホすぎ。
```
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext -lx11 -lmlx sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
/usr/bin/ld: cannot find -lx11: No such file or directory
/usr/bin/ld: cannot find -lmlx: No such file or directory
clang: error: linker command failed with exit code 1 (use -v to see invocation)
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext -lX11 -lmlx sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
/usr/bin/ld: cannot find -lmlx: No such file or directory
clang: error: linker command failed with exit code 1 (use -v to see invocation)
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext -lX11 sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
kjikuhar@c2r9s2 ~/42_FDF/test % ./a.out
0x1ef3a2a0
```
```c
#include <stdio.h>
#include "../minilibx-linux/mlx.h"

int main(int argc, char const *argv[])
{
	printf("%p\n", mlx_init());
	return (0);
}
```

できた！！！


### 実際にminilibxを使ってみる。
```c
/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
```
これ使ってみる。
第一引数は、mlx_init()で得られたポインタを渡すっぽい。
size_x, size_yは、ウィンドウのサイズかな。
titleは知らんが適当に文字列を渡しときゃええやろ。const char * ちゃうんや。きになるなぁ。
```c
#include <stdio.h>
#include "../minilibx-linux/mlx.h"

int main(int argc, char const *argv[])
{
	void *mlx_ptr = mlx_init();
	printf("%p\n", mlx_ptr);
	void *mlx_success = mlx_new_window(mlx_ptr, 100, 100, "test_title");
	printf("%p\n", mlx_success);
	return (0);
}
```

```c
kjikuhar@c2r9s2 ~/42_FDF/test % cc -lXext -lX11 sandbox_for_minilibx.c libmlx.a -I ../minilibx-linux/mlx.h
kjikuhar@c2r9s2 ~/42_FDF/test % ./a.out
0x360d42a0
0x360e9b30
```

良さげですねぇ。
