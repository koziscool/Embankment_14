
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int e1(int limit){
    int total = 0;
    for( int i = 1; i < limit; i++ ){
        if( i % 3 == 0 || i % 5 == 0 )
            total += i;
    }
    
    return total;
}



int main(){
    cout << "e1:   " << e1(1000) << endl;

    return 0;
}
