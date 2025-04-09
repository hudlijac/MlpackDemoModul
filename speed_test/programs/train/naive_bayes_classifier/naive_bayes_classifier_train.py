import pandas as pd
from sklearn.naive_bayes import GaussianNB
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

naive_bayes_model = GaussianNB(var_smoothing=1e-10)

naive_bayes_model.fit(dataset,labels)

with open('naive_bayes_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(naive_bayes_model, f)



