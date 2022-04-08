

#include <iostream>
#include <iomanip>
using namespace std;
const int N=6;//board contant//

//Checking User input STUFF//
bool checkinput(char board[N][N],string input){
    int a=0,b=0;
    
    for(int i=1;i<=8;i++){
        if('0'<=input[i] &&input[i]<='9'){
            a=input.at(i)-48+a*10;
        }
    }
    
    b=input.at(0);
    if(b<=90){
        b=b-65;
    }else if (97<=b){
        b=b-97;
    }
    
    a--;
    if(a<=N-1&&b<=N-1&&board[a][b]!='#'&&board[a][b]!='X'&&board[a][b]!='O'){
        return true;
    }else{
        return false;}
}


//Printing board//
void printboard(char board[N][N]){
    cout <<"   ";
    for(int a=0;a<N;a++){
        char words='A';
        words='A'+a;
        cout <<words<<" ";
    }
    int tmp=1;
    for(int a=0;a<N;a++){
        cout<<endl<<setw(2)<<tmp <<" ";
        tmp++;
        for(int b=0;b<N;b++){
            cout << board[a][b]<<" ";
        }
    }
    cout<<endl;
}


//Switching//

int switchboard(char board[N][N],string input, char symbol){
    int x=0,y;
    
    char secondboard[N][N];
    
    for(int i=0;i<N;i++){
        for(int tmp=0;tmp<N;tmp++){
            secondboard[i][tmp]=board[i][tmp];
        }
    }
    
    
    for(int i=1;i<=N;i++){
        if('0'<=input[i] &&input[i]<='9'){
            x=input.at(i)-48+x*10;
        }
    }
    x--;
    y=input.at(0);
    if(y<=90){
        y=y-65;
    }else if (97<=y){
        y=y-97;
    }
    board[x][y]=symbol;
    
    if(symbol=='#'){
        return 1;
    }
    
    //Taking over pieces_Left and right direction//
    
    if(symbol=='X'||symbol=='O'){
        int a=N;
        
        for(int i=N;i>y;i--){
            if(board[x][i]=='#'||board[x][i]==symbol||board[x][i]=='.'){
                a=i;
            }
        }
        for(int i=a;i>y;i--){
            if(board[x][i]==board[x][y]&&board[x][i-1]!='#'){
                board[x][i-1]=board[x][y];
            }
        }
        
        a=0;
        for(int i=0;i<y;i++){
            if(board[x][i]=='#'||board[x][i]==symbol||board[x][i]=='.'){
                a=i;
            }
        }
        
        
        for(int i=a;i<y;i++){
            if(board[x][i]==board[x][y]&&board[x][i+1]!='#'){
                board[x][i+1]=board[x][y];
            }
        }
        
        //Taking over pieces_Up down//
        a=N;
        for(int i=N;i>x;i--){
            if(board[i][y]=='#'||board[i][y]==symbol||board[i][y]=='.'){
                a=i;
            }
        }
        
        for(int i=a;i>x;i--){
            if(board[i][y]==board[x][y]&&board[i-1][y]!='#'){
                board[i-1][y]=board[x][y];
            }
        }
        
        a=0;
        for(int i=0;i<x;i++){
            if(board[i][y]=='#'||board[i][y]==symbol||board[i][y]=='.'){
                a=i;
            }
        }
        for(int i=a;i<x;i++){
            if(board[i][y]==board[x][y]&&board[i+1][y]!='#'){
                board[i+1][y]=board[x][y];
            }
        }
        //Taking over piece_Sideways//
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x+i][y+i]=='#'||board[x+i][y+i]==symbol||board[x+i][y+i]=='.'){
                a=i;
            }
        }
        
        for(int i=a;i!=1;i--){
            if(board[x+i][y+i]==board[x][y]&&board[x+i-1][y+i-1]!='#'&&x+i<N&&y+i<N){
                board[x+i-1][y+i-1]=board[x][y];
            }
        }
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x-i][y-i]=='#'||board[x-i][y-i]==symbol||board[x-i][y-i]=='.'){
                a=i;
            }
        }
        
        for(int i=a;i!=1;i--){
            if(board[x-i][y-i]==board[x][y]&&board[x-i+1][y-i+1]!='#'&&x-i>=0&&y-i>=0){
                board[x-i+1][y-i+1]=board[x][y];
            }
        }
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x-i][y+i]=='#'||board[x-i][y+i]==symbol||board[x-i][y+i]=='.'){
                a=i;
            }
        }
        for(int i=a;i!=1;i--){
            if(board[x-i][y+i]==board[x][y]&&board[x-i+1][y+i-1]!='#'&&x-i>=0&&y+i<N){
                board[x-i+1][y+i-1]=board[x][y];
            }
        }
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x+i][y-i]=='#'||board[x+i][y-i]==symbol||board[x+i][y-i]=='.'){
                a=i;
            }
        }
        for(int i=a;i!=1;i--){
            if(board[x+i][y-i]==board[x][y]&&board[x+i-1][y-i+1]!='#'&&y-i>=0&&x+i<N){
                board[x+i-1][y-i+1]=board[x][y];
            }
        }
    }
    
    int count=0;
    for(int i=0;i<N;i++){
        for(int tmp=0;tmp<N;tmp++){
            if(symbol=='X'){
                if(board[i][tmp]=='O'){
                    count++;
                }
                if(secondboard[i][tmp]=='O'){
                    count--;
                }
            }else if(symbol=='O'){
                if(board[i][tmp]=='X'){
                    count++;
                }
                if(secondboard[i][tmp]=='X'){
                    count--;
                }
            }
        }
    }
    
    if(count<0){
        return 1;
    }else{
        for(int i=0;i<N;i++){
            for(int tmp=0;tmp<N;tmp++){
                board[i][tmp]=secondboard[i][tmp];
            }
        }
        
        return 0;}
}
//check avaiable move//
int check(char board[N][N],int x,int y, char symbol){
    char secondboard[N][N];
    
    for(int i=0;i<N;i++){
        for(int tmp=0;tmp<N;tmp++){
            secondboard[i][tmp]=board[i][tmp];
        }
    }
    
    
    board[x][y]=symbol;
    
    //Check left and right for symbol//
    
    if(symbol=='X'||symbol=='O'){
        int a=N;
        
        for(int i=N;i>y;i--){
            if(board[x][i]=='#'||board[x][i]==symbol){
                a=i;
            }
        }
        for(int i=a;i>y;i--){
            if(board[x][i]==board[x][y]&&board[x][i-1]!='#'){
                board[x][i-1]=board[x][y];
            }
        }
        
        a=0;
        for(int i=0;i<y;i++){
            if(board[x][i]=='#'||board[x][i]==symbol){
                a=i;
            }
        }
        
        
        for(int i=a;i<y;i++){
            if(board[x][i]==board[x][y]&&board[x][i+1]!='#'){
                board[x][i+1]=board[x][y];
            }
        }
        
        //check Up down//
        a=N;
        for(int i=N;i>x;i--){
            if(board[i][y]=='#'||board[i][y]==symbol){
                a=i;
            }
        }
        
        for(int i=a;i>x;i--){
            if(board[i][y]==board[x][y]&&board[i-1][y]!='#'){
                board[i-1][y]=board[x][y];
            }
        }
        
        a=0;
        for(int i=0;i<x;i++){
            if(board[i][y]=='#'||board[i][y]==symbol){
                a=i;
            }
        }
        for(int i=a;i<x;i++){
            if(board[i][y]==board[x][y]&&board[i+1][y]!='#'){
                board[i+1][y]=board[x][y];
            }
        }
        //check piece_Sideways//
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x+i][y+i]=='#'||board[x+i][y+i]==symbol){
                a=i;
            }
        }
        
        for(int i=a;i!=1;i--){
            if(board[x+i][y+i]==board[x][y]&&board[x+i-1][y+i-1]!='#'&&x+i<N&&y+i<N){
                board[x+i-1][y+i-1]=board[x][y];
            }
        }
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x-i][y-i]=='#'||board[x-i][y-i]==symbol){
                a=i;
            }
        }
        
        for(int i=a;i!=1;i--){
            if(board[x-i][y-i]==board[x][y]&&board[x-i+1][y-i+1]!='#'&&x-i>=0&&y-i>=0){
                board[x-i+1][y-i+1]=board[x][y];
            }
        }
        
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x-i][y+i]=='#'||board[x-i][y+i]==symbol){
                a=i;
            }
        }
        for(int i=a;i!=1;i--){
            if(board[x-i][y+i]==board[x][y]&&board[x-i+1][y+i-1]!='#'&&x-i>=0&&y+i<N){
                board[x-i+1][y+i-1]=board[x][y];
            }
        }
        a=N;
        for(int i=N;i!=0;i--){
            if(board[x+i][y-i]=='#'||board[x+i][y-i]==symbol){
                a=i;
            }
        }
        for(int i=a;i!=1;i--){
            if(board[x+i][y-i]==board[x][y]&&board[x+i-1][y-i+1]!='#'&&y-i>=0&&x+i<N){
                board[x+i-1][y-i+1]=board[x][y];
            }
        }
    }
    //See if any piece is taken from the opposite side//
    int count=0;
    for(int i=0;i<N;i++){
        for(int tmp=0;tmp<N;tmp++){
            if(symbol=='X'){
                if(board[i][tmp]=='O'){
                    count++;
                }
                if(secondboard[i][tmp]=='O'){
                    count--;
                }
            }else if(symbol=='O'){
                if(board[i][tmp]=='X'){
                    count++;
                    
                }
                if(secondboard[i][tmp]=='X'){
                    count--;
                    
                }
            }
        }
    }
    //Change the board back to the orginal//
    if(count<0){
        for(int i=0;i<N;i++){
            for(int tmp=0;tmp<N;tmp++){
                board[i][tmp]=secondboard[i][tmp];
            }
        }
        return 1;
    }else{
        for(int i=0;i<N;i++){
            for(int tmp=0;tmp<N;tmp++){
                board[i][tmp]=secondboard[i][tmp];
            }
        }
        return 0;}
}





//Set up board board//
void clearboard(char board[N][N]){
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            board[a][b]='.';
        }
    }
    
    board[N/2][N/2]=board[N/2-1][N/2-1]='X';
    board[N/2-1][N/2]=board[N/2][N/2-1]='O';
}



//Main function//
int main() {
    char board [N][N];
    int pit;
    string input;
    clearboard(board);
    
    //pit asked//
    cout<<"Enter number of pits: ";
    cin>> pit;
    while(pit>N*N/2){
        cout<<"Too many pits!\n";
        cout<<"Enter number of pits: ";
        cin>>pit;
    }
    
    //Printing pit onto the board//
    for(int tmp=1;tmp<=pit;tmp++){
        cout<<"Enter position for pit "<<tmp<<": ";
        cin>>input;
        
        //Checking pit input//
        while(checkinput(board,input)!=true){
            cout<<"Invalid position!\nEnter position for pit "<<tmp<<": ";
            cin>>input;
        }
        //Adding pit//
        switchboard(board,input,'#');
    }
    
    
    //Start//
    for(int turn=1;turn<=N*N;turn++){
        
        
        //Player 1//
        cout<<"Round "<<turn<<":\n";
        printboard(board);
        
        int moves=0;
        int rest=0;
        
        for(int i=0;i<N;i++){
            for(int tmp=0;tmp<N;tmp++){
                if (board[i][tmp]=='.'&&check(board,i,tmp,'X')!=0){
                    moves++;
                }
            }
        }
        
        
        
        if(moves==0){
            cout<<"Player X has no valid moves! Pass!"<<endl;
            rest++;
            
        }else{
            cout<<"Player X's turn: ";
            cin>>input;
            while(checkinput(board,input)!=true||switchboard(board,input,'X')!=1){
                cout<<"Invalid move!\nPlayer X's turn: ";
                cin>>input;
            }}
        turn++;
        
        
        
        //Player 2//
        cout<<"Round "<<turn<<":\n";
        printboard(board);
        
        moves=0;
        for(int i=0;i<N;i++){
            for(int tmp=0;tmp<N;tmp++){
                if (board[i][tmp]=='.'&&check(board,i,tmp,'O')!=0){
                    moves++;
                }
            }
        }
        
        if(moves==0){
            cout<<"Player O has no valid moves! Pass!"<<endl;
            rest++;
        }else{
            cout<<"Player O's turn: ";
            cin>>input;
            while(checkinput(board,input)!=true||switchboard(board,input,'O')!=1){
                cout<<"Invalid move!\nPlayer O's turn: ";
                cin>>input;
            }}
        if(rest==2){
            break;
        }
        
    }
    
    //Winning Result//
    
    int winO=0,winX=0;
    for(int i=0;i<N;i++){
        for( int tmp=0;tmp<N;tmp++){
            if(board[i][tmp]=='O'){
                winO++;
            }else if(board[i][tmp]=='X'){
                winX++;
            }
        }
    }
    cout<<"Gameover:\n";
    printboard(board);
    if(winO>winX){
        cout<<"Player O wins!";
    }else if(winX==winO){
        cout<<"Draw game!";
    }else{
        cout<<"Player X wins!";
    }
    
    return 0;
}


