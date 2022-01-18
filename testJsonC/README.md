# 依赖
json-c：https://github.com/json-c/json-c


# jsonc构建并使用

```shell
mkdir build
cd build
cmake ..
```
或者
```shell
cmake .
```
方法一：通过cmake编译生成json-c.sln，打开该解决方案生成对应的静态库与动态库。将.h文件复制出来。  
方法二：不直接生成动态库与静态库，将.h与.cpp文件复制出来。