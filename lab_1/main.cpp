#include <iostream>
#include <vector>

namespace Matrixxx{

    using namespace std;

    int main(){
        vector<vector<double>> A;
        vector<vector<double>> B;
        vector<vector<double>> C;

        for (auto& row : A)
        {
            for (auto& el : row)
            {
                el = 1; 
            }
        }

        for (auto& row : A)
        {
            for (auto& el : row)
            {
                cout << el << " ";
            }
            cout << endl;
        }

        return 0;
    }
}
