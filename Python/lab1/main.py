import sys

import mglearn
import pandas as pds
import matplotlib
import matplotlib.pyplot as plt
import numpy
import scipy
import IPython
import sklearn
from sklearn.datasets import load_iris

iris_dataset = load_iris()
print("Ключи iris_dataset: \n{}".format(iris_dataset.keys()))
print(iris_dataset['DESCR'][:200] + "\n...")
print("Названия ответов: {}".format(iris_dataset['target_names']))
print("Названия признаков:\n{}".format(iris_dataset['feature_names']))
print("Тип массива data: {}".format(type(iris_dataset['data'])))
print("Форма массива data: {}".format(iris_dataset['data'].shape))
print("Первые пять строк массива data:\n{}".format(iris_dataset['data'][:5]))
print("Типмассива target: {}".format(type(iris_dataset['target'])))
print("Формамассива target: {}".format(iris_dataset['target'].shape))
print("filename: {}".format(iris_dataset['filename']))
print("frame: {}".format(iris_dataset['frame']))
print("Ответы:\n{}".format(iris_dataset['target']))

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(
    iris_dataset['data'], iris_dataset['target'], random_state=0)

print("формамассива X_train: {}".format(X_train.shape))
print("формамассива y_train: {}".format(y_train.shape))
print("формамассива X_test: {}".format(X_test.shape))
print("формамассива y_test: {}".format(y_test.shape))

# создаем dataframe изданныхвмассиве X_train
from pandas.plotting import scatter_matrix
# маркируемстолбцы, используя строки в iris_dataset.feature_names
iris_dataframe = pds.DataFrame(X_train, columns=iris_dataset.feature_names)
# создаем матрицу рассеяния из dataframe, цвет точек задаем с помощью  y_train
grr = scatter_matrix(
    iris_dataframe,
    c=y_train,
    figsize=(15, 15),
    marker='o',
    hist_kwds={'bins': 20},
    s=60,
    alpha=.8,
    cmap= mglearn.cm3)
plt.show()