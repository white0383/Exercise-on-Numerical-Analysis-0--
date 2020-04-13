#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

    ifstream readFile;
    readFile.open("myRand.dat");
    if(!readFile.is_open()){
        cout << "File is not opened!" << endl;
        return 0;
    }

    char now_char;
    int now_int = -1;
    int prev_int = -1;
    //int count = 0;
    int countEachNumArr[10] = {0};
    map<int, int> comparePrevAndNowMap;

    while(readFile.get(now_char)){
        now_int = now_char-48;
        if(prev_int != -1){
            int delta = now_int - prev_int;
            if(comparePrevAndNowMap.count(delta)){
                comparePrevAndNowMap[delta]++;
            }else{
                comparePrevAndNowMap[delta] = 1;
            }
        }

        countEachNumArr[now_int]++;

        //count++;
        //cout << count << "\t int: " << now_int << "\t char: " << now_char << endl;
        prev_int = now_int;
    }

    cout << "Count Each Number" << endl;
    for(int i = 0; i < 10;i++){
        cout << i <<": "<< countEachNumArr[i] << endl;
    }

    cout << "Compare Prev and Now number" << endl;
    map<int, int>::iterator iter;
    for(iter = comparePrevAndNowMap.begin(); iter != comparePrevAndNowMap.end(); ++iter){
        cout << iter->first << " " << iter->second << endl;
    }

    readFile.close();

    return 0;
}