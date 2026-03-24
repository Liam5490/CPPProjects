#include <iostream>
#include <vector>
using namespace std; 

class SquareMatrix {
    private:
    vector<vector<double> > data;
    size_t order;

    public:
    SquareMatrix(size_t n): order(n) { 
        data.resize(order); 
        for (size_t i=0; i < order; i++) {
            data[i].resize(order);
        }
    }
    
    void setSquareMatrix(size_t row, size_t col, double value) {
        data[row][col] = value;
    }

    double getSquareMatrix(size_t row, size_t col) {
        return data[row][col];
    }    

    vector<double> getdiagonal() {
        vector<double> diagonal;
        for (size_t i= 0; i<order; i++) {
            diagonal.push_back(data[i][i]);
        }
        return diagonal;
    }


};

int main() {
 
    SquareMatrix mx(3); //mx stands for matrix, easy to remember as an iterator

    
    mx.setSquareMatrix(0, 0, 4);
    mx.setSquareMatrix(0, 1, 6);
    mx.setSquareMatrix(0, 2, 2);
    mx.setSquareMatrix(1, 1, 8);
    mx.setSquareMatrix(2, 2, 10);

    cout << "Element at (0,1): " << mx.getSquareMatrix(0, 1) << endl;
    cout << "Element at (2,2): " << mx.getSquareMatrix(2, 2) << endl;


    vector<double> diag = mx.getdiagonal(); //uses diagonal getter
    cout << "Diagonal: ";
    for (size_t i = 0; i < diag.size(); i++) {
    cout << diag[i] << " ";
}
    cout << endl;

    return 0;
}
