#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class PolyphaseSorter {
private:
    int bufferSize;
    int numTapes;
    vector<ifstream> inputTapes;
    vector<ofstream> outputTapes;
    string baseName;

    void distributeInitialRuns() {
        ifstream inputFile(baseName + ".dat", ios::binary);
        vector<int> buffer(bufferSize);

        int tapeIndex = 0;
        while (inputFile.read(reinterpret_cast<char*>(buffer.data()), bufferSize * sizeof(int))) {
            sort(buffer.begin(), buffer.end());

            string tapeName = baseName + ".tape" + to_string(tapeIndex);
            ofstream tape(tapeName, ios::binary | ios::app);
            tape.write(reinterpret_cast<char*>(buffer.data()), bufferSize * sizeof(int));
            tape.close();

            tapeIndex = (tapeIndex + 1) % (numTapes - 1);
        }
        inputFile.close();
    }

    void mergePhase() {
        vector<bool> tapeActive(numTapes, false);
        int inputTapeCount = numTapes - 1;
        int outputTape = numTapes - 1;

        while (inputTapeCount > 1) {

            for (int i = 0; i < numTapes; i++) {
                if (i != outputTape) {
                    string tapeName = baseName + ".tape" + to_string(i);
                    inputTapes[i].open(tapeName, ios::binary);
                    tapeActive[i] = true;
                }
            }

            string outTapeName = baseName + ".tape" + to_string(outputTape);
            outputTapes[outputTape].open(outTapeName, ios::binary);

            priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>
            > minHeap;

            vector<int> currentValues(inputTapeCount);
            vector<bool> hasMore(inputTapeCount, true);

            for (int i = 0, j = 0; i < numTapes; i++) {
                if (tapeActive[i]) {
                    if (inputTapes[i].read(reinterpret_cast<char*>(&currentValues[j]), sizeof(int))) {
                        minHeap.push({ currentValues[j], j });
                    }
                    else {
                        hasMore[j] = false;
                    }
                    j++;
                }
            }


            while (!minHeap.empty()) {
                auto minElement = minHeap.top();
                minHeap.pop();

                int minVal = minElement.first;
                int tapeIdx = minElement.second;

                outputTapes[outputTape].write(reinterpret_cast<char*>(&minVal), sizeof(int));

                int physicalTape = 0;
                for (int i = 0, j = 0; i < numTapes; i++) {
                    if (tapeActive[i] && j++ == tapeIdx) {
                        physicalTape = i;
                        break;
                    }
                }

                if (inputTapes[physicalTape].read(reinterpret_cast<char*>(&currentValues[tapeIdx]), sizeof(int))) {
                    minHeap.push({ currentValues[tapeIdx], tapeIdx });
                }
                else {
                    hasMore[tapeIdx] = false;
                }
            }


            for (int i = 0; i < numTapes; i++) {
                if (tapeActive[i]) {
                    inputTapes[i].close();
                    remove((baseName + ".tape" + to_string(i)).c_str());
                    tapeActive[i] = false;
                }
            }
            outputTapes[outputTape].close();

            outputTape = (outputTape + 1) % numTapes;
            inputTapeCount--;
        }

        string finalTape = baseName + ".tape" + to_string((outputTape + 1) % numTapes);
        string resultFile = baseName + "_sorted.dat";
        rename(finalTape.c_str(), resultFile.c_str());
    }

public:
    PolyphaseSorter(const string& name, int bufSize = 1000, int tapes = 3)
        : baseName(name), bufferSize(bufSize), numTapes(tapes < 3 ? 3 : tapes),
        inputTapes(tapes), outputTapes(tapes) {}

    void sort() {
        distributeInitialRuns();
        mergePhase();
    }
};

int main() {

    ofstream testData("data.dat", ios::binary);
    vector<int> testValues = { 15, 8, 42, 4, 23, 16, 9, 55, 32, 7 };
    for (int val : testValues) {
        testData.write(reinterpret_cast<const char*>(&val), sizeof(int));
    }
    testData.close();


    PolyphaseSorter sorter("data", 3, 3);
    sorter.sort();

    ifstream result("data_sorted.dat", ios::binary);
    int value;
    cout << "Отсортированные данные: ";
    while (result.read(reinterpret_cast<char*>(&value), sizeof(int))) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
