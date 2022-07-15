#include<iostream>
using namespace std;
bool check(int** arr, int row, int col, int n){
    for(int i=0; i<9; i++){
        if(arr[row][i]==n){
            return false;
        }
        if(arr[i][col]==n){
            return false;
        }
    }
    int a = row - row%3;
    int b = col - col%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[a+i][b+j]==n){
                return false;
            }
        }
    }
    return true;
}
bool FillSudoku(int** arr, int row, int col){
    if(row==8 && col==9){
        return true;
    }
    if(col==9){
        row++;
        col=0;
    }
    if(arr[row][col]>0){
        return FillSudoku(arr,row,col+1);
    }
    for(int i=1; i<10; i++){
        if(check(arr,row,col,i)){
            arr[row][col]=i;
            if(FillSudoku(arr,row,col+1)){
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}
int main(){
    cout<<"************************* Welcome to the Sudoku Solver *************************"<<endl<<endl;
    int** arr= new int*[9];
    for(int i=0; i<9; i++){
        arr[i] = new int[9];
    }
    cout<<"INTSTRUCTION: "<<endl;
    cout<<"For already given numbers enter them as it as, but for the numbers to be known mark them with '0' (ZERO). After Completion of every row press enter, for better visibility."<<endl<<endl<<endl;;
    bool k=true;
    while(k){
        cout<<"ENTER THE SUDOKU THAT NEED TO BE SOLVED: "<<endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin>>arr[i][j];
            }
        }
        cout<<endl;
        if(FillSudoku(arr,0,0)){
            cout<<"\a\t Solution: "<<endl;
            for(int i=0; i<9; i++){
                cout<<"\t\t";
              for(int j=0; j<9; j++){
                    cout<<arr[i][j]<<" ";
                }
            cout<<endl;
        }
        }else{
            cout<<"\t\t\t\aSUDOKU CAN'T BE SOLVED"<<endl;
        }
        cout<<"IF YOU WANT TO USE AGAIN, PLEASE ENTER 1: ";
        int q;
        cin>>q;
        if(q!=1){
            k = false;
            break;
        }
    }
    cout<<"\t\tTHANKS! FOR USING, HOPING YOU HAVE ENJOYED THIS.........😊🥰🧡"<<endl;
    for(int i=0; i<9; i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;
}
