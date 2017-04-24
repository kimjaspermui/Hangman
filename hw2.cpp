/**
 * Name:            Kim Jasper Mui
 * Date:            Apr 24 2017
 * Filename:        hw2.cpp
 * Description:     CSE 150 hw2 problem 3 solutions.
 * Sources of help: None.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

double populateSet(set<pair<double, string>>& mySet, ifstream& in) {

  double sum = 0;

  // while there is something to read, populate the vector
  while (in) {

    // a line from input
    string oneLine;

    // read the line if possible, if not, break out
    if (!getline(in, oneLine)) {

      break;
    }

    // stringstream for read one by one value
    istringstream mySS(oneLine);

    // the string to store the single element
    string data;

    // read the word and value
    getline(mySS, data, ' ');
    string word = data;
    getline(mySS, data, ' ');    
    double value = stod(data);

    // push this value to current vector
    mySet.insert({value, word});

    sum += value;
  }

  return sum;
}


int main(int argc, char* argv[]) {

  // check arguments number
  int NUM_ARGUMENTS = 2;
  if (argc != NUM_ARGUMENTS && argc != NUM_ARGUMENTS - 1) {

    cout << "Error! Must enter a data file" << endl;

    return 1;
  }

  // read in arguments
  int index = 1;
  string dataFileName = argv[index++];

  // obtain the training data
  ifstream in(dataFileName);
  set<pair<double, string>> dataSet;
  double sum = populateSet(dataSet, in);
  in.close();

  for (auto data : dataSet) {

    printf("%6f, %s\n", data.first, data.second.c_str());
  }
}
