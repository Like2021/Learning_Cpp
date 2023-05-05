# 记录

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



## 4. 数组作为函数参数

一维数组名也是一个地址，即指针，只不过数组名是一个常量指针，常量指针即不能修改该指针的值。

所以如下代码是错误的：

```c++
int arr[5];
arr++;
arr--;
```



### 数组作为函数参数的格式

参考链接: https://zhuanlan.zhihu.com/p/438555365

```c++
void f1(int arr[]) {}

void f2(int arr[8]) {}

void f3(int(arr)[]) {}

void f4(int(arr)[9]) {}

void f5(int* arr) {}
```

以上的定义是完全等价的, 特别是`void f2(int arr[8]) {}`这种写法，非常具有迷惑性，也是初学者容易犯错的地方。它会让人觉得，参数是个长度为8的int数组，然后在函数内部，完全把参数`arr`当做数组来访问。

比如：

```c++
void printArray(int arr[8]) {
    int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0 ; i < length; ++i){
        std::cout << arr[i] << std::endl;
    }
}
```

而实际上，`sizeof(arr)`的值是`sizeof(int*)`，这样写出来的代码肯定有问题。

这种定义方法，在函数内部无法得到数组的真实长度，一般推荐的方法是增加一个参数表示长度。

比如：

```c++
void printArray(int arr[], int length) {
    for (int i = 0 ; i < length; ++i){
        std::cout << arr[i] << std::endl;
    }
}
```

记住`f1, f2, f3, f4`的定义完全等价于`f5`，使用上基本就不会犯错了。

准确地说，这种定义方法并不是把数组作为参数，只是定义了个指针类型的参数，写的形式像数组罢了。把数组传给如此定义的函数，数组就退化成一个指针，同时丢失了长度信息。
