### 求一个行列式的值

#### 问题描述：

输入一个行列式的阶数，再按行输入这个行列式，再计算出它的值。

#### 解法：

存储一个行列式可以使用一个`n`行`n`列的数组。使用双重`for`循环按行输入行列式的值即可。

```cpp
cout << "请输入行列式的阶数：" << endl;
cin >> n;
cout << "请按行输入一个行列式：" << endl;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cin >> det[i][j];
    }
}
```

接下来以下列这个行列式为例：
$$
\left|
\begin{array}{cccc} 
1 & 1 & 4 \\ 
5 & 1 & 4\\ 
1 & 9 & 1 
\end{array}
\right| 
$$
解行列式，使用行列的性质将其化成一个上三角行列式来求解：（为了程序实现方便，这里采用自顶向下把当前列元素化成0的方法）

- 将第1行第0列(`det[1][0]`)的元素置0利用第0行第0列的元素置为0，求出这个系数`temp`，然后让`det[1][0] += temp * det[0][0]`，对当前行的其他列也要做此处理，故有：

  ```cPp
  //把第1行第0列变成0
  temp = -det[1][0] / det[0][0];	//temp == -5
  det[1][0] += det[0][0] * temp;	//det[1][0] == 1 * (-5) + 5 == 0
  det[1][1] += det[0][1] * temp;	//det[1][1] == 1 + (-5) + 1 == -4
  det[1][2] += det[0][2] * temp;	//det[1][2] == 4 * (-5) + 4 = -16
  ```

- 再求第2行

  ```cpp
  //把第2行第0列变成0
  temp = -det[2][0] / det[0][0];	//temp == -1
  det[2][0] += det[0][0] * temp;	//det[2][0] == 1 * (-1) + 1 == 0
  det[2][1] += det[0][1] * temp;	//det[2][1] == 1 *(-1) + 9 == 8
  det[2][2] += det[0][2] * temp;	//det[2][2] == 4 * (-1) + 1 == -3
  ```

- 当前列完毕，利用第1行第1列，将第1行以后（第2行），第1列的元素置为`0`

  ```cpp
  temp = -det[2][1] / det[1][1];
  det[2][0] += det[1][0] * temp;	//det[2][0] == 0
  det[2][1] += det[1][1] * temp;	//det[2][1] == 0
  det[2][2] += det[1][2] * temp;	//det[2][2] == -35
  ```

- 得到主对角线的元素，将其相乘

  ```cpp
  det[0][0] == 1;
  det[1][1] == -4;
  det[2][2] == -35;
  
  //结果
  result == 1 * (-4) * (-35);
  ```

将上述推导过程抽象化得：

- 用`det[j][j]`将`det[j+1...n][j]`置成0，得到一个上三角行列式

  ```cpp
  //以列为准遍历数组
  for (int j = 0; j < n; j++)
  {
      for (int i = j + 1; i < n; i++)
      {
          //分别未出由det[j][j]可将第[j + 1, n - 1][j]列置为0的系数temp
          temp = -det[i][j] / det[j][j];
  
          for (int k = 0; k < n; k++)
          {
              //操作当前行其他列
              det[i][k] += temp * det[j][k];
          }
      }
  }
  ```

- 但是如果首行首列为0的话，这样会出错，所以需要做一个换行的操作，使用`flag`变量记录交换的状态，奇数次置为`-1`，偶数次为`1`，最后让主对角线的积，与其相乘：

  ```cpp
  double temp;
  
  int flag = 1;
  for (int j = 0; j < n; j++)
  {
      for (int i = j + 1; i < n; i++)
      {
          //处理首行首列的0行
          if (det[0][0] == 0)
          {
              //当前行，所有列，找到第一个非0的元素就交换
              for (int i = 0; i < n; i++)
              {
                  //当前行第一个非0元素，i为其所在行
                  if (det[i][0] != 0)
                  {
                      //交换两行
                      for (int j = 0; j < n; j++)
                      {
                          int temp = det[i][j];
                          det[i][j] = det[0][j];
                          det[0][j] = temp;
                      }
                      //每次交换之后符号变负
                      flag = -flag;
                      //防止多次交换
                      break;
                  }
              }
          }
          //分母不能为0
          else
          {
              //从当前列自顶向下变0
              temp = -det[i][j] / det[j][j];
  
              for (int k = 0; k < n; k++)
              {
                  det[i][k] += temp * det[j][k];
              }
          }
      }
  }
  
  //主对角相乘再乘以一个符号
  double result = 1;
  for (int i = 0; i < n; i++)
  {
      result *= det[i][i] * flag;
  }
  ```

综上：

```bash
#include <iostream>
#define MAX 114
using namespace std;

//描述det
double det[MAX][MAX];

int n;

//按行输入det
void inputDet()
{
    cout << "请输入行列式的阶数：" << endl;
    cin >> n;
    cout << "请按行输入一个行列式：" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> det[i][j];
        }
    }
}

//打印det
void disDet()
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << det[i][j] << "\t";
        }
        cout << endl;
    }
}

//运算det
void solve()
{
    inputDet();

    double temp;

    int flag = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            //处理首行首列的0行
            if (det[0][0] == 0)
            {
                //当前行，所有列，找到第一个非0的元素就交换
                for (int i = 0; i < n; i++)
                {
                    //当前行第一个非0元素，i为其所在行
                    if (det[i][0] != 0)
                    {
                        //交换两行
                        for (int j = 0; j < n; j++)
                        {
                            int temp = det[i][j];
                            det[i][j] = det[0][j];
                            det[0][j] = temp;
                        }
                        //每次交换之后符号变负
                        flag = -flag;
                        //防止多次交换
                        break;
                    }
                }
            }
            //分母不能为0
            else
            {
                //从当前列自顶向下变0
                temp = -det[i][j] / det[j][j];

                for (int k = 0; k < n; k++)
                {
                    det[i][k] += temp * det[j][k];
                }
            }
        }
    }

    //主对角相乘再乘以一个符号
    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= det[i][i] * flag;
    }
    
    disDet();

    cout << " = " << result << endl;
}

int main(void)
{
    solve();

    return 0;
}
```



