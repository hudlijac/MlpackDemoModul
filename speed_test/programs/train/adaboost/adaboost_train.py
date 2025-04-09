import pandas as pd
from sklearn.linear_model import Perceptron
from sklearn.ensemble import AdaBoostClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

base_classifier = Perceptron(max_iter=100, tol=1e-6)

adaboost_model = AdaBoostClassifier(estimator=base_classifier,algorithm='SAMME')

adaboost_model.fit(dataset, labels)

with open('adaboost_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(adaboost_model, f)



