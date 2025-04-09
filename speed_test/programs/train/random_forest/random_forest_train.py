import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

random_forest_model = make_pipeline(StandardScaler(),RandomForestClassifier(n_estimators=2, min_samples_leaf=1, min_impurity_decrease=1e-7, max_depth=3))

random_forest_model.fit(dataset,labels)

with open('random_forest_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(random_forest_model, f)



