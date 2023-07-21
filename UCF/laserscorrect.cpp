#include <bits/stdc++.h>


using namespace std;
int t, r, c;
int starGrid[1001][1001];
int rowVals[1001];
int colVals[1001];
int prevRow[1001];
int prevCol[1001];
bool checkWorks(){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if ((rowVals[i] + colVals[j])%2 != starGrid[i][j]) return false;
        }
    }
    return true;
}
int main(){
    cin >> t;
    while(t--){
        
        cin >> r >> c;
        int numTotal = 0;
        for (int i = 0; i < r; i++){
            rowVals[i] = 0;
            string s;
            cin >> s;
            for (int j = 0; j < c; j++){
                colVals[j] = 0;
                starGrid[i][j] = s[j] - '0';
                
            }
        }
        

        for (int i = 0; i < c; i++){
            if (starGrid[0][i] == 1) colVals[i] = 1;
        }
        for (int i = 1; i < r; i++){
            if ((starGrid[i][0] + colVals[0])%2 == 1) rowVals[i] = 1;
        }

        if (checkWorks()){
            for (int i = 0; i < r; i++) {
                prevRow[i] = rowVals[i];
                if (prevRow[i] == 1) numTotal ++;
            }
            
            for (int i = 0; i < c; i++) {
                prevCol[i] = colVals[i];
                if (prevCol[i] == 1) numTotal++;
            }
        }
        for (int i = 0; i < r; i++) rowVals[i] = 0;
        for (int i = 0; i < c; i++) colVals[i] = 0;
        rowVals[0] = 1;
        for (int i = 0; i < c; i++){
            if (starGrid[0][i] == 0) colVals[i] = 1;
        }
        for (int i = 1; i < r; i++){
            if ((starGrid[i][0] + colVals[0])%2 == 1) rowVals[i] = 1;
        }
        int currTotal = 0;
        if (checkWorks()){
            for (int i = 0; i < r; i++) if (rowVals[i] == 1)currTotal++;
            for (int i = 0; i < c; i++) if (colVals[i] == 1) currTotal++;
            if (currTotal < numTotal){
                for (int i = 0; i < r; i++) cout << rowVals[i] << " ";
                cout << endl;
                for (int i = 0; i < c; i++) cout << colVals[i] << " ";
                cout << endl;
            }
            else{
                for (int i = 0; i < r; i++) cout << prevRow[i] << " ";
                cout << endl;
                for (int i = 0; i < c; i++) cout << prevCol[i] << " ";
                cout << endl;
            }
        }
        else{
            cout << "impossible" << endl;
        }


    }



    return 0;
}