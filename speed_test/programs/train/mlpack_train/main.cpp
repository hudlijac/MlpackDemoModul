#include "wif/ml/mlpackModels/adaboostModel.hpp"
#include "wif/ml/mlpackModels/decisionTreeModel.hpp"
#include "wif/ml/mlpackModels/hoeffdingTreeModel.hpp"
#include "wif/ml/mlpackModels/linearSVMModel.hpp"
#include "wif/ml/mlpackModels/mlpackModel.hpp"
#include "wif/ml/mlpackModels/naiveBayesModel.hpp"
#include "wif/ml/mlpackModels/perceptronModel.hpp"
#include "wif/ml/mlpackModels/randomForestModel.hpp"
#include <ensmallen.hpp>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <wif/storage/dataVariant.hpp>
#include <wif/storage/flowFeatures.hpp>

using namespace WIF;

int main() {
  // MlpackClassifier initialization (edit according to your needs)
  WIF::MlpackModels::NaiveBayesModel nbc_model1;
  WIF::MlpackModels::DecisionTreeModel dt_model1;
  WIF::MlpackModels::LinearSVMModel svm_model1;
  WIF::MlpackModels::RandomForestModel rf_model1;
  WIF::MlpackModels::PerceptronModel p_model1;
  WIF::MlpackModels::AdaBoostModel<mlpack::Perceptron<>> a_model1;
  WIF::MlpackModels::AdaBoostModel<mlpack::DecisionTree<>> a_dt_model1;
  WIF::MlpackModels::HoeffdingTreeModel ht_model1;
  WIF::MlpackModels::HoeffdingTreeModel ht_model2;
  WIF::MlpackModels::HoeffdingTreeModel ht_model3;
  WIF::MlpackModels::HoeffdingTreeModel ht_model4;
  std::cout << "Inicializece probehla uspesne." << std::endl;

  // train models
  std::string filename =
      "train.csv"; // path of the training data (edit according to your needs)
  std::ifstream file(filename);
  std::string line;
  std::string path = "trained_data.bin"; // the name of the future model (edit
                                         // according to your needs)
  std::vector<FlowFeatures> flowFeaturesVector;

  if (!file.is_open()) {
    std::cout << "Chyba pri otevreni souboru." << std::endl;
    return 1;
  }

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
    flowFeaturesVector.push_back(flowFeatures);
  }
  file.close();

  std::string filename_labels = "labels.csv"; // path to the labels
  std::ifstream file_labels(filename_labels);
  std::vector<size_t> labels;

  if (!file_labels.is_open()) {
    std::cout << "Chyba pri otevreni souboru." << std::endl;
    return 1;
  }

  while (std::getline(file_labels, line)) {
    labels.push_back(std::stoi(line));
  }
  file_labels.close();

  std::vector<FeatureID> sourceFeatureIDs;

  for (int i = 0; i < 13; i++) {
    sourceFeatureIDs.push_back(i);
  }

  // The following setFeatureSourceIDs methods must be called for each
  // initialized MlpackClassifier (edit according to your needs)
  nbc_model1.setFeatureSourceIDs(sourceFeatureIDs);
  dt_model1.setFeatureSourceIDs(sourceFeatureIDs);
  svm_model1.setFeatureSourceIDs(sourceFeatureIDs);
  rf_model1.setFeatureSourceIDs(sourceFeatureIDs);
  p_model1.setFeatureSourceIDs(sourceFeatureIDs);
  a_model1.setFeatureSourceIDs(sourceFeatureIDs);
  a_dt_model1.setFeatureSourceIDs(sourceFeatureIDs);
  ht_model1.setFeatureSourceIDs(sourceFeatureIDs);
  ht_model2.setFeatureSourceIDs(sourceFeatureIDs);
  ht_model3.setFeatureSourceIDs(sourceFeatureIDs);
  ht_model4.setFeatureSourceIDs(sourceFeatureIDs);

  // The following train methods must be called for each initialized
  // MlpackClassifier (edit according to your needs)
  std::cout << "Zacatek trenovani" << std::endl;
  nbc_model1.train(flowFeaturesVector, labels, "nbc_" + path);
  dt_model1.train(flowFeaturesVector, labels, "dt_" + path);
  svm_model1.train(flowFeaturesVector, labels, "svm_" + path);
  rf_model1.train(flowFeaturesVector, labels, "rf_" + path);
  p_model1.train(flowFeaturesVector, labels, "p_" + path);
  a_model1.train(flowFeaturesVector, labels, "ab_" + path);
  a_dt_model1.train(flowFeaturesVector, labels, "abDt_" + path);
  ht_model1.train(flowFeaturesVector, labels, "ht_1_" + path);
  ht_model2.train(flowFeaturesVector, labels, "ht_2_" + path);
  ht_model3.train(flowFeaturesVector, labels, "ht_3_" + path);
  ht_model4.train(flowFeaturesVector, labels, "ht_4_" + path);
  std::cout << "Trenovani dat: uspech" << std::endl;
}