/*
 __ 
/  \
\__/
*/


#include <bits/stdc++.h>
using namespace std;
char matrix[1007][1007];
int n;
typedef struct point{
    int x, y;
}point;
void generate(int x, int y){
    matrix[x + 1][y] = matrix[x + 2][y] =
    matrix[x + 1][y - 2] = matrix[x + 2][y - 2] =  '_';
    matrix[x][y - 1] = matrix[x + 3][y - 2] = '/';
    matrix[x][y - 2] = matrix[x + 3][y - 1] = '\\';


}
void dfs(point p, int depth){

}

void printMatrix(){
    
}
int main(){
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            matrix[i][j] = ' ';
        }
    }
    cin >> n;

}