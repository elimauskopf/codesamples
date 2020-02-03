#include <iostream>
#include <vector>
using namespace std;

int fibo(vector<int> &table, int n);


int fibo(vector<int> &table, int n){
    if (n < table.size()){
        return table[n];
    }
     else {
        int result = fibo(table,n-1) + fibo(table,n-2);
        table.push_back(result);
        return result;
    }
}

int main(){
    vector<int> memo;
    memo.push_back(0);
    memo.push_back(1);

    for(int i = 0; i < 47;  i++){
        cout << "fibo("<<i<<") = " << fibo(memo, i) << endl;
    
    }
   
}
