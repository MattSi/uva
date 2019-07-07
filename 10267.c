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
X               ： 退出程序 
*/

/*
 * 1. 这道题需要非常细心。
 * 2. 先列，后行。和通常理解的不同。
 * 3. 区域填充的话，可以用图论中的DFS尝试，也可以用BFS尝试。
 * */

#define SIZE 256
char image[SIZE][SIZE]; 
char marks[SIZE][SIZE];

int M1, M2; /*M1是列，M2是行*/

void commandC(){
    /*printf("CommandC\n");*/
    int i, j;
    for(i=1; i<=SIZE; i++)
        for(j=1; j<=SIZE; j++){
            image[i][j] = 'O';
            marks[i][j] = 0;
        }
}

void commandI(char *buff){
    /*printf("CommandI\n");*/
    int i, j ;
    sscanf(buff, "%d %d", &M1, &M2);
    commandC();
}

void commandL(char *buff){
    /*printf("CommandL\n");*/
    int x, y;
    char c;
    sscanf(buff, "%d %d %c", &x, &y, &c);
    image[y][x] = c;
}


void swap(int *t1, int *t2){
    int tmp;
    tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
}

void commandV(char *buff){
    /*printf("CommandV\n");*/
    int x, y1, y2, i;
    char c;
    sscanf(buff, "%d %d %d %c", &x, &y1, &y2, &c);
    if(y1 > y2)
        swap(&y1, &y2);
    for(i=y1; i<=y2; i++){
        image[i][x] = c;
    }
}

void commandH(char *buff){
    /*printf("CommandH\n");*/
    int x1, x2, y, i;
    char c;
    sscanf(buff, "%d %d %d %c", &x1, &x2, &y, &c);
    if(x1 > x2)
        swap(&x1, &x2);
    for(i=x1; i<=x2; i++){
        image[y][i] = c;
    }
}

void commandK(char *buff){
    /*printf("CommandK\n");*/
    int x1, x2, y1, y2;
    int i, j;
    char c;
    sscanf(buff, "%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
    if(y1 > y2){
        swap(&y1, &y2);
    }
    if(x1 > x2){
        swap(&x1, &x2);
    }
    for(i=y1; i<=y2; i++){
        for(j=x1; j<=x2; j++){
            image[i][j] = c;
        }
    }
}

void commandS(char *buff){
    /*printf("CommandS\n")*/
    char name[128];
    int i, j;
    sscanf(buff, "%s", name);
    printf("%s\n", name);
    for(i=1; i<=M2; i++){
        for(j=1; j<=M1; j++){
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

void dfs(int x, int y, char origc, char targetc){
    if(x<1 || x>M1 || y<1 || y>M2) return;

    if(marks[y][x] == 1)return;
    else{
        if(image[y][x] == origc){
            image[y][x] = targetc;
            marks[y][x] = 1;
            dfs(x+1, y, origc, targetc);
            dfs(x-1, y, origc, targetc);
            dfs(x, y+1, origc, targetc);
            dfs(x, y-1, origc, targetc);
        }else{
            return;
        }
    }
}

void commandF(char *buff){
    /*printf("CommandF\n");*/
    int x,y,i,j;
    char origc, targetc;
    sscanf(buff, "%d %d %c", &x, &y, &targetc);
    for(i=1; i<=M2; i++){
        for(j=1; j<=M1; j++){
            marks[i][j]=0;
        }
    }
    origc = image[y][x];

    dfs(x, y, origc, targetc);

}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    freopen("./tests/10267.in", "r", stdin);
#endif
    
	char *buff = (char*)malloc(SIZE * sizeof(char));
	while(fgets(buff, SIZE, stdin)!=NULL){
		size_t len = strlen(buff);
		if(len > 0 && buff[len - 1] == '\n'){
			buff[--len] = '\0';
		}
		switch(buff[0]){
			case 'I': commandI(buff+1);break;
			case 'C': commandC();break;
			case 'L': commandL(buff+1);break;
			case 'V': commandV(buff+1);break;
			case 'H': commandH(buff+1);break;
			case 'K': commandK(buff+1);break;
			case 'F': commandF(buff+1);break;
			case 'S': commandS(buff+1);break;
			case 'X': return 0;
			default:
				break;
		}
	}
	return 0;
}
