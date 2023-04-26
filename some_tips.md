# 问题记录

## 1. `sort()`方法的使用

用`sort()`方法排序，需要包含`algorithm`头文件



## 2. `rand()`方法的使用

```C++
int score = rand() % 40;  // rand() % 40即0~39
```



## 3. ubuntu强转十六进制为十进制

### 报错代码

```c++
int a = 10;
int b = 10;

cout << "局部变量a的地址: " << (int)&a << endl;
cout << "局部变量b的地址: " << (int)&b << endl;
```

### 问题解决

报错问题如下: 

```bash
error: cast from ‘int*’ to ‘int’ loses precision [-fpermissive]
```

这里是因为基于Linux内核的64位系统上指针类型占用8个字节，而int类型占用4个字节，所以会出现`loses precision`

**解决方法**

```c++
cout << "局部变量a的地址: " << (long)&a << endl;
cout << "局部变量b的地址: " << (long)&b << endl;
```

