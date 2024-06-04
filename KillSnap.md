#### 干掉烦人的snap

列出用snap安装的软件包：

```bash
snap list
```

把它们卸载了:

```bash
sudo snap remove --purge <all_packages_name>
```

干掉snap的守护进程：

```bash
sudo apt remove --auto-remove snapd
```

配置apt让其不使用snap：

使用vim打开该文件

```bash
sudo -H vim /etc/apt/preferences.d/nosnap.pref
```

再将这些配置写入进去

```bash
Package: snapd
Pin: release a=*
Pin-Priority: -10
```

更新一下源

```bash
sudo apt update
```

安装一些需要的deb包：

```bash
sudo apt install --install-suggests gnome-software
```
