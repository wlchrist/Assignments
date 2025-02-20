#include "ListMyJosephus.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    ofstream logFile("results.log", ios::app);
    if (!logFile) {
        cerr << "Error opening results.log\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> rowDist(0, 24);
    uniform_int_distribution<int> destDist(1, 1025);

    vector<double> executionTimes;

    for (int N = 1; N <= 1025; N++) {
        int M = destDist(gen) % N + 1;

        ListMyJosephus game(M, N);
        game.storeDestinations("Destinations.csv");

        auto start = high_resolution_clock::now();
        game.eliminateDestinations();
        auto end = high_resolution_clock::now();

        duration<double> elapsed = end - start;
        executionTimes.push_back(elapsed.count());

        logFile << "ListMyJosephus | N: " << N << " | M: " << M << " | Time: " << elapsed.count() << " sec\n";

        cout << "Completed ListMyJosephus for N = " << N << ", M = " << M << endl;
    }

    double avgTime = 0;
    for (double t : executionTimes) {
        avgTime += t;
    }
    avgTime /= executionTimes.size();
    
    cout << "Average execution time for ListMyJosephus: " << avgTime << " sec\n";
    logFile << "Average execution time for ListMyJosephus: " << avgTime << " sec\n";

    logFile.close();
    return 0;
}
