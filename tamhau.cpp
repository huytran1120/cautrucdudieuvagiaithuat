#include <iostream>
#include <vector>
using namespace std;

//luu gia tri
vector<vector<string>> ret;

bool is_valid(vector<string> board, int row, int col){
    // kiem tra cot 
	for(int i=row;i>=0;i--){
        if(board[i][col]=='Q') return false;
    }
	//kiem tra hang cheo trai 
    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--){
        if(board[i][j]=='Q') return false;
    }

	//kiem tra hang cheo phai
    for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

void dfs(vector<string> &board, int row){

    if(row==board.size()){
        ret.push_back(board);
        return ;
    }
    for(int i=0;i<board.size();i++){
        if(is_valid(board,row,i)){
            board[row][i]='Q';
            dfs(board,row+1);
            board[row][i]='.';
        }
    }


}

void solveNQueens(int n) {
    if(n <= 0) return ;
    vector<string> board(n,string(n,'.'));
    dfs(board,0);
}
void print(){
	if(ret.size()==0)
		cout<<"Khong the sap xep"<<'\n';
	else{
		int i=1;	
		for(auto r:ret){
		    cout<<"Cach sap xep "<<i++<<'\n';
			for(auto c:r){
				for(auto a:c){
					cout<<a;
			    }
				cout<<'\n';
			}
		}
	}
}
int main(){
    int n;
	cout<<"nhap N: ";
	cin>>n;
    solveNQueens(n); 
	print();
}
