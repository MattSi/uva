#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
正如文本编辑器允许我们修改文本一样， 图形化的编辑器允许我们修改位图图像。
本题中，图像被表示成一个M * N的像素数组，每个像素有一种颜色。
编写程序，模拟简单的交互式图形化编辑器。

输入：
输入包括一个指令序列，每条指令占单独的一行，每行的第一个字母总是大写。代表指令的类型。如果该指令需要参数，将会在同一行陆续给出，用空格隔开。
像素坐标用序号和行号这两个整数来表示。列号在1到M的范围内，行号在1到N的范围内。（1 <= M,N <=250）坐标原点在左上角，颜色用大写字母表示。

指令集：
I M N           ： 创建一个新的M * N的图像，所有像素为白色(0)
C               ： 清除图像，把所有像素涂成白色(0)
L X Y C         ： 把像色(X,Y)，涂成颜色(C)
V X Y1 Y2 C     ： 画一条竖直线段，颜色为(C)，列号为X，从第Y1行到Y2行，（包括Y1和Y2）
H Y X1 X2 C	    ： 画一条水平线段，颜色为(C)，行号为Y，从第X1列到X2列，（包括X1和X2）
K X1 Y1 X2 Y2 C ： 画一个实心矩形，颜色为(C), 左上角为(X1, Y1),右下角为(X2, Y2)
F X Y C         ： 把区域R填充为颜色(C)，R定义如下，若像素(X,Y)属于R，则所有与(X,Y)有公共边且颜色相同的像素也属于R
S NAME          ： 原样输出文件名以及整幅图像的像素矩阵
X               ： 推出程序 
*/

#define N 256
char image[N][N]; 


void init(int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			image[i][j] = 'O';
		}
	}
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    FILE* fp = freopen("./tests/10267.in", "r", stdin);
#endif
	char buff[N];
	int M, N;
	while(fgets(buff, sizeof(buff), stdin)!=NULL){
		size_t len = strlen(buff);
		if(len > 0 && buff[len - 1] == '\n'){
			buff[--len] = '\0';
		}
		switch(buff[0]){
			case 'I':

				break;
			case 'C':
				break;
			case 'L':
				break;
			case 'V':
				break;
			case 'H':
				break;
			case 'K':
				break;
			case 'F':
				break;
			case 'S':
				break;
			case 'X':
				break;
			default:
				break;
		}
		printf("%s\n", buff);
	}
			
	return 0;
}
