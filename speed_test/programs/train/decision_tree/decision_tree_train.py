import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

decision_tree_model = DecisionTreeClassifier(min_samples_leaf=10, min_impurity_decrease=1e-7, max_depth=3)

decision_tree_model.fit(dataset,labels)

with open('decisionTree_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(decision_tree_model, f)



