#include <unirec++/unirec.hpp>
#include <unirec/unirec.h>

#include "wif/classifiers/mlpackClassifier.hpp"
#include <string>
#include <vector>
#include <wif/storage/dataVariant.hpp>
#include <wif/storage/flowFeatures.hpp>

#include <csignal>
#include <iostream>

#define IN_IFC_FORMAT                                                          \
  "double BYTES,double BYTES_REV,double PACKETS,double PACKETS_REV,double "    \
  "VARIANCE_TIME,double BYTES_PER_PACKETS,double "                             \
  "BYTES_REV_PER_PACKETS_REV,double AVERAGE_PPI_PKT_LENGTHS,double "           \
  "AVERAGE_PPI_PKT_TIMES,double BYTES_PER_SECOND,double "                      \
  "BYTES_REV_PER_SECOND,double PACKETS_PER_SECOND,double "                     \
  "PACKETS_REV_PER_SECOND"
#define OUT_IFC_FORMAT "int8 ANOMALLY"

using namespace Nemea;
using namespace WIF;
using namespace WIF::MlpackModels;

static volatile std::sig_atomic_t g_SignalStatus;

typedef struct ip_addr_s {
  uint64_t ui64[2];
} ip_addr_t2;

static void signalHandler(int signal) {
  if (signal == SIGINT || signal == SIGQUIT || signal == SIGHUP ||
      signal == SIGTERM) {
    g_SignalStatus = 1;
  }
}

void mainLoop(MlpackClassifier &classifier, UnirecInputInterface &inputIfc,
              UnirecOutputInterface &outputIfc) {
  while (!g_SignalStatus) {
    try {
      // Receive record
      std::optional<UnirecRecordView> unirecRecord = inputIfc.receive();
      if (!unirecRecord) {
        break;
      }

      // Extracting features from unirecRecord
      double bytes =
          unirecRecord->getFieldAsType<double_t>(ur_get_id_by_name("BYTES"));
      double bytes_rev = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("BYTES_REV"));
      double packets =
          unirecRecord->getFieldAsType<double_t>(ur_get_id_by_name("PACKETS"));
      double packets_rev = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("PACKETS_REV"));
      double variance_time = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("VARIANCE_TIME"));
      double bytes_per_packets = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("BYTES_PER_PACKETS"));
      double bytes_rev_per_packets_rev = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("BYTES_REV_PER_PACKETS_REV"));
      double average_PPI_PKT_LENGTHS = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("AVERAGE_PPI_PKT_LENGTHS"));
      double average_PPI_PKT_TIMES = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("AVERAGE_PPI_PKT_TIMES"));
      double bytes_per_second = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("BYTES_PER_SECOND"));
      double bytes_rev_per_second = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("BYTES_REV_PER_SECOND"));
      double packets_per_second = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("PACKETS_PER_SECOND"));
      double packets_rev_per_second = unirecRecord->getFieldAsType<double_t>(
          ur_get_id_by_name("PACKETS_REV_PER_SECOND"));

      // Set FlowFeatures for classifier
      WIF::FlowFeatures flowFeatures(13);

      flowFeatures.set<double>(static_cast<FeatureID>(0), bytes);
      flowFeatures.set<double>(static_cast<FeatureID>(1), bytes_rev);
      flowFeatures.set<double>(static_cast<FeatureID>(2), packets);
      flowFeatures.set<double>(static_cast<FeatureID>(3), packets_rev);
      flowFeatures.set<double>(static_cast<FeatureID>(4), variance_time);
      flowFeatures.set<double>(static_cast<FeatureID>(5), bytes_per_packets);
      flowFeatures.set<double>(static_cast<FeatureID>(6),
                               bytes_rev_per_packets_rev);
      flowFeatures.set<double>(static_cast<FeatureID>(7),
                               average_PPI_PKT_LENGTHS);
      flowFeatures.set<double>(static_cast<FeatureID>(8),
                               average_PPI_PKT_TIMES);
      flowFeatures.set<double>(static_cast<FeatureID>(9), bytes_per_second);
      flowFeatures.set<double>(static_cast<FeatureID>(10),
                               bytes_rev_per_second);
      flowFeatures.set<double>(static_cast<FeatureID>(11), packets_per_second);
      flowFeatures.set<double>(static_cast<FeatureID>(12),
                               packets_rev_per_second);

      // Classification
      bool isAnomally =
          (classifier.classify(flowFeatures).get<std::vector<double>>()[0] <
           0.5); // change conversion of classify result to bool representation
                 // according to which data type classify method returns.

      // Send result
      auto outputRecord = outputIfc.createUnirecRecord();

      outputRecord.setFieldFromType<bool>(isAnomally,
                                          ur_get_id_by_name("ANOMALLY"));
      outputIfc.send(outputRecord);
    } catch (EoFException) {
      break;
    } catch (std::exception &ex) {
      std::cerr << "Error: " << ex.what() << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  Unirec unirec({1, 1, "MlpackClassifier", "Mlpack classifier"});
  MlpackClassifier classifier("../models/svm_trained_data.bin");

  unirec.init(argc, argv);

  auto inputIfc = unirec.buildInputInterface();
  inputIfc.setRequieredFormat(IN_IFC_FORMAT);

  auto outputIfc = unirec.buildOutputInterface();
  outputIfc.changeTemplate(OUT_IFC_FORMAT);

  std::vector<FeatureID> sourceFeatureIDs = {0, 1, 2, 3,  4,  5, 6,
                                             7, 8, 9, 10, 11, 12};

  classifier.setFeatureSourceIDs(sourceFeatureIDs);
  mainLoop(classifier, inputIfc, outputIfc);
}