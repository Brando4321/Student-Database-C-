#include <iostream>
#include <fstream>
using namespace std;


int main(){
    fstream myFile;
    myFile.open("accounts.txt", ios::out);//Write 
    if(myFile.is_open()){
        myFile<<"Hello my name is Brandon"<<endl;
    }
    else{
        cout << "Error opening file" << endl;
    }

return 0;
}