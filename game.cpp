#include<iostream>
using namespace std;
string n1=" ";
string n2=" ";
char token='o';
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
bool tie=false;


void board(){
    cout<<"     |       |      \n";
    cout<<"     |       |      \n";
    cout<<" "<<space[0][0]<<"   |   "<<space[0][1]<<"   |  "<<space[0][2]<<"  \n";
    cout<<"_____|_______|______\n";
    cout<<"     |       |      \n";
    cout<<"     |       |      \n";
    cout<<" "<<space[1][0]<<"   |   "<<space[1][1]<<"   |  "<<space[1][2]<<"  \n";
    cout<<"_____|_______|______\n";
    cout<<"     |       |      \n";
    cout<<"     |       |      \n";
    cout<<" "<<space[2][0]<<"   |   "<<space[2][1]<<"   |  "<<space[2][2]<<"  \n";
    cout<<"     |       |      \n";
}


void logic(){
    int digit;
    if(token=='o'){
        cout<<n1<<" chance: ";
        cin>>digit;
    }
    if(token=='x'){
        cout<<n2<<" chance: ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid!!\n";
    }
    if(token=='o' && space[row][column]!='o' && space[row][column]!='x'){
        space[row][column]='o';
        token='x';
    }
    else if(token=='x' && space[row][column]!='o' && space[row][column]!='x'){
        space[row][column]='x';
        token='o';
    }
    else{
        cout<<"There is no empty space!\n";
        logic();
    }
}


bool whoWin(){
    for(int i=0;i<3;i++){
        
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='o' && space[i][j]!='x'){
                return false;
            }
        }
    }
    tie=true;
    return true;
}


int main(){

   cout<<"***Welcome To the Tic Tak Toe Game***\n";
   cout<<"Enter Player1 Name: ";
   cin>>n1;
   cout<<"Enter Player2 Name: ";
   cin>>n2;
   while(!whoWin()){
    board();
    logic();
    whoWin();
   }
   if(token=='o' && tie==false){
    cout<<n2<<" Wins";
   }
   else if(token=='x' && tie==false){
    cout<<n1<<" Wins";
   }
   else if(tie==true){
    cout<<"It's a draw.!\n";
   }

}

