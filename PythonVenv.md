#### 创建虚拟环境

```bash
python3 -m venv <directory_name>
```

#### 激活虚拟环境

```bash
source <directory_name>/bin/active
```

#### 检查当前使用的是哪个Python

下面这条命令会输出当前使用Python环境的目录：

```bash
which python
```

配置好之后使用`pip`安装的库就会默认放在这个环境中

#### 停用当前环境

```bash
deactivate
```
#### 重启环境

再次使用之前激活的命令即可

```bash
source
```

#### 配置pip

使用清华镜像站更新pip

```bash
python -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip
```

更换镜像源为清华镜像站

```bash
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
```

查看pip的版本

```bash
python -m pip --version
```

#### 使用pip安装库

Syntax:

```bash
python -m pip install <libraries_name>
```

安装一个requests库:

```bash
python -m pip install requests
```

#### 如何安装一个特定的版本
Syntax:

```bash
python -m install <pachage_name>==<version_number>
```

例如：安装最近一次更新的request 2.x版本：

```bash
python3 -m pip install 'requests==2.18.4'
```

安装上一个版本的request

```bash
python -m pip install --pre requests
```
#### 升级库

语法：

```bash
python -m pip install --upgrade <package_name>
```

实例：升级requests

```bash
python -m pip install --upgrade requests
```