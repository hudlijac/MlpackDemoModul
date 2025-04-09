import pandas as pd
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
from sklearn.calibration import CalibratedClassifierCV
import pickle

datasetFile = pd.read_csv("../../data/sdssdr6_4e7/train.csv")
labelsFile = pd.read_csv("../../data/sdssdr6_4e7/labels.csv")

dataset = datasetFile.values
labels = labelsFile.values.ravel()

lam=0.0
delta=1.0
fit_intercept=False
C=1e6

linear_svm_model = make_pipeline(StandardScaler(),SVC(C=C,kernel='linear',probability=True))

linear_svm_model.fit(dataset,labels)

with open('linearSVM_sdssdr6_4e7.pkl', 'wb') as f:
    pickle.dump(linear_svm_model, f)



