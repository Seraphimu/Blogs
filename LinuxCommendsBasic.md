### 常用的Linux命令

#### `pwd`命令

作用：查看当前在哪个目录：

```bash
pwd
```

输出：

```bash
tom@VM-4-4-ubuntu:~$ pwd
/home/tom
tom@VM-4-4-ubuntu:~$
```

#### `ls`命令

作用：列出当前目录下的内容：

```bash
ls         # 列出文件夹下的内容
ls -a      # 列出文件夹下的内容，包括隐藏的文件
ls -l      # 列出文件夹下的内容，以列表的形式
ls -al     # 以列表形式，列出当前文件夹下的所有内容（包括隐藏文件）
```

测试`ls`命令：

```bash
tom@VM-4-4-ubuntu:~$ ls
Desktop    Download  Hello.Java  NewDir  test.c
Documents  hello.c   Music       Temp    Videos
tom@VM-4-4-ubuntu:~$
```

加上参数`-a`：

```bash
tom@VM-4-4-ubuntu:~$ ls -a
.              Documents   .sudo_as_admin_successful
..             Download    Temp
.bash_history  hello.c     test.c
.bash_logout   Hello.Java  Videos
.bashrc        Music       .viminfo
.cache         NewDir
Desktop        .profile
tom@VM-4-4-ubuntu:~$
```

加上参数`-l`

```bash
tom@VM-4-4-ubuntu:~$ ls -l
total 32
drwxrwxr-x 2 tom tom 4096 Jun  4 18:41 Desktop
drwxrwxr-x 3 tom tom 4096 Jun  4 19:39 Documents
drwxrwxr-x 2 tom tom 4096 Jun  4 20:44 Download
-rw-rw-r-- 1 tom tom    0 Jun  4 18:41 hello.c
-rw-rw-r-- 1 tom tom  102 Jun  4 19:24 Hello.Java
drwxrwxr-x 2 tom tom 4096 Jun  4 18:41 Music
drwxrwxr-x 2 tom tom 4096 Jun  4 18:58 NewDir
drwxrwxr-x 3 tom tom 4096 Jun  4 19:38 Temp
-rw-rw-r-- 1 tom tom    0 Jun  4 18:41 test.c
drwxrwxr-x 2 tom tom 4096 Jun  4 18:41 Videos
tom@VM-4-4-ubuntu:~$
```

加上参数`-al`

```bash
tom@VM-4-4-ubuntu:~$ ls -al
total 64
drwxr-x--- 10 tom  tom  4096 Jun  4 19:39 .
drwxr-xr-x  6 root root 4096 Jun  4 18:33 ..
-rw-------  1 tom  tom  3019 Jun  4 21:57 .bash_history
-rw-r--r--  1 tom  tom   220 Jan  7  2022 .bash_logout
-rw-r--r--  1 tom  tom  3771 Jan  7  2022 .bashrc
drwx------  2 tom  tom  4096 Jun  4 18:38 .cache
drwxrwxr-x  2 tom  tom  4096 Jun  4 18:41 Desktop
drwxrwxr-x  3 tom  tom  4096 Jun  4 19:39 Documents
drwxrwxr-x  2 tom  tom  4096 Jun  4 20:44 Download
-rw-rw-r--  1 tom  tom     0 Jun  4 18:41 hello.c
-rw-rw-r--  1 tom  tom   102 Jun  4 19:24 Hello.Java
drwxrwxr-x  2 tom  tom  4096 Jun  4 18:41 Music
drwxrwxr-x  2 tom  tom  4096 Jun  4 18:58 NewDir
-rw-r--r--  1 tom  tom   807 Jan  7  2022 .profile
-rw-r--r--  1 tom  tom     0 Jun  4 18:33 .sudo_as_admin_successful
drwxrwxr-x  3 tom  tom  4096 Jun  4 19:38 Temp
-rw-rw-r--  1 tom  tom     0 Jun  4 18:41 test.c
drwxrwxr-x  2 tom  tom  4096 Jun  4 18:41 Videos
-rw-------  1 tom  tom  1234 Jun  4 19:22 .viminfo
tom@VM-4-4-ubuntu:~$
```

#### 切换当前目录：`cd`命令

`cd`命令可以切换当前所在的目录，以在对应的目录中展开作业：

基本语法：

```bash
cd <目标目录>
```

例如，切换到`/opt`目录下

```bash
cd /opt
```

再使用`pwd`命令查看当前所在的目录，输出为`/opt`

```bash
tom@VM-4-4-ubuntu:~$ pwd
/home/tom
tom@VM-4-4-ubuntu:~$ cd /opt
tom@VM-4-4-ubuntu:/opt$ pwd
/opt
tom@VM-4-4-ubuntu:/opt$
```

`cd`的特殊用法：

直接在命令行中键入`cd`会直接切换到家目录

```bash
cd
```

效果如下：

```bash
tom@VM-4-4-ubuntu:/opt$ pwd
/opt
tom@VM-4-4-ubuntu:/opt$ cd
tom@VM-4-4-ubuntu:~$ pwd
/home/tom
tom@VM-4-4-ubuntu:~$
```

#### 创建文件夹：`mkdir`命令

语法：

```bash
mkdir <目录名>           # 在当前目录下创建目录
mkdir <路径/目录名>      # 在指定路径下路下创建目录
```

例如，在当前目录(`/home/tom/Videos`)下创建一个目录`NewDir`：

```bash
mkdir NewDir
```

结果为：

```bash
tom@VM-4-4-ubuntu:~/Videos$ pwd
/home/tom/Videos
tom@VM-4-4-ubuntu:~/Videos$ ls
tom@VM-4-4-ubuntu:~/Videos$ mkdir NewDir
tom@VM-4-4-ubuntu:~/Videos$ ls
NewDir
tom@VM-4-4-ubuntu:~/Videos$
```

给指定的目录`/home/tom/Temp`下创建一个新目录`Test`

```bash
mkdir /home/tom/Temp/Test
```

结果为：

```bash
tom@VM-4-4-ubuntu:~$ ls /home/tom/Temp/

tom@VM-4-4-ubuntu:~$ mkdir /home/tom/Temp/Test
tom@VM-4-4-ubuntu:~$ ls /home/tom/Temp/
Test
tom@VM-4-4-ubuntu:~$
```

在一个不存在的目录(`/home/Projects`)下创建目录`Java`

```bash
mkdir -p /home/tom/Projects/Java
```

效果如下，该目录成功创建：

```bash
tom@VM-4-4-ubuntu:~$ ls
Desktop  Documents  Download  hello.c  Hello.Java  Music  Temp  test.c  Videos
tom@VM-4-4-ubuntu:~$ mkdir -p /home/tom/Projects/Java
tom@VM-4-4-ubuntu:~$ ls
Desktop  Documents  Download  hello.c  Hello.Java  Music  Projects  Temp  test.c  Videos
tom@VM-4-4-ubuntu:~$
```

如果直接使用`mkdir`不加上参数`-p`的话：

```bash
# `No such file or directory
mkdir /home/tom/Projects/Java
```

会被告知`No such file or directory`：

```bash
tom@VM-4-4-ubuntu:~$ ls
Desktop    Download  Hello.Java  Temp    Videos
Documents  hello.c   Music       test.c
tom@VM-4-4-ubuntu:~$ mkdir /home/tom/Projects/Java
mkdir: cannot create directory ‘/home/tom/Projects/Java’: No such file or directory
tom@VM-4-4-ubuntu:~$
```

#### 引入相对路径的概念

绝对路径例如：

```bash
/home/tom/Temp/
```

相对路径：

```bash
./		# 在当前目录下
../		# 在当前目录的上一级
```

例如终端当前目录位于为`/home/tom`，则访问目录`/home/tom/Temp` 只需使用 `./Temp`即可，如：

```bash
ls ./Temp
```

输出：

```bash
tom@VM-4-4-ubuntu:~$ ls ./Temp
Test
tom@VM-4-4-ubuntu:~$
```

或者，进入该目录：

```bash
cd ./Temp
```

查看当前目录及内容：

```bash
tom@VM-4-4-ubuntu:~$ ls ./Temp
Test
tom@VM-4-4-ubuntu:~$ cd ./Temp/
tom@VM-4-4-ubuntu:~/Temp$ ls
Test
tom@VM-4-4-ubuntu:~/Temp$ pwd
/home/tom/Temp
tom@VM-4-4-ubuntu:~/Temp$
```

在`/home/tom/Temp`目录下我们返回父级目录，即`/home/tom/`目录下只需用`../`即可

```bash
cd ../
```

效果：

```bash
tom@VM-4-4-ubuntu:~/Temp$ pwd
/home/tom/Temp
tom@VM-4-4-ubuntu:~/Temp$ cd ../
tom@VM-4-4-ubuntu:~$ pwd
/home/tom
tom@VM-4-4-ubuntu:~$
```

#### 创建文件：`touch`命令

语法：

```bash
touch <指定的文件>
```

例如创建一个文件，名为`Test.java`：

```bash
touch Hello.Java
```

效果如下：

```bash
tom@VM-4-4-ubuntu:~/Projects/Java$ ls
tom@VM-4-4-ubuntu:~/Projects/Java$ pwd
/home/tom/Projects/Java
tom@VM-4-4-ubuntu:~/Projects/Java$ touch Test.java
tom@VM-4-4-ubuntu:~/Projects/Java$ ls
Test.java
tom@VM-4-4-ubuntu:~/Projects/Java$
```

#### 复制（`cp`）命令：

cp命令的语法：

```bash
cp <要复制的文件> <要复制到的目标目录>
```

例如把`Test.java`复制到父目录(`/home/tom/Projects`)：

```bash
cp Test.java ../	#把Test.java文件复制到父目录
```

结果展示：

```bash
tom@VM-4-4-ubuntu:~/Projects/Java$ ls
Test.java
tom@VM-4-4-ubuntu:~/Projects/Java$ cp Test.java  ../
tom@VM-4-4-ubuntu:~/Projects/Java$ ls ../
Java  Test.java
tom@VM-4-4-ubuntu:~/Projects/Java$ cd ../
tom@VM-4-4-ubuntu:~/Projects$ ls
Java  Test.java
tom@VM-4-4-ubuntu:~/Projects$
```

如果在复制目录的话，需要用到`-r`参数递归复制：

```bash
cp -r ./Projects ./Temp
```

效果如下，此时可以看见Temp目录下

```bash
tom@VM-4-4-ubuntu:~$ ls ./Temp/
Test
tom@VM-4-4-ubuntu:~$ cp -r ./Projects ./Temp
tom@VM-4-4-ubuntu:~$ ls ./Temp/
Projects  Test
tom@VM-4-4-ubuntu:~$

```

不加 `-r`参数复制目录的操作会失败：

```bash
cp ./Projects ./Temp
```

结果：

```bash
tom@VM-4-4-ubuntu:~$ ls ./Temp/
Test
tom@VM-4-4-ubuntu:~$ cp ./Projects ./Temp
cp: -r not specified; omitting directory './Projects'
tom@VM-4-4-ubuntu:~$
```



#### 文件和文件夹的移动命令：`mv`

语法和`cp`命令很相似：

```bash
mv <文件/目录>	<目标目录>
```

例如把`~/Projects`下的`Test.java`移动到`/home/tom`目录中（当前用户的家目录可以用`~`代替，与`/home/当前用户`的效果相同）：

```bash
cd /home/tom/Projects
mv Test.java /home/tom
```

或者：

```bash
cd ~/Projects
mv Test.java ~
```

执行完这条命令后，发现`Test.java`文件已经不在`Project`目录中了，而是在家目录中：

```bash
tom@VM-4-4-ubuntu:~$ cd ~/Projects/
tom@VM-4-4-ubuntu:~/Projects$ ls	# 查看~/Projects目录下的文件
Java  Test.java
tom@VM-4-4-ubuntu:~/Projects$ mv Test.java ~

tom@VM-4-4-ubuntu:~/Projects$ ls	# 再次查看~/Projects目录下的文件
Java
tom@VM-4-4-ubuntu:~/Projects$ cd
tom@VM-4-4-ubuntu:~$ ls
Desktop  Documents  Download  hello.c  Hello.Java  Music  Projects  Temp  test.c  Test.java  Videos
tom@VM-4-4-ubuntu:~$
```

`mv`移动目录与文件同理：

例如将`tom`的家目录下的`Projects`目录移动到`Documents`目录中：

```bash
mv ./Projects ./Documents
```

通过`ls`命令来查看家目录下已经没有`Projects`这个目录了，在`Documents`目录下发现了它

```bash
tom@VM-4-4-ubuntu:~$ ls
Desktop  Documents  Download  hello.c  Hello.Java  Music  Projects  Temp  test.c  Test.java  Videos
tom@VM-4-4-ubuntu:~$ ls Documents/			# 移动前Documents是个空目录
tom@VM-4-4-ubuntu:~$ mv Projects/ Documents/
tom@VM-4-4-ubuntu:~$ ls
Desktop  Documents  Download  hello.c  Hello.Java  Music  Temp  test.c  Test.java  Videos
tom@VM-4-4-ubuntu:~$ ls Documents/			# 把家目录下的Project目录移动到了Documents中
Projects
tom@VM-4-4-ubuntu:~$
```

