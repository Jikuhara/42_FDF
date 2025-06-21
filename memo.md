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
