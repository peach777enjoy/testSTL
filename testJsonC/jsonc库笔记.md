# 下载源码并引用
github仓库：https://github.com/json-c/json-c.git

## Window下CMake生成json-c.dll库
```shell
$ git clone https://github.com/json-c/json-c.git
$ mkdir json-c-build
$ cd json-c-build
$ cmake ../json-c  
```
点击json-c.sln,选择Debug/Release,x86/x64编译即会生成json-c.dll库

## 引用json-c库
方式一：将所有的.c,.h文件拷贝到同一个文件夹下，将所有源码导入项目工程。
方式二：将生成的json-c.dll链接到项目工程，并include所有含.h路径。

# 使用
API文档：https://json-c.github.io/json-c/json-c-0.15/doc/html/index.html

