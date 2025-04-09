#include "wif/classifiers/mlpackClassifier.hpp"
#include "wif/classifiers/scikitMlClassifier.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <wif/storage/dataVariant.hpp>
#include <wif/storage/flowFeatures.hpp>

using namespace WIF;

// Arguments:
// 1) Path to trained model
// 2) Set 0 for MlpackClassifier, 1 for ScikitMlClassifier
int main(int argc, char *argv[]) {
  WIF::Classifier *classifier;
  int IDsCount = std::stoi(argv[3]);
  std::vector<WIF::FeatureID> IDs;

  // Choose type of classifier according to argument
  if (argv[2][0] == '0') {
    classifier = new WIF::MlpackClassifier(argv[1]);
  } else {
    classifier = new ScikitMlClassifier("bridge.py", argv[1]);
  }

  // Set source feature IDs
  for (int i = 0; i < IDsCount; i++) {
    IDs.push_back(i);
  }

  classifier->setFeatureSourceIDs(IDs);

  // Load data for test
  std::string filename = "test.csv";
  std::ifstream file(filename);
  std::string line;
  std::vector<FlowFeatures> flowFeaturesVector;

  if (!file.is_open()) {
    std::cout << "Chyba pri otevreni souboru." << std::endl;
    return 1;
  }

  // Classification of individual IP flow records from test data
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string value;
    std::vector<double> row;

    while (std::getline(ss, value, ',')) {
      row.push_back(std::stod(value));
    }
    FlowFeatures flowFeatures(row.size());

    for (int i = 0; i < row.size(); i++) {
      flowFeatures.set(static_cast<FeatureID>(i), row[i]);
    }
    volatile auto result = classifier->classify(flowFeatures);
  }
  file.close();
  delete classifier;

  return 0;
}
