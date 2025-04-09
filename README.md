# MlpackDemoModul
This repository is part of my bachelor thesis Augmenting WIF library by a new Machine Learning Classifier. It contains a proxy server detector that uses the classifier I implemented, and a speed test that compares the speed of my MlpackClassifier classifier with the speed of the ScikitMlClassifier classifier.

## Proxy server detector
The "demo_modul" folder contains the source code of the proxy server detector. In addition, the folder contains IP flows of benign communication, public proxy server communication and residential ones, on which various Mlpack machine learning models were trained (see models). The IP flows were captured according to the IP lists from the folder "ip_lists". I tested the detector and measured metrics for evaluating the effectiveness of machine learning models (see results, where the results are clearly displayed in a table, or unirec_results, where there are only raw outputs from the detector, on the basis of which the table was compiled).

### ip_flows
This folder contains following files:

-benign_ipflow.csv - Benign dataset

-feature_names.txt - List of features, which are captured.

-proxy_data.tar.gz - Archive with all data for training and testing.

-pub_ipflow.csv - Public proxy servers dataset

-res_ipflow.csv - Residential proxy dataset

-test-proxy_anom.csv - Dataset with anomaly data for test of proxy detector (csv format).

-test-proxy_anom.trapcap - Dataset with anomaly data for test of proxy detector (unirec format).

-test-proxy_ben.csv - Dataset with benign data for test of proxy detector (csv format).

-test-proxy_ben.trapcap - Dataset with benign data for test of proxy detector (unirec format).

-test-res_anom.csv - Dataset with anomaly data for test of residential proxy detector (csv format).

-test-res_anom.trapcap - Dataset with anomaly data for test of residential proxy detector (unirec format).

-test-res_ben.csv - Dataset with benign data for test of residential proxy detector (csv format)

-test-res_ben.trapcap - Dataset with benign data for test of residential proxy detector (unirec format).

-train-proxy.csv - Dataset with data for training proxy server detector.

-train-proxy_labels.csv - Dataset with labels belonging to train-proxy.csv.

-train-res.csv - Dataset with data for training residential proxy server detector.

-train-res_labels.csv - Dataset with labels belonging to train-res.csv.

### ip_lists
This folder contains following files:

-pub_ips.txt - List of IP addresses of public proxy servers.

-residential_proxy_check.py - Script, which check IP address according to ip2location.io database.

-res_ips.txt - List of IP addresses of residential proxy.

### models
This folder contains following files with models. If any hyperparameters are not mentioned, default from particular train method are used.

-abDt_iter200_res_trained_data.bin - AdaBoost model with Decision Tree weak learner and maximum 200 iterations for residential proxy detector.

-abDt_iter200_trained_data.bin -AdaBoost model with Decision Tree weak learner and maximum 200 iterations for proxy server detector.

-abDt_res_trained_data.bin - AdaBoost model with Decisiont Tree weak learner for residential proxy detector.

-abDt_t10_res_trained_data.bin - AdaBoost model with Decision Tree weak learner and maximal depth of the tree 10 for residential proxy detector.

-abDt_t10_trained_data.bin - AdaBoost model with Decision Tree weak learner and maximal depth of the tree 10 for proxy server detector.

-abDt_t5_res_trained_data.bin - AdaBoost model with Decision Tree weak learner and maximal depth of the tree 5 for residential proxy detector.

-abDt_t5_trained_data.bin - AdaBoost model with Decision Tree weak learner and maximal depth of the tree 5 for proxy server detector.

-abDt_trained_data.bin - AdaBoost model with Decision Tree weak learner for proxy server detector.

-ab_iter200_res_trained_data.bin - AdaBoost model with Perceptron weak learner and maximum 200 iterations for residential proxy detector.

-ab_iter200_trained_data.bin - AdaBoost model with Perceptron weak learner and maximum 200 iterations for proxy server detector.

-ab_trained_data.bin - AdaBoost model with Perceptron weak learner for proxy server detector.

-ab_trained_res_data.bin - AdaBoost model with Perceptron weak learner for residential proxy detector.

-dt_d10_res_trained_data.bin - Decision Tree model with maximal depth 10 for residential proxy detector.

-dt_d10_trained_data.bin -Decision Tree model with maximal depth 10 for proxy server detector.

-dt_d5_res_trained_data.bin - Decision Tree model with maximal depth 5 for residential proxy detector.

-dt_d5_trained_data.bin - Decision Tree model with maximal depth 5 for proxy server detector.

-dt_res_trained_data.bin - Decision Tree model for residential proxy detector.

-dt_trained_data.bin - Decision Tree model for proxy server detector.

-ht_1_res_trained_data.bin - Hoeffding Tree model for residential proxy detector.

-ht_1_trained_data.bin - Hoeffding Tree model for proxy server detector.

-ht_2_res_trained_data.bin - Hoeffding Tree model with success probability 0.9, maximum samples 1 000, check interval 50 and min samples 75 for residential proxy detector.

-ht_2_trained_data.bin - Hoeffding Tree model with success probability 0.9, maximum samples 1 000, check interval 50 and min samples 75 for proxy server detector.

-ht_3_res_trained_data.bin - Hoeffding Tree model with success probability 0.99, maximum samples 5 000, check interval 500 and min samples 300 for residential proxy detector.

-ht_3_trained_data.bin - Hoeffding Tree model with success probability 0.99, maximum samples 5 000, check interval 500 and min samples 300 for proxy server detector.

-ht_4_res_trained_data.bin - Hoeffding Tree model with success probability 0.92, maximum samples 2 000, check interval 100 and min samples 150 for residential proxy detector.

-ht_4_trained_data.bin - Hoeffding Tree model with success probability 0.92, maximum samples 2 000, check interval 100 and min samples 150 for proxy server detector.

-nbc_res_trained_data.bin - Naive Bayes model for residential proxy detector.

-nbc_trained_data.bin - Naive Bayes model for proxy server detector.

-p_res_trained_data.bin - Perceptron model for residential proxy detector.

-p_trained_data.bin - Perceptron model for proxy server detector.

-rf_res_trained_data.bin - Random Forest model for residential proxy detector.

-rf_t100_res_trained_data.bin - Random Forest model with 100 trees for residential proxy detector.

-rf_t100_trained_data.bin - Random Forest model with 100 trees for proxy server detector.

-rf_t50_res_trained_data.bin -Random Forest model with 50 trees for residential proxy detector.

-rf_t50_trained_data.bin - Random Forest model with 50 trees for proxy server detector.

-rf_trained_data.bin - Random Forest model for proxy server detector.

-svm_l0_01_res_trained_data.bin - Linear SVM model with lambda 0,01 for residential proxy detector.

-svm_l0_1_res_trained_data.bin - Linear SVM model with lambda 0,1 for residential proxy detector.

-svm_l1_0_res_trained_data.bin - Linear SVM model with lambda 1 for residential proxy detector.

-svm_proxy_l0_01_trained_data.bin - Linear SVM model with lambda 0,01 for proxy server detector.

-svm_proxy_l0_1_trained_data.bin - Linear SVM model with lambda 0,1 for proxy server detector.

-svm_proxy_l1_0_trained_data.bin - Linear SVM model with lambda 1 for proxy server detector.

-svm_res_trained_data.bin - Linear SVM model for residential proxy detector.

-svm_trained_data.bin - Linear SVM model for proxy server detector.

### results
This folder contains file performance_metrics.ods with results.

### unirec_results
This folder contains outputs of the detectors for each trainded model.

### main.cpp and CMakeLists.txt
Source code of the detector, which can be compiled by CMakeList.

## Speed test
The "speed_test" folder contains the data on which I trained Mlpack and scikit-learn machine learning models using training programs (see programs/train). For the speed test, I measured the runtime of the program programs/speed_dest/main.cpp, which performed classification using the trained models. The measurement results are in the results folder.

### data/models
This folder contains following files with models. Hyperparameters are introduced in speed_test/programs/train/<i>name of the model</i>/hyperparams.txt.

-ab_trained_data_sdssdr6_4e7.bin - AdaBoost with Perceptron weak learner Mlpack model.

-adaboost_sdssdr6_4e7.pkl - AdaBoost with Perceptron weak learner scikit-learn model.

-decisionTree_sdssdr6_4e7.pkl - Decision Tree Mlpack model.

-dt_trained_data_sdssdr6_4e7.bin - Decision Tree scikit-learn model.

-linearSVM_sdssdr6_4e7.pkl - Linear SVM scikit-learn model.

-naive_bayes_sdssdr6_4e7.pkl - Naive Bayes scikit-learn model.

-nbc_trained_data_sdssdr6_4e7.bin - Naive Bayes Mlpack model.

-perceptron_sdssdr6_4e7.pkl - Perceptron scikit-learn model.

-p_trained_data_sdssdr6_4e7.bin - Perceptron Mlpack model.

-random_forest_sdssdr6_4e7.pkl - Random Forest scikit-learn model.

-rf_trained_data_sdssdr6_4e7.bin - Random Forest Mlpack model.

-svm_trained_data_sdssdr6_4e7.bin - Linear SVM Mlpack model.

### data/sdssdr6_4e7
-labels.csv - Dataset with labels belonging to train.csv.

-sdssdr6_4e7.csv - All data for training and testing.

-test.csv - Dataset with for test of proxy detector (csv format).

-train.csv - Dataset with data for training.

### programs/speed_test
This folder condeins source code of speed_test, which can be compiled by CMakeList.

### programs/train
This folder contains subfolders for each model, which contains Python script for training scikit-learn model and list of models hyperparameters.

Secondly the folder contains subfolder mlpack_train, where is C++ program for training Mlpack models.

### results
This folder contains file speed.ods with results.

## Usage

All C++ source codes can be compiled as C++17 code. In addition, the following libraries need to be installed:

-wif

-Mlpack

-Armadillo

-OpenMP

-unirec

-unirec++

For Python codes (training models for ScikitMlClassifier), the following libraries are needed:

-pandas

-sklearn

-pickle

## Author
Jáchym Hudlický <hudlijac@fit.cvut.cz>
# MlpackDemoModul
