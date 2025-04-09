import pandas as pd
from sklearn import linear_model
from sklearn.datasets import make_classification
from sklearn.calibration import CalibratedClassifierCV
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

perceptron_model = linear_model.Perceptron(max_iter=50)
perceptron_model.fit(dataset,labels)
clf_isotonic = CalibratedClassifierCV(perceptron_model, cv="prefit", method='isotonic')

clf_isotonic.fit(dataset, labels)

with open('perceptron_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(clf_isotonic, f)



