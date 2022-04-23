源代码保存在src文件夹中
源代码加量版在html文件夹中
程序实现在mingw5文件夹中
命令行版本：
 打开cmd，调至程序目录下
 HighLight.exe [devcpp|cfree] (InputFile) (OutputFile) (Name)
 如 HighLight.exe devcpp "E:\U disk\2048\main.cpp" "E:\U disk\2048\main.h" main.cpp
 或 HighLight.exe cfree E:\Udisk\2048\main.cpp E:\U disk\2048\main.h main.cpp
 建议直接把文件拖进cmd窗口，否则文件引号不好处理（有空格或特殊字符左右加双引号）
 devcpp:文件按Dev C++语法加亮格式加亮成HTML文件
 cfree:文件按C Free5.0语法加亮格式加亮成HTML文件（由于需要完整头文件关联，部分功能无法 实现（常量宏、数据类型加亮等））
 然后提示输入作者名字，输入英文后回车
程序版本
 双击进入程序
按↑↓←→键切换 Dev C++与C Free5.0加亮格式