#include <iostream>
#include <fstream>
using namespace std;

#define INPUT_FILE "input.txt"
#define NUM_ROWS 3
#define NUM_COLUMNS 7

void readFile(int rows, int cols, char output[][NUM_COLUMNS], ifstream& f);
void display2D(int rows, int cols, char array2D[][NUM_COLUMNS]);
void display2D(int rows, int cols, char array2D[][NUM_ROWS]);
void rotate2D(int rows, int cols, char original[][NUM_COLUMNS], char output[][NUM_ROWS]);

int main(){
    char originalArray2D[NUM_ROWS][NUM_COLUMNS];

    ifstream file;
    file.open(INPUT_FILE);
    if(file.good()){
        readFile(NUM_ROWS, NUM_COLUMNS, originalArray2D, file);
        display2D(NUM_ROWS, NUM_COLUMNS, originalArray2D);
        cout << endl;

        char rotatedArray2D[NUM_COLUMNS][NUM_ROWS];
        rotate2D(NUM_ROWS, NUM_COLUMNS, originalArray2D, rotatedArray2D);
        display2D(NUM_COLUMNS, NUM_ROWS, rotatedArray2D);
        file.close();
    }
    else{
        cout << "Cannot open File" << endl;
    }

    return 0;
}

void readFile(int rows, int cols, char output[][NUM_COLUMNS], ifstream& f){
    char temp;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            f >> temp;
            output[i][j] = temp;
        }
    }
}

void display2D(int rows, int cols, char array2D[][NUM_COLUMNS]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }
}

void display2D(int rows, int cols, char array2D[][NUM_ROWS]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate2D(int rows, int cols, char original[][NUM_COLUMNS], char output[][NUM_ROWS]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            output[j][rows - i - 1] = original[i][j];
        }
    }
}