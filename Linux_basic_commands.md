## 终端界面介绍

当进入Linux终端时, 有如下显示:

```bash
vivit@Xen:~/Documents$ 
```

这上面的信息是: 用户名@主机名:当前目录$.

其中, `~` 表示用户的家目录, 当前用户为 `vivit`, 家目录默认就在 `/home/vivit` 下. 对于 `root` 用户, 家目录默认在 `/root` 下.

结尾的小 `$` 符号表示当前用户非 `root` 用户, 如果是root用户, 结尾应当显示 `#`, 如下所示: 

```
root@Xen:~#
```

终端的作用是: 用户在终端中输入正确的指令, 计算机依据指令执行对应的操作.


## Linux常用基础命令

### `pwd` 命令

作用: 查看当前用户的终端在哪个路径? 

实例:

```bash
vivit@Xen:~$ pwd
/home/vivit
```

可以看到当前用户 `vivit` 在 `/home/vivit` 目录下


### `cd` 命令

作用: 切换到指定路径, 如果不指定路径, 则切换到家目录

用法: cd [路径]

实例: 

进入到 `/home/vivit/temp` 再返回家目录, 在过程中我们可以使用pwd命令来验证我们是否切换成功.

```bash
vivit@Xen:temp$ pwd
/home/vivit/temp
vivit@Xen:temp$ cd /home/vivit/temp/		# 或 cd ~/temp
vivit@Xen:temp$ pwd
/home/vivit/temp
vivit@Xen:temp$ cd							# 或 cd ~
vivit@Xen:~$ pwd
/home/vivit
vivit@Xen:~$ 

```



### `ls` 命令

作用: 列指定目录下的文件和目录信息. 如果不指定目录, 则列出当前目录下的文件和目录信息. 因目录也是一种特殊的文件, 下文中统一表示为 "查看指定目录下的文件信息.".

用法: `ls [选项] [目录]`

实例:

查看 `~/cmd_demo` 下的文件信息

```bash
vivit@Xen:~$ ls ~/cmd_demo/
1.txt  2.png  3.mp3  4.mp4  a.out  test.c
```

可以看到 `~/cmd_demo` 下有以上文件, 目前看来我们只列出了文件名, 如果想列出其他更详细的信息, 需要使用到 「选项」. 下面列出 `ls` 命令的常用选项:

- `-l` 列出更详细的信息
- `-a` 列出目录下的隐藏文件
- `-h` 以人类更可读的方式显示文件大小

使用选项的格式通常是: 命令 -选项, 如 `ls -l`. 不同的选项可能对应着不同的功能.

先来展示 `-l` 选项, 它可以让我们看到目录中更详细的信息:

```bash
vivit@Xen:~$ ls -l ~/cmd_demo/
total 558112
-rw-rw-r-- 1 vivit vivit        36 Mar  4 14:43 1.txt
-rw-rw-r-- 1 vivit vivit   3145728 Mar  4 14:43 2.png
-rw-rw-r-- 1 vivit vivit  31457280 Mar  4 14:43 3.mp3
-rw-rw-r-- 1 vivit vivit 536870912 Mar  4 14:42 4.mp4
-rwxrwxr-x 1 vivit vivit     15952 Mar  4 14:43 a.out
drwxrwxr-x 2 vivit vivit      4096 Mar  4 14:53 new
-rw-rw-r-- 1 vivit vivit        73 Mar  4 14:43 test.c
```

<!--
接下来介绍部分详细信息:

- total 558112: 这是说当前目录下文件大小的和为 558112字节
- 从显示结果的第二行起, 在开头我们可以看到两个符号 `-` 和 `d`, 其中 `-` 代表文件为普通文件. 而 `d` 代表文件是目录
- 再-->


先不管这些信息表示什么意思, 继续下一个选项:

```bash
vivit@Xen:~$ ls -a ~/cmd_demo/
.  ..  1.txt  2.png  3.mp3  4.mp4  a.out  new  test.c
```

我们可以看到, 对比直接 `ls`, 加上 `-a` 选项之后在显示中多了两个文件, `.` 和 `..`, 其中:

- `.` 与当前目录等价
- `..` 与其父目录, 即上级目录等价

这两个文件就是隐藏文件, 在Linux中以`.`开头的文件属于隐藏文件, 用 `ls` 命令需要使用 `-a` 选项才能被显示

同时, 这些选项也可以组合起来使用, 比如:

```bash
vivit@Xen:~$ ls -alh ~/cmd_demo/
total 546M
drwxrwxr-x  3 vivit vivit 4.0K Mar  4 14:53 .
drwx------ 28 vivit vivit 4.0K Mar  4 15:03 ..
-rw-rw-r--  1 vivit vivit   36 Mar  4 14:43 1.txt
-rw-rw-r--  1 vivit vivit 3.0M Mar  4 14:43 2.png
-rw-rw-r--  1 vivit vivit  30M Mar  4 14:43 3.mp3
-rw-rw-r--  1 vivit vivit 512M Mar  4 14:42 4.mp4
-rwxrwxr-x  1 vivit vivit  16K Mar  4 14:43 a.out
drwxrwxr-x  2 vivit vivit 4.0K Mar  4 14:55 new
-rw-rw-r--  1 vivit vivit   73 Mar  4 14:43 test.c

```

这一次, 我们使用组合选项 `-alh` 显示了隐藏文件, 详细信息, 同时也以更易读的方式显示了文件的大小. 

再举一综合的例子:

1. 进入到 `~/cmd_demo` 目录
2. 验证路径是否切换成功
3. 查看该目录下的详细信息

```bash
vivit@Xen:~$ cd ~/cmd_demo/
vivit@Xen:cmd_demo$ pwd
/home/vivit/cmd_demo
vivit@Xen:cmd_demo$ ls -alh		
total 546M
drwxrwxr-x  3 vivit vivit 4.0K Mar  4 14:53 .
drwx------ 28 vivit vivit 4.0K Mar  4 15:03 ..
-rw-rw-r--  1 vivit vivit   36 Mar  4 14:43 1.txt
-rw-rw-r--  1 vivit vivit 3.0M Mar  4 14:43 2.png
-rw-rw-r--  1 vivit vivit  30M Mar  4 14:43 3.mp3
-rw-rw-r--  1 vivit vivit 512M Mar  4 14:42 4.mp4
-rwxrwxr-x  1 vivit vivit  16K Mar  4 14:43 a.out
drwxrwxr-x  2 vivit vivit 4.0K Mar  4 14:55 new
-rw-rw-r--  1 vivit vivit   73 Mar  4 14:43 test.c
```
在本次使用 `ls` 命令时, 我们未指定目录, 即查看当前目录下的文件, 这也是最常用的用法之一.