#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile){
        cerr << "Error: input.txt not found" << endl;
        return 1;
    }

    int processes, resources;
    inputFile >> processes >> resources;

    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> max(processes, vector<int>(resources));
    vector<vector<int>> require(processes, vector<int>(resources));
    vector<int> available(resources); // Fixed spelling

    for(int i = 0; i < processes; ++i){
        for(int j = 0; j < resources; ++j){
            inputFile >> allocation[i][j];
        }
    }


    for(int i = 0; i < processes; ++i){
        for(int j = 0; j < resources; ++j){
            inputFile >> max[i][j];
        }
    }

 
    for(int j = 0; j < resources; ++j){
        inputFile >> available[j];
    }

    inputFile.close();

    // Calculate required Matrix
    for(int i = 0; i < processes; ++i){
        for(int j = 0; j < resources; ++j){
            require[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Bankers Algorithm
    vector<int> work = available;
    vector<bool> finish(processes, false);
    vector<int> safeSequence;

    int finished = 0; 
    while(finished < processes){
        bool found = false;

        for(int p = 0; p < processes; ++p){
            if(!finish[p]){
                int j;
                for(j = 0; j < resources; ++j){
                    if(require[p][j] > work[j])
                        break;
                }

                if(j == resources){
                    for(int k = 0; k < resources; ++k){
                        work[k] += allocation[p][k];
                    }
                    safeSequence.push_back(p);
                    finish[p] = true;
                    found = true;
                    finished++;
                }
            }
        }
        if(!found){
            cout << "System is not in a safe state" << endl;
            return 0;
        }
    }

    cout << "system is in a safe state ";
    for(int i = 0; i < processes; ++i){
        cout << "P" << safeSequence[i];
        if(i < processes - 1) cout << "->";
    }
    cout << endl;

    return 0;
}