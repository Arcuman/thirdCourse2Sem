#LAB 1
#import sys
#import pandas
#import matplotlib
#import numpy
#import scipy
#import IPython
#import sklearn

#print("версия Python: {}".format(sys.version))
#print("версия pandas: {}".format(pandas.__version__))
#print("версия matplotlib: {}".format(matplotlib.__version__))
#print("версия numpy: {}".format(numpy.__version__))
#print("версия scipy: {}".format(scipy.__version__))
#print("версия IPython: {}".format(IPython.__version__))
#print("версия sklearn: {}".format(sklearn.__version__))

#import sys
#import pandas as pds
#import mglearn
#import matplotlib
#import matplotlib.pyplot as plt
#import numpy as np
#import scipy as sp
#import IPython
#import sklearn
#from sklearn.datasets import load_iris
#iris_dataset = load_iris()



#print("Ключи iris_dataset: \n{}".format(iris_dataset.keys()))
#print(iris_dataset['DESCR'][:193] + "\n...")
#print("Названия ответов: {}".format(iris_dataset['target_names']))
#print("Названия признаков: \n{}".format(iris_dataset['feature_names']))
#print("Тип массива data: {}".format(type(iris_dataset['data'])))
#print("Форма массива data: {}".format(iris_dataset['data'].shape))
#print("Первые пять строк массива data:\n{}".format(iris_dataset['data'][:5]))
#print("Тип массива target: {}".format(type(iris_dataset['target'])))
#print("Форма массива target: {}".format(iris_dataset['target'].shape))
#print("Ответы:\n{}".format(iris_dataset['target']))

#from sklearn.model_selection import train_test_split

#X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state=0)
#print("форма массива X_train: {}".format(X_train.shape))
#print("форма массива y_train: {}".format(y_train.shape))
#print("форма массива X_test: {}".format(X_test.shape))
#print("форма массива y_test: {}".format(y_test.shape))
#iris_dataframe = pds.DataFrame(X_train, columns=iris_dataset.feature_names)

#from pandas.plotting import scatter_matrix

#grr = scatter_matrix(iris_dataframe, c=y_train, figsize=(30, 30), marker='w', hist_kwds={'bins': 150}, s=150, alpha=.8, cmap=mglearn.cm3)
#plt.show()

#LAB 2
#import pandas as pds
#import mglearn
#import matplotlib.pyplot as plt
#import numpy as np
#from sklearn.datasets import load_iris
#from sklearn.model_selection import train_test_split
#iris_dataset = load_iris()

#X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state=0)
#print("форма массива X_train: {}".format(X_train.shape))
#print("форма массива y_train: {}".format(y_train.shape))
#print("форма массива X_test: {}".format(X_test.shape))
#print("форма массива y_test: {}".format(y_test.shape))
#iris_dataframe = pds.DataFrame(X_train, columns=iris_dataset.feature_names)

#from pandas.plotting import scatter_matrix

#grr = scatter_matrix(iris_dataframe, c=y_train, figsize=(15, 15), marker='o',hist_kwds={'bins': 20}, s=60, alpha=.8, cmap=mglearn.cm3)

#from sklearn.neighbors import KNeighborsClassifier
#knn = KNeighborsClassifier(n_neighbors=3)
#knn.fit(X_train, y_train)
#X_new = np.array([[5, 2.9, 1, 0.2]])

#print("форма массива X_new: {}".format(X_new.shape))
#prediction = knn.predict(X_new)
#print("Прогноз: {}".format(prediction))
#print("Спрогнозированная метка: {}".format(iris_dataset['target_names'][prediction]))
#y_pred = knn.predict(X_test)
#print("Прогнозы для тестового набора:\n{}".format(y_pred))
#print("Правильность на тестовом наборе: {:.2f}".format(np.mean(y_pred == y_test)))
#print("Правильность на тестовом наборе: {:.2f}".format(knn.score(X_test, y_test)))
#X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state=0)
#knn = KNeighborsClassifier(n_neighbors=1)
#knn.fit(X_train, y_train)
#print("Правильность на тестовом наборе: {:.2f}".format(knn.score(X_test, y_test)))

# 3 LAB
#from sklearn.datasets import load_breast_cancer
#rom sklearn.datasets import load_boston

#X, y = mglearn.datasets.make_forge()
#mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
#plt.legend(["Класс 0", "Класс 1"], loc=4)
#plt.xlabel("Первый признак")
#plt.ylabel("Второй признак")
#print("форма массива X: {}".format(X.shape))
#plt.show()
#X, y = mglearn.datasets.make_wave(n_samples=40)
#plt.plot(X, y, 'o')
#plt.ylim(-3, 3)
#plt.xlabel("Признак")
#plt.ylabel("Целевая переменная")
#plt.show()
#cancer = load_breast_cancer()
#print("Ключи cancer(): \n{}".format(cancer.keys()))
#print("Форма массива data для набора cancer: {}".format(cancer.data.shape))
#print("Количество примеров для каждого класса:\n{}".format({n: v for n, v in zip(cancer.target_names, np.bincount(cancer.target))}))
#print("Количество примеров для каждого класса:\n{}".format({n: v for n, v in zip(cancer.target_names, np.bincount(cancer.target))}))

#boston = load_boston()
#print("форма массива data для набора boston: {}".format(boston.data.shape))
#X, y = mglearn.datasets.load_extended_boston()
#print("форма массива X: {}".format(X.shape))
#mglearn.plots.plot_knn_classification(n_neighbors=1)
#plt.show()
##mglearn.plots.plot_knn_classification(n_neighbors=3)
#plt.show()

#X, y = mglearn.datasets.make_forge()
#X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
#clf = KNeighborsClassifier(n_neighbors=3)
#clf.fit(X_train, y_train)
#print("Прогнозы на тестовом наборе: {}".format(clf.predict(X_test)))
#print("Правильность на тестовом наборе: {:.2f}".format(clf.score(X_test, y_test)))

#fig, axes = plt.subplots(1,3, figsize=(10, 3))
#for n_neighbors, ax in zip([1,3, 9], axes):
# clf = KNeighborsClassifier(n_neighbors=n_neighbors).fit(X, y)
    #mglearn.plots.plot_2d_separator(clf, X, fill=True, eps=0.5, ax=ax, alpha=.4)
    # mglearn.discrete_scatter(X[:, 0], X[:, 1], y, ax=ax)
    #ax.set_title("количество соседей:{}".format(n_neighbors))
    # ax.set_xlabel("признак 0")
    #    ax.set_ylabel("признак 1")

#axes[0].legend(loc=3)
#plt.show()

#from sklearn.datasets import load_breast_cancer
#cancer = load_breast_cancer()
#X_train, X_test, y_train, y_test = train_test_split(cancer.data, cancer.target, stratify=cancer.target, random_state=66)
#training_accuracy = []
#test_accuracy = []
#neighbors_settings = range(1, 11)

#for n_neighbors in neighbors_settings:
    #clf = KNeighborsClassifier(n_neighbors=n_neighbors)
    #clf.fit(X_train, y_train)
    # training_accuracy.append(clf.score(X_train, y_train))
    #    test_accuracy.append(clf.score(X_test, y_test))

#plt.plot(neighbors_settings, training_accuracy, label="правильность на обучающем наборе")
#plt.plot(neighbors_settings, test_accuracy, label="правильность на тестовом наборе")
#plt.ylabel("Правильность")
#plt.xlabel("количество соседей")
#plt.legend()
#plt.show()

#mglearn.plots.plot_knn_regression(n_neighbors=1)
#plt.show()

#mglearn.plots.plot_knn_regression(n_neighbors=3)
#plt.show()
#from sklearn.neighbors import KNeighborsRegressor
#X, y = mglearn.datasets.make_wave(n_samples=40)
#X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

#reg = KNeighborsRegressor(n_neighbors=3)
#reg.fit(X_train, y_train)

#print("Прогнозы для тестового набора:\n{}".format(reg.predict(X_test)))
#print("R^2 на тестовом наборе: {:.2f}".format(reg.score(X_test, y_test)))

#fig, axes = plt.subplots(1, 3, figsize=(15, 4))
#line = np.linspace(-3, 3, 1000).reshape(-1, 1)

#for n_neighbors, ax in zip([1, 3, 9], axes):
    #reg = KNeighborsRegressor(n_neighbors=n_neighbors)
    #reg.fit(X_train, y_train)
    #ax.plot(line, reg.predict(line))
    #ax.plot(X_train, y_train, '^', c=mglearn.cm2(0), markersize=8)
    #ax.plot(X_test, y_test, 'v', c=mglearn.cm2(1), markersize=8)
    #ax.set_title("{} neighbor(s)\ntrain score: {:.2f} test score: {:.2f}".format(n_neighbors, reg.score(X_train, y_train), reg.score(X_test, y_test)))
    #    ax.set_xlabel("Признак")
    #    ax.set_ylabel("Целевая переменная")
#axes[0].legend(["Прогнозы модели", "Обучающие данные/ответы","Тестовые данные/ответы"], loc="best")
#plt.show()


#import sklearn
#import mglearn
#import matplotlib.pyplot as plt
#import matplotlib
#import numpy as np
#mglearn.plots.plot_linear_regression_wave()
#plt.show()

#from sklearn.linear_model import LinearRegression
#X, y = mglearn.datasets.make_wave(n_samples=60)

#from sklearn.model_selection import train_test_split
#X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=42)
#lr = LinearRegression().fit(X_train, y_train)
#print("lr.coef_: {}".format(lr.coef_))
#print("lr.intercept_: {}".format(lr.intercept_))
#print("Правильность на обучающем наборе: {:.2f}".format(lr.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(lr.score(X_test, y_test)))
#X, y = mglearn.datasets.load_extended_boston()
#X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
#lr = LinearRegression().fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(lr.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(lr.score(X_test, y_test)))

#from sklearn.linear_model import Ridge
#ridge = Ridge().fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(ridge.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(ridge.score(X_test, y_test)))
#ridge10 = Ridge(alpha=10).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(ridge10.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(ridge10.score(X_test, y_test)))
#ridge01 = Ridge(alpha=0.1).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(ridge01.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(ridge01.score(X_test, y_test)))
#plt.plot(ridge.coef_, 's', label="Гребневая регрессия alpha=1")
#plt.plot(ridge10.coef_, '^', label="Гребневая регрессия alpha=10")
#plt.plot(ridge01.coef_, 'v', label="Гребневая регрессия alpha=0.1")
#plt.plot(lr.coef_, 'o', label="Линейная регрессия")
#plt.xlabel("Индекс коэффициента")
#lt.ylabel("Оценка коэффициента")
#plt.hlines(0, 0, len(lr.coef_))
#plt.ylim(-25, 25)
#plt.legend()
#plt.show()

#mglearn.plots.plot_ridge_n_samples()
#plt.show()

#from sklearn.linear_model import Lasso
#lasso = Lasso().fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(lasso.score(X_train, y_train)))
#print("Правильность на контрольном наборе: {:.2f}".format(lasso.score(X_test, y_test)))
#print("Количество использованных признаков: {}".format(np.sum(lasso.coef_ != 0)))
#lasso001 = Lasso(alpha=0.01, max_iter=100000).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(lasso001.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(lasso001.score(X_test, y_test)))
#print("Количество использованных признаков: {}".format(np.sum(lasso001.coef_ != 0)))
#lasso00001 = Lasso(alpha=0.0001, max_iter=100000).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.2f}".format(lasso00001.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.2f}".format(lasso00001.score(X_test, y_test)))
#print("Количество использованных признаков: {}".format(np.sum(lasso00001.coef_ != 0)))
#plt.plot(lasso.coef_, 's', label="Лассо alpha=1")
#plt.plot(lasso001.coef_, '^', label="Лассо alpha=0.01")
#plt.plot(lasso00001.coef_, 'v', label="Лассо alpha=0.0001")
#plt.plot(ridge01.coef_, 'o', label="Гребневая регрессия alpha=0.1")
#plt.legend(ncol=2, loc=(0, 1.05))
#plt.ylim(-25, 25)
#plt.xlabel("Индекс коэффициента")
#plt.ylabel("Оценка коэффициента")
#plt.show()


#LAB 4
#import mglearn
#import sklearn
#import matplotlib.pyplot as plt
#from sklearn.linear_model import LogisticRegression
#from sklearn.svm import LinearSVC
#X, y = mglearn.datasets.make_forge()
#fig, axes = plt.subplots(1, 2, figsize=(10, 3))
#for model, ax in zip([LinearSVC(), LogisticRegression()], axes):
#    clf = model.fit(X, y)
#    mglearn.plots.plot_2d_separator(clf, X, fill=False, eps=0.5,ax=ax, alpha=.7)
#    mglearn.discrete_scatter(X[:, 0], X[:, 1], y, ax=ax)
#    ax.set_title("{}".format(clf.__class__.__name__))
#    ax.set_xlabel("Признак 0")
#    ax.set_ylabel("Признак 1")
#axes[0].legend()
#plt.show()

#mglearn.plots.plot_linear_svc_regularization()
#plt.show()

#from sklearn.datasets import load_breast_cancer
#cancer = load_breast_cancer()

#from sklearn.model_selection import train_test_split

#X_train, X_test, y_train, y_test = train_test_split(cancer.data, cancer.target, stratify=cancer.target, random_state=42)
#logreg = LogisticRegression().fit(X_train, y_train)

#print("Правильность на обучающем наборе: {:.3f}".format(logreg.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(logreg.score(X_test, y_test)))

#logreg100 = LogisticRegression(C=100).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.3f}".format(logreg100.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(logreg100.score(X_test, y_test)))

#logreg001 = LogisticRegression(C=0.01).fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.3f}".format(logreg001.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(logreg001.score(X_test, y_test)))
#plt.plot(logreg.coef_.T, 'o', label="C=1")
#plt.plot(logreg100.coef_.T, '^', label="C=100")
#plt.plot(logreg001.coef_.T, 'v', label="C=0.001")
#plt.xticks(range(cancer.data.shape[1]), cancer.feature_names, rotation=90)
#plt.hlines(0, 0, cancer.data.shape[1])
#plt.ylim(-5, 5)
#plt.xlabel("Индекс коэффициента")
#plt.ylabel("Оценка коэффициента")


#plt.legend()
#plt.show()

#for C, marker in zip([0.001, 1, 100], ['o', '^', 'v']):
#    lr_l1 = LogisticRegression(C=C, penalty="l2").fit(X_train, y_train)
#    print("Правильность на обучении для логрегрессии l1 с C={:.3f}: {:.2f}".format( C, lr_l1.score(X_train,y_train)))
#    print("Правильность на тесте для логрегрессии l1 с C={:.3f}: {:.2f}".format( C, lr_l1.score(X_test, y_test)))
#plt.plot(lr_l1.coef_.T, marker, label="C={:.3f}".format(C))
#plt.xticks(range(cancer.data.shape[1]), cancer.feature_names, rotation=90)
#plt.hlines(0, 0, cancer.data.shape[1])
#plt.xlabel("Индекс коэффициента")
#plt.ylabel("Оценка коэффициента")
#plt.ylim(-5, 5)
#plt.legend(loc=3)
#plt.show()


#LAB 5
#import mglearn
#import sklearn
#import matplotlib.pyplot as plt
#import numpy as np
#from sklearn.datasets import make_blobs

#X, y = make_blobs(random_state=1942)
#mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
#plt.xlabel("Признак 0")
#plt.ylabel("Признак 1")
#plt.legend(["Класс 0", "Класс 1", "Класс 2"])
#plt.show()

#from sklearn.svm import LinearSVC

#linear_svm = LinearSVC().fit(X, y)
#print("Форма коэффициента: ", linear_svm.coef_.shape)
#print("Форма константы: ", linear_svm.intercept_.shape)
#mglearn.discrete_scatter(X[:, 0], X[:, 1], y)

#line = np.linspace(-15, 15)
#for coef, intercept, color in zip(linear_svm.coef_, linear_svm.intercept_, ['b', 'r', 'g']):
#    plt.plot(line, -(line * coef[0] + intercept) / coef[1], c=color)

#plt.ylim(-10, 15)
#plt.xlim(-10, 8)
#plt.xlabel("Признак 0")
#plt.ylabel("Признак 1")
#plt.legend(['Класс 0', 'Класс 1', 'Класс 2', 'Линия класса 0', 'Линия класса 1', 'Линия класса2'], loc=(1.01, 0.3))
#plt.show()

#mglearn.plots.plot_2d_classification(linear_svm, X, fill=True, alpha=.7)
#mglearn.discrete_scatter(X[:, 0], X[:, 1], y)

#line = np.linspace(-15, 15)

#for coef, intercept, color in zip(linear_svm.coef_, linear_svm.intercept_, ['b', 'r', 'g']):
#    plt.plot(line, -(line * coef[0] + intercept) / coef[1], c=color)

#plt.legend(['Класс 0', 'Класс 1', 'Класс 2', 'Линия класса 0', 'Линия класса 1','Линия класса 2'], loc=(1.01, 0.3))
#plt.xlabel("Признак 0")
#plt.ylabel("Признак 1")
#plt.show()


#LAB 6
#import mglearn
#import sklearn
#import matplotlib.pyplot as plt
#import numpy as np
#from sklearn.naive_bayes import BernoulliNB
#from sklearn.naive_bayes import MultinomialNB
#from sklearn.naive_bayes import GaussianNB
# Классификатор BernoulliNB
#X = np.array([[0, 1, 0, 1], [1, 0, 1, 1], [0, 0, 0, 1], [1, 0, 1, 0]])
#Y = np.array([0, 1, 0, 1])
#counts = {}
#for label in np.unique(Y):
#    counts[label] = X[Y == label].sum(axis=0)
#print("Частоты признаков:\n{}".format(counts))
#clf = BernoulliNB()
#clf.fit(X, Y)
#print("clf.predict:\n{}".format(clf.predict(X[2:3])))

# Классификатор MultinomialNB
#rng = np.random.RandomState(1)
#X = rng.randint(5, size=(6, 100))
#Y = np.array([1, 2, 3, 4, 5, 6])
#clf = MultinomialNB()
#clf.fit(X, Y)
#print(clf.predict(X[2:3]))

# Классификатор GaussianNB
#X = np.array([[-1, -1], [-2, -1], [-3, -2], [1, 1], [2, 1], [3, 2]])
#Y = np.array([1, 1, 1, 2, 2, 2])
#clf = GaussianNB()
#clf.fit(X, Y)
#print(clf.predict([[-0.8, -1]]))
#clf_pf = GaussianNB()
#clf_pf.partial_fit(X, Y, np.unique(Y))
#print(clf_pf.predict([[-0.8, -1]]))



#LAB 7
#import mglearn
#import sklearn
#import matplotlib.pyplot as plt
#import numpy as np

#X = np.array([[0,1,0,1],[1,0,1,1],[0,0,0,1],[1,0,1,0]])
#y = np.array([0,1,0,1])

#counts = {}

#for label in np.unique(y):
#    counts[label] = X[y==label].sum(axis=0)
#print("Частоты признаков:\n{}".format(counts))

#mglearn.plots.plot_animal_tree()
#plt.show()

#mglearn.plots.plot_tree_progressive()
#plt.show()

#from sklearn.tree import DecisionTreeClassifier
#from sklearn.datasets import load_breast_cancer
#from sklearn.model_selection import train_test_split

#cancer = load_breast_cancer()
#X_train,X_test,y_train,y_test = train_test_split(cancer.data,cancer.target,stratify=cancer.target,random_state=42)
#tree = DecisionTreeClassifier(random_state=0)
#tree.fit(X_train,y_train)
#print("Правильность на обучающем наборе:{:.3f}".format(tree.score(X_train,y_train)))
#print("Правильность на тестовом наборе:{:.3f}".format(tree.score(X_test,y_test)))

#tree = DecisionTreeClassifier(max_depth=4,random_state=0)
#tree.fit(X_train,y_train)

#print("Правильность на обучающем наборе:{:.3f}".format(tree.score(X_train,y_train)))
#print("Правильность на тестовом наборе:{:.3f}".format(tree.score(X_test,y_test)))

#from sklearn.tree import export_graphviz
#export_graphviz(tree,
#                out_file="/home/vladislav/tree.dot",
#                class_names=["malignant","benign"],
#                feature_names=cancer.feature_names,
#                impurity=False,
#                filled=True)

#import graphviz

#with open("/home/vladislav/tree.dot") as f:
#    dot_graph = f.read()
#graphviz.Source(dot_graph)

#"Export as pdf"
#from sklearn.model_selection import train_test_split
#from sklearn.datasets import load_breast_cancer
#from sklearn import tree

#cancer = load_breast_cancer()
#X_train, X_test, y_train, y_test = train_test_split(cancer.data,cancer.target,stratify=cancer.target,random_state=42)
#clf = tree.DecisionTreeClassifier(max_depth=4, random_state=0)
#clf = clf.fit(X_train,y_train)

#import pydotplus
#dot_data = tree.export_graphviz(clf,out_file=None)
#graph = pydotplus.graph_from_dot_data(dot_data)
#graph.write_pdf("cancer.pdf")

#"Create tree with using IPython"
#from IPython.display import Image

#dot_data=tree.export_graphviz(clf,
#                              out_file=None,
#                              feature_names=cancer.feature_names,
#                              class_names=cancer.target_names,
#                              filled=True,
#                              rounded=True,
#                              special_characters=True)

#graph = pydotplus.graph_from_dot_data(dot_data)
#Image(graph.create_png())

#from sklearn.tree import DecisionTreeClassifier
#tree = DecisionTreeClassifier().fit(X_train,y_train)
#print("Важности признаков:\n{}".format(tree.feature_importances_))


#def plot_feature_cancer(model):
#    n_features = cancer.data.shape[1]
#    plt.barh(range(n_features), model.feature_importances_,align='center')
#    plt.yticks(np.arange(n_features),cancer.feature_names)
#    plt.xlabel("Важность признака")
#    plt.ylabel("Признак")
#    plt.show()

#plot_feature_cancer(tree)

#tree = mglearn.plots.plot_tree_not_monotone()
#plt.show()

#from IPython.display import display
#display(tree)

#import pandas as pd
#ram_prices = pd.read_csv("/home/vladislav/ram_price.csv")
#plt.semilogy(ram_prices.date,ram_prices.price)
#plt.xlabel("Год")
#plt.ylabel("Цена$/Мбайт")
#plt.show()


#from sklearn.tree import DecisionTreeRegressor
#data_train = ram_prices[ram_prices.date<2000]
#data_test = ram_prices[ram_prices.date>=2000]

#y_train = np.log(data_train.price)
#X_train = data_train.date[:,np.newaxis]

#print("X:\n{}".format(X_train))
#print("y:\n{}".format(y_train))

#tree = DecisionTreeRegressor().fit(X_train,y_train)


#from sklearn.linear_model import LinearRegression
#linear_reg = LinearRegression().fit(X_train,y_train)

#X_all = ram_prices.date[:,np.newaxis]

#pred_tree = tree.predict(X_all)
#pred_lr = linear_reg.predict(X_all)

#price_tree = np.exp(pred_tree)
#price_lr = np.exp(pred_lr)

#plt.semilogy(data_train.date,data_train.price,label="Обучающие данные")
#plt.semilogy(data_test.date,data_test.price,label="Тестовые данные")
#plt.semilogy(ram_prices.date,price_tree,label="Прогнозы дерева")
#plt.semilogy(ram_prices.date,price_lr,label="Прогнозы линейной регрессии")
#plt.legend()
#plt.show()



#LAB 9

#import sklearn
#import mglearn
#import matplotlib.pyplot as plt
#import numpy as np
#from sklearn.ensemble import RandomForestClassifier
#from sklearn.datasets import make_moons

#X, y = make_moons(n_samples=100, noise=0.25, random_state=3)

#from sklearn.model_selection import train_test_split

#X_train, X_test, y_train, y_test = train_test_split(X, y, stratify=y, random_state=42)
#forest = RandomForestClassifier(n_estimators=5, random_state=2)
#forest.fit(X_train, y_train)

#fig, axes = plt.subplots(2, 3, figsize=(20, 10))
#for i, (ax, tree) in enumerate(zip(axes.ravel(), forest.estimators_)):
#    ax.set_title("Дерево {}".format(i))
#    mglearn.plots.plot_tree_partition(X_train, y_train, tree, ax=ax)
#    mglearn.plots.plot_2d_separator(forest, X_train, fill=True, ax=axes[-1, -1], alpha=.4)
#axes[-1, -1].set_title("Случайный лес")
#mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train)
#plt.show()

#from sklearn.datasets import load_breast_cancer
#
#cancer = load_breast_cancer()
#X_train, X_test, y_train, y_test = train_test_split(cancer.data, cancer.target, random_state=0)
#forest = RandomForestClassifier(n_estimators=1000, random_state=0)
#forest.fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.3f}".format(forest.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(forest.score(X_test, y_test)))
#
#def plot_feature_importances_cancer(model):
#    n_features = cancer.data.shape[1]
#    plt.barh(range(n_features), model.feature_importances_, align='center')
#    plt.yticks(np.arange(n_features), cancer.feature_names)
#    plt.xlabel("Важность признака")
#    plt.ylabel("Признак")
#    plt.show()

#plot_feature_importances_cancer(forest)

#from sklearn.ensemble import GradientBoostingClassifier

#X_train, X_test, y_train, y_test = train_test_split( cancer.data,cancer.target, random_state=0)

#gbrt = GradientBoostingClassifier(random_state=0)
#gbrt.fit(X_train, y_train)
#print("Правильность на обучающем наборе: {:.3f}".format(gbrt.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(gbrt.score(X_test, y_test)))

#gbrt = GradientBoostingClassifier(random_state=0, max_depth=1)
#gbrt.fit(X_train, y_train)

#print("Правильность на обучающем наборе: {:.3f}".format(gbrt.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(gbrt.score(X_test, y_test)))
#gbrt = GradientBoostingClassifier(random_state=0,learning_rate=0.01)
#gbrt.fit(X_train, y_train)

#print("Правильность на обучающем наборе: {:.3f}".format(gbrt.score(X_train, y_train)))
#print("Правильность на тестовом наборе: {:.3f}".format(gbrt.score(X_test, y_test)))

#gbrt = GradientBoostingClassifier(random_state=0, max_depth=1)
#gbrt.fit(X_train, y_train)

#def plot_feature_importances_cancer(model):
#    n_features = cancer.data.shape[1]
#    plt.barh(range(n_features), model.feature_importances_, align='center')
#    plt.yticks(np.arange(n_features), cancer.feature_names)
#    plt.xlabel("Важность признака")
#    plt.ylabel("Признак")
#    plt.show()
#plot_feature_importances_cancer(gbrt)


#LAB 10

import mglearn
import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
from mpl_toolkits.mplot3d import Axes3D, axes3d
from sklearn.svm import LinearSVC, SVC
from sklearn.datasets import load_breast_cancer

X, y = make_blobs(centers=4, random_state=8)
y = y % 2

mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
plt.xlabel("Признак 0")
plt.ylabel("Признак 1")
plt.show()


linear_svm = LinearSVC().fit(X, y)

mglearn.plots.plot_2d_separator(linear_svm, X)
mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
plt.xlabel("Признак 0")
plt.ylabel("Признак 1")
plt.show()

X_new = np.hstack([X, X[:, 1:] ** 2])


figure = plt.figure()
ax = Axes3D(figure, elev=-152, azim=-26)
mask = y == 0

ax.scatter(X_new[mask, 0], X_new[mask, 1], X_new[mask, 2], c='b', cmap=mglearn.cm2, s=60)
ax.scatter(X_new[~mask, 0], X_new[~mask, 1],X_new[~mask, 2], c='r', marker='^', cmap=mglearn.cm2, s=60)
ax.set_xlabel("признак0")
ax.set_ylabel("признак1")
ax.set_zlabel("признак1 ** 2")
plt.show()

linear_svm_3d = LinearSVC().fit(X_new, y)
coef, intercept = linear_svm_3d.coef_.ravel(), linear_svm_3d.intercept_
figure = plt.figure()

ax = Axes3D(figure, elev=-152, azim=-26)

xx = np.linspace(X_new[:, 0].min() -2, X_new[:, 0].max() + 2, 50)
yy = np.linspace(X_new[:, 1].min() -2, X_new[:, 1].max() + 2, 50)

XX, YY = np.meshgrid(xx, yy)
ZZ = (coef[0] * XX + coef[1] * YY + intercept) / -coef[2]

ax.plot_surface(XX, YY, ZZ, rstride=8, cstride=8, alpha=0.3)
ax.scatter(X_new[mask, 0], X_new[mask, 1], X_new[mask, 2], c='b', cmap=mglearn.cm2, s=60)
ax.scatter(X_new[~mask, 0], X_new[~mask, 1], X_new[~mask, 2], c='r', marker='^', cmap=mglearn.cm2, s=60)

ax.set_xlabel("признак0")
ax.set_ylabel("признак1")
ax.set_zlabel("признак1 ** 2")
plt.show()

ZZ = YY ** 2
dec = linear_svm_3d.decision_function(np.c_[XX.ravel(), YY.ravel(), ZZ.ravel()])
plt.contourf(XX, YY, dec.reshape(XX.shape), levels=[dec.min(), 0, dec.max()],cmap=mglearn.cm2, alpha=0.5)

mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
plt.xlabel("Признак 0")
plt.ylabel("Признак 1")
plt.show()

X, y = mglearn.tools.make_handcrafted_dataset()
svm = SVC(kernel='rbf', C=10, gamma=0.1).fit(X, y)

mglearn.plots.plot_2d_separator(svm, X, eps=.5)
mglearn.discrete_scatter(X[:, 0], X[:, 1], y)

sv = svm.support_vectors_
sv_labels = svm.dual_coef_.ravel() > 0

mglearn.discrete_scatter(sv[:, 0], sv[:, 1], sv_labels, s=15, markeredgewidth=3)
plt.xlabel("Признак 0")
plt.ylabel("Признак 1")
plt.show()

fig, axes = plt.subplots(3, 3, figsize=(15, 10))

for ax, C in zip(axes, [-1, 0, 3]):
    for a, gamma in zip(ax, range(-1, 2)):
        mglearn.plots.plot_svm(log_C=C, log_gamma=gamma, ax=a)

axes[0, 0].legend(["class 0", "class 1", "sv class 0", "sv class 1"], ncol=4, loc=(.9, 1.2))
plt.show()


cancer = load_breast_cancer()
X_train, X_test, y_train, y_test = train_test_split( cancer.data, cancer.target, random_state=0)
svc = SVC()
svc.fit(X_train, y_train)

print("Правильность на обучающем наборе: {:.2f}".format(svc.score(X_train, y_train)))
print("Правильность на тестовом наборе: {:.2f}".format(svc.score(X_test, y_test)))
plt.show()

plt.plot(X_train.min(axis=0), 'o', label="min")
plt.plot(X_train.max(axis=0), '^', label="max")
plt.legend(loc=4)
plt.xlabel("Индекс признака")
plt.ylabel("Величина признака")
plt.yscale("log")
plt.show()

min_on_training = X_train.min(axis=0)
range_on_training = (X_train - min_on_training).max(axis=0)
X_train_scaled = (X_train - min_on_training) / range_on_training
print("Минимальное значение для каждого признака\n{}".format(X_train_scaled.min(axis=0)))
print("Максимальное значение для каждого признака\n {}".format(X_train_scaled.max(axis=0)))

X_test_scaled = (X_test - min_on_training) / range_on_training
svc = SVC()
svc.fit(X_train_scaled, y_train)
print("Правильность на обучающем наборе: {:.3f}".format( svc.score(X_train_scaled, y_train)))
print("Правильность на тестовом наборе: {:.3f}".format(svc.score(X_test_scaled, y_test)))

svc = SVC(C=1000)
svc.fit(X_train_scaled, y_train)
print("Правильность на обучающем наборе: {:.3f}".format( svc.score(X_train_scaled, y_train)))
print("Правильность на тестовом наборе: {:.3f}".format(svc.score(X_test_scaled, y_test)))


#LAB 11
#
# import mglearn
# import sklearn
# import matplotlib.pyplot as plt
# import numpy as np
# import graphviz
# from IPython.display import display
# from sklearn.model_selection import train_test_split
# from sklearn.neural_network import MLPClassifier
# from sklearn.datasets import make_moons
#
# display(mglearn.plots.plot_single_hidden_layer_graph())
# line = np.linspace(-3, 3, 100)
#
# plt.plot(line, np.tanh(line), label="tanh")
# plt.plot(line, np.maximum(line, 0), label="relu")
# plt.legend(loc="best")
# plt.xlabel("x")
# plt.ylabel("relu(x), tanh(x)")
# plt.show()
#
# mglearn.plots.plot_two_hidden_layer_graph()
# plt.show()
#
# X, y = make_moons(n_samples=100, noise=0.25, random_state=3)
# X_train, X_test, y_train, y_test = train_test_split(X, y, stratify=y, random_state=42)
# mlp = MLPClassifier(solver='lbfgs', random_state=0).fit(X_train, y_train)
# mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3)
# mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train)
#
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# mlp = MLPClassifier(solver='lbfgs', random_state=0, hidden_layer_sizes=[10])
# mlp.fit(X_train, y_train)
#
# mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3)
# mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train)
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# mlp = MLPClassifier(solver='lbfgs', random_state=0, hidden_layer_sizes=[10, 10])
# mlp.fit(X_train, y_train)
#
# mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3)
# mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train)
#
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# mlp = MLPClassifier(solver='lbfgs', activation='tanh',random_state=0, hidden_layer_sizes=[10, 10])
# mlp.fit(X_train, y_train)
#
# mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3)
# mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train)
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# fig, axes = plt.subplots(2, 4, figsize=(20, 8))
#
# for axx, n_hidden_nodes in zip(axes, [10, 100]):
#     for ax, alpha in zip(axx, [0.0001, 0.01, 0.1, 1]):
#         mlp = MLPClassifier(solver='lbfgs', random_state=0,hidden_layer_sizes=[n_hidden_nodes, n_hidden_nodes], alpha=alpha)
#         mlp.fit(X_train, y_train)
#         mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3, ax=ax)
#         mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train, ax=ax)
#         ax.set_title("n_hidden=[{}, {}]\nalpha={:.4f}".format(n_hidden_nodes, n_hidden_nodes, alpha))
# plt.show()
#
# fig, axes = plt.subplots(2, 4, figsize=(20, 8))
#
# for i, ax in enumerate(axes.ravel()):
#     mlp = MLPClassifier(solver='lbfgs', random_state=i, hidden_layer_sizes=[100, 100])
#     mlp.fit(X_train, y_train)
#     mglearn.plots.plot_2d_separator(mlp, X_train, fill=True, alpha=.3, ax=ax)
#     mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train, ax=ax)
# plt.show()
#
# from sklearn.datasets import load_breast_cancer
# cancer = load_breast_cancer()
#
# print("Максимальные значения характеристик:\n{}".format(cancer.data.max(axis=0)))
# X_train, X_test, y_train, y_test = train_test_split( cancer.data, cancer.target, random_state=0)
#
# mlp = MLPClassifier(random_state=42)
# mlp.fit(X_train, y_train)
# print("Правильность на обучающем наборе: {:.2f}".format(mlp.score(X_train, y_train)))
# print("Правильности на тестовом наборе: {:.2f}".format(mlp.score(X_test, y_test)))
# min_on_training = X_train.min(axis=0)
# range_on_training = (X_train -min_on_training).max(axis=0)
# X_train_scaled = (X_train -min_on_training) / range_on_training
#
# mean_on_train = X_train.mean(axis=0)
# std_on_train = X_train.std(axis=0)
# X_test_scaled = (X_test -mean_on_train) / std_on_train
# mlp = MLPClassifier(random_state=0)
#
# mlp.fit(X_train_scaled, y_train)
# print("Правильность на обучающем наборе: {:.3f}".format( mlp.score(X_train_scaled, y_train)))
# print("Правильность на тестовом наборе: {:.3f}".format(mlp.score(X_test_scaled, y_test)))
# mlp = MLPClassifier(max_iter=1000, random_state=0)
# mlp.fit(X_train_scaled, y_train)
# print("Правильность на обучающем наборе: {:.3f}".format( mlp.score(X_train_scaled, y_train)))
# print("Правильность на тестовом наборе: {:.3f}".format(mlp.score(X_test_scaled, y_test)))
# mlp = MLPClassifier(max_iter=1000, alpha=1, random_state=0)
#
# mlp.fit(X_train_scaled, y_train)
# print("Правильность на обучающем наборе: {:.3f}".format( mlp.score(X_train_scaled, y_train)))
# print("Правильность на тестовом наборе: {:.3f}".format(mlp.score(X_test_scaled, y_test)))
# plt.figure(figsize=(20, 5))
# plt.imshow(mlp.coefs_[0], interpolation='none', cmap='viridis')
# plt.yticks(range(30), cancer.feature_names)
# plt.xlabel("Столбцы матрицы весов")
# plt.ylabel("Входная характеристика")
# plt.colorbar()
# plt.show()


# #LAB 12
#
# import mglearn
# import sklearn
# import matplotlib.pyplot as plt
# import numpy as np
# from sklearn.ensemble import GradientBoostingClassifier
# from sklearn.datasets import make_blobs, make_circles
# from sklearn.model_selection import train_test_split
# from sklearn.datasets import load_iris
# from sklearn.linear_model import LogisticRegression
#
# X, y = make_circles(noise=0.25, factor=0.5, random_state=1)
# y_named = np.array(["blue", "red"])[y]
# X_train, X_test, y_train_named, y_test_named, y_train, y_test = train_test_split(X, y_named, y, random_state=0)
#
# gbrt = GradientBoostingClassifier(random_state=0)
# gbrt.fit(X_train, y_train_named)
# print("Форма массива X_test: {}".format(X_test.shape))
# print("Форма решающей функции: {}".format(gbrt.decision_function(X_test).shape))
# print("Решающая функция:\n{}".format(gbrt.decision_function(X_test)[:6]))
# print("Решающая функция спорогом отсечения:\n{}".format( gbrt.decision_function(X_test) > 0))
# print("Прогнозы:\n{}".format(gbrt.predict(X_test)))
# greater_zero = (gbrt.decision_function(X_test) > 0).astype(int)
#
# pred = gbrt.classes_[greater_zero]
# print("pred идентичен прогнозам: {}".format(np.all(pred == gbrt.predict(X_test))))
# decision_function = gbrt.decision_function(X_test)
# print("Решающая функция минимум: {:.2f} максимум: {:.2f}".format( np.min(decision_function), np.max(decision_function)))
# fig, axes = plt.subplots(1, 2, figsize=(13, 5))
# mglearn.tools.plot_2d_separator(gbrt, X, ax=axes[0], alpha=.4, fill=True, cm=mglearn.cm2)
# scores_image = mglearn.tools.plot_2d_scores(gbrt, X, ax=axes[1],alpha=.4, cm=mglearn.ReBl)
# for ax in axes:
#     mglearn.discrete_scatter(X_test[:, 0], X_test[:, 1], y_test,markers='^', ax=ax)
#     mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train, markers='o', ax=ax)
#     ax.set_xlabel("Характеристика 0")
#     ax.set_ylabel("Характеристика 1")
#     cbar = plt.colorbar(scores_image, ax=axes.tolist())
#     axes[0].legend(["Тесткласс 0", "Тесткласс 1", "Обучениекласс 0", "Обучениекласс 1"], ncol=4, loc=(.1, 1.1))
# plt.show()
# print("Форма вероятностей: {}".format(gbrt.predict_proba(X_test).shape))
# print("Спрогнозированные вероятности:\n{}".format(gbrt.predict_proba(X_test[:6])))
#
# fig, axes = plt.subplots(1, 2, figsize=(13, 5))
# mglearn.tools.plot_2d_separator(gbrt, X, ax=axes[0], alpha=.4, fill=True, cm=mglearn.cm2)
# scores_image = mglearn.tools.plot_2d_scores(gbrt, X, ax=axes[1], alpha=.5, cm=mglearn.ReBl, function='predict_proba')
#
# for ax in axes:
#     mglearn.discrete_scatter(X_test[:, 0], X_test[:, 1], y_test,markers='^', ax=ax)
#     mglearn.discrete_scatter(X_train[:, 0], X_train[:, 1], y_train, markers='o', ax=ax)
#     ax.set_xlabel("Характеристика 0")
#     ax.set_ylabel("Характеристика 1")
# cbar = plt.colorbar(scores_image, ax=axes.tolist())
# axes[0].legend(["Тест класс 0", "Тест класс 1", "Обуч класс 0", "Обуч класс 1"], ncol=4, loc=(.1, 1.1))
# plt.show()
#
# iris = load_iris()
#
# X_train, X_test, y_train, y_test = train_test_split( iris.data, iris.target, random_state=42)
# gbrt = GradientBoostingClassifier(learning_rate=0.01, random_state=0)
# gbrt.fit(X_train, y_train)
#
# print("Форма решающей функции: {}".format(gbrt.decision_function(X_test).shape))
# print("Решающая функция:\n{}".format(gbrt.decision_function(X_test)[:6, :]))
# print("Arg max решающей функции:\n{}".format(np.argmax(gbrt.decision_function(X_test), axis=1)))
# print("Прогнозы:\n{}".format(gbrt.predict(X_test)))
# print("Спрогнозированные вероятности:\n{}".format(gbrt.predict_proba(X_test)[:6]))
# print("Суммы: {}".format(gbrt.predict_proba(X_test)[:6].sum(axis=1)))
# print("Arg max спрогнозированных вероятностей:\n{}".format( np.argmax(gbrt.predict_proba(X_test), axis=1)))
# print("Прогнозы:\n{}".format(gbrt.predict(X_test)))
#
# logreg = LogisticRegression()
# named_target = iris.target_names[y_train]
# logreg.fit(X_train, named_target)
# print("уникальные классы в обучающем наборе: {}".format(logreg.classes_))
# print("прогнозы: {}".format(logreg.predict(X_test)[:10]))
# argmax_dec_func = np.argmax(logreg.decision_function(X_test), axis=1)
# print("arg max решающей функции: {}".format(argmax_dec_func[:10]))
# print("arg max объединенный с классами_: {}".format(logreg.classes_[argmax_dec_func][:10]))

# #LAB 13
#
# import mglearn
# import sklearn
# import matplotlib.pyplot as plt
# from sklearn.preprocessing import StandardScaler
# from sklearn.datasets import load_breast_cancer
# from sklearn.model_selection import train_test_split
# from sklearn.preprocessing import MinMaxScaler
# from sklearn.datasets import make_blobs
# from sklearn.preprocessing import StandardScaler
# from sklearn.svm import SVC
#
#
# "In[2]:"
# mglearn.plots.plot_scaling()
# plt.show()
#
#
# cancer=load_breast_cancer()
# X_train,X_test,y_train,y_test = train_test_split(cancer.data,cancer.target,random_state=1)
# print(X_train.shape)
# print(X_test.shape)
#
# "In[4]:"
# scaler=MinMaxScaler()
#
# "In[5]:"
# scaler.fit(X_train)
#
# "In[6]:"
#
# min_on_training = X_train.min(axis=0)
# range_on_training=(X_train-min_on_training).max(axis=0)
# X_train_scaled=(X_train-min_on_training) / range_on_training
# print("форма преобразованного массива:{}".format(X_train_scaled.shape))
# print("min значение признака до масштабирования:\n{}".format(X_train.min(axis=0)))
# print("max значение признака до масштабирования:\n{}".format(X_train.max(axis=0)))
# print("min значение признака после масштабирования:\n{}".format(X_train_scaled.min(axis=0)))
# print("max значение признака после масштабирования:\n{}".format(X_train_scaled.max(axis=0)))
#
# "In[7]:"
# X_test_scaled=(X_test-min_on_training) / range_on_training
# print("min значение признака после масштабирования:\n{}".format(X_test_scaled.min(axis=0)))
# print("max значение признака после масштабирования:\n{}".format(X_test_scaled.max(axis=0)))
#
# "In[8]:"
# X,_ = make_blobs(n_samples=50,centers=5,random_state=4,cluster_std=2)
#
# X_train, X_test=train_test_split(X,random_state=5,test_size=.1)
# fig,axes = plt.subplots(1,3,figsize=(13,4))
# axes[0].scatter(X_train[:,0],X_train[:,1],c=mglearn.cm2(0),label="Обучающий набор",s=60)
# axes[0].scatter(X_test[:,0],X_test[:,1],marker='^',c=mglearn.cm2(1),label="Тестовый набор",s=60)
# axes[0].legend(loc='upper left')
# axes[0].set_title("Исходные данные")
#
# scaler=MinMaxScaler()
# scaler.fit(X_train)
# X_train_scaled = scaler.transform(X_train)
# X_test_scaled = scaler.transform(X_test)
# axes[1].scatter(X_train_scaled[:,0],X_train_scaled[:,1],c=mglearn.cm2(0),label="Обучающий набор",s=60)
# axes[1].scatter(X_test_scaled[:,0],X_test_scaled[:,1],marker='^',c=mglearn.cm2(1),label="Тестовый набор",s=60)
# axes[1].set_title("Масштабированные данные")
#
# test_scaler=MinMaxScaler()
# test_scaler.fit(X_test)
# X_test_scaled_badly=test_scaler.transform(X_test)
# axes[2].scatter(X_train_scaled[:,0],X_train_scaled[:,1],c=mglearn.cm2(0),label="Обучающий набор",s=60)
# axes[2].scatter(X_test_scaled_badly[:,0],X_test_scaled_badly[:,1],marker='^',c=mglearn.cm2(1),label="Тестовый набор",s=60)
# axes[2].set_title("Неправильно масштабированные данные")
# for ax in axes:
#     ax.set_xlabel("Признак 0")
#     ax.set_ylabel("Признак 1")
# plt.show()
#
# "In[9]:"
# scaler=StandardScaler()
# X_scaled=scaler.fit(X).transform(X)
# X_scaled_d=scaler.fit_transform(X)
#
# "In[10]:"
# X_train,X_test,y_train,y_test=train_test_split(cancer.data,cancer.target,random_state=0)
# svm=SVC(C=100)
# svm.fit(X_train,y_train)
#
# print("Правильность на тестовом наборе:{:.2f}".format(svm.score(X_test,y_test)))
# "In[11]:"
#
# scaler=MinMaxScaler()
# scaler.fit(X_train)
# X_train_scaled=scaler.transform(X_train)
# X_test_scaled=scaler.transform(X_test)
# svm.fit(X_train_scaled,y_train)
# print("Правильность на масштабированном тестовом наборе:{:.2f}".format(svm.score(X_test_scaled,y_test)))
#
# "In[12]:"
#
# scaler=StandardScaler()
# scaler.fit(X_train)
# X_train_scaled=scaler.transform(X_train)
# X_test_scaled=scaler.transform(X_test)
# svm.fit(X_train_scaled,y_train)
# print("Правильность SVM на тестовом наборе:{:.2f}".format(svm.score(X_test_scaled,y_test)))


# #LAB 14
#
# import mglearn
# import sklearn
# import matplotlib.pyplot as plt
# import numpy as np
# from sklearn.model_selection import train_test_split
# from sklearn.decomposition import PCA
# from sklearn.datasets import load_breast_cancer
# from sklearn.datasets import fetch_lfw_people
# from sklearn.neighbors import KNeighborsClassifier
# from sklearn.preprocessing import StandardScaler
#
# mglearn.plots.plot_pca_illustration()
# plt.show()
#
# cancer = load_breast_cancer()
# fig, axes = plt.subplots(15, 2,figsize=(10, 20))
# malignant = cancer.data[cancer.target == 0]
# benign = cancer.data[cancer.target == 1]
#
# ax = axes.ravel()
# for i in range(30):
#     _, bins = np.histogram(cancer.data[:, i], bins=50)
#     ax[i].hist(malignant[:,i], bins=bins, color=mglearn.cm3(0), alpha=.5)
#     ax[i].hist(benign[:, i], bins=bins, color=mglearn.cm3(2), alpha=.5)
#     ax[i].set_title(cancer.feature_names[i])
#     ax[i].set_yticks(())
#     ax[0].set_xlabel("Значение признака")
#     ax[0].set_ylabel("Частота")
# ax[0].legend(["доброкачественная", "злокачественная"], loc="best")
# fig.tight_layout()
# plt.show()
#
# cancer = load_breast_cancer()
#
# scaler = StandardScaler()
# scaler.fit(cancer.data)
# X_scaled = scaler.transform(cancer.data)
#
# #оставляем первые две главные компоненты
# pca = PCA(n_components=2)
# #подгоняем модель PCA на наборе данных breastcancer
# pca.fit(X_scaled)
# #преобразуем данные к первым двум главным компонентам
#
# X_pca = pca.transform(X_scaled)
# print("Форма исходного массива:{}".format(str(X_scaled.shape)))
# print("Форма массива после сокращения размерности:{}".format(str(X_pca.shape)))
#
# #строим график первых двух главных компонент,классы выделены цветом
# plt.figure(figsize=(8,8))
# mglearn.discrete_scatter(X_pca[:, 0],X_pca[:, 1],cancer.target)
# plt.legend(cancer.target_names, loc="best")
# plt.gca().set_aspect("equal")
# plt.xlabel("Первая главная компонента")
# plt.ylabel("Вторая главная компонента")
# plt.show()
#
#
# print("форма главных компонент:{}".format(pca.components_.shape))
# print("компоненты PCA:\n{}".format(pca.components_))
# plt.matshow(pca.components_,cmap='viridis')
# plt.yticks([0,1],["Первая компонента", "Вторая компонента"])
# plt.colorbar()
# plt.xticks(range(len(cancer.feature_names)), cancer.feature_names, rotation=60, ha='left')
# plt.xlabel("Характеристика")
# plt.ylabel("Главные компоненты")
# plt.show()
#
# # conda install -c anaconda openssl
#
# people=fetch_lfw_people(min_faces_per_person=20,resize=0.7)
# image_shape = people.images[0].shape
# fix, axes = plt.subplots(2, 5, figsize=(15, 8), subplot_kw={'xticks': (), 'yticks': ()})
#
# for target,image,ax in zip(people.target,people.images,axes.ravel()):
#     ax.imshow(image)
#     ax.set_title(people.target_names[target])
# plt.show()
# print("форма массива из ображений лиц:{}".format(people.images.shape))
# print("количество классов:{}".format(len(people.target_names)))
#
# #вычисляем частоту встречаемости каждого ответа
# counts = np.bincount(people.target)
# #печатаем частоты рядом с ответами
#
# for i, (count,name) in enumerate(zip(counts,people.target_names)):
#     print("{0:25}{1:3}".format(name, count),end='')
#     if (i + 1) % 3 == 0:
#         print()
#
# mask=np.zeros(people.target.shape,dtype=np.bool)
# for target in np.unique(people.target):
#     mask[np.where(people.target == target)[0][:50]] = 1
#
# X_people = people.data[mask]
# y_people = people.target[mask]
#
# #для получения большей стабильности масштабируем шкалу оттенков серого так, чтобы значения были в диапазоне от 0 до 1 вместо использования шкалы значений от 0 до 255
# X_people = X_people / 255.
#
#
# #разбиваем данные на обучающий и тестовый наборы
# X_train, X_test, y_train, y_test = train_test_split(X_people, y_people, stratify=y_people, random_state=0)
#
# #строим KNeighborsClassifier с одним соседом
# knn = KNeighborsClassifier(n_neighbors=1)
# knn.fit(X_train,y_train)
# print("Правильность на тестовом наборе для 1-nn:{:.2f}".format(knn.score(X_test,y_test)))
#
# mglearn.plots.plot_pca_whitening()
# plt.show()
#
# pca = PCA(n_components=100, whiten=True, random_state=0).fit(X_train)
# X_train_pca = pca.transform(X_train)
# X_test_pca = pca.transform(X_test)
#
# print("обучающие данные после PCA:{}".format(X_train_pca.shape))
# knn = KNeighborsClassifier(n_neighbors=1)
# knn.fit(X_train_pca, y_train)
# print("Правильность на тестовом наборе:{:.2f}".format(knn.score(X_test_pca,y_test)))
# print("форма pca.components_:{}".format(pca.components_.shape))

#fix, axes = plt.subplots(3,5,15=(12,figsize),
#subplot_kw={'xticks':(),'yticks':()})
#for i,(component,ax) in enumerate(zip(pca.components_,axes.ravel())):
#ax.imshow(component.reshape(image_shape),cmap='viridis')
#ax.set_title("{}.component".format((i+1))
#plt.show()

# mglearn.plots.plot_pca_faces(X_train, X_test, image_shape)
# plt.show()
#
# mglearn.discrete_scatter(X_train_pca[:, 0], X_train_pca[:, 1], y_train)
# plt.xlabel("Первая главная компонента")
# plt.ylabel("Вторая главная компонента")
# plt.show()

# #LAB 15
#
# import mglearn
# import matplotlib.pyplot as plt
# import numpy as np
# from sklearn.datasets import load_digits, load_breast_cancer, fetch_lfw_people
# from sklearn.decomposition import NMF
# from sklearn.manifold import TSNE
# from sklearn.model_selection import train_test_split
# from sklearn.decomposition import PCA
#
# cancer = load_breast_cancer()
# mglearn.plots.plot_nmf_illustration()
# plt.show()
#
# people = fetch_lfw_people(min_faces_per_person=5, resize=1.0)
# image_shape = people.images[0].shape
#
# #mglearn.plots.plot_nmf_faces(X_train,X_test,image_shape)
# #plt.show()
#
# X_train, X_test, y_train, y_test = train_test_split(cancer.data, cancer.target, random_state=0)
#
# nmf = NMF(n_components=15, random_state=0)
# nmf.fit(X_train)
# X_train_nmf = nmf.transform(X_train)
# X_test_nmf = nmf.transform(X_test)
# fix, axes = plt.subplots(3, 5, figsize=(15, 12), subplot_kw={'xticks': (), 'yticks': ()})
#
# for i, (component,ax) in enumerate(zip(nmf.components_, axes.ravel())):
#     ax.imshow(component.reshape(image_shape, order='F'))
#     ax.set_title("{}.component".format(i))
# plt.show()
#
# compn = 3
# #сортируем по 3-й компоненте, выводим первые 10 изображений
# inds = np.argsort(X_train_nmf[:, compn])[::-1]
# fig, axes = plt.subplots(2, 5, figsize=(15, 8), subplot_kw={'xticks': (), 'yticks': ()})
#
# for i, (ind,ax) in enumerate(zip(inds,axes.ravel())):
#     ax.imshow(X_train[ind].reshape(image_shape))
# plt.show()
#
# compn = 7
# #сортируем по 7-й компоненте,выводим первые 10 изображений
# inds = np.argsort(X_train_nmf[:, compn])[::-1]
# fig, axes = plt.subplots(2, 5, figsize=(15, 8), subplot_kw={'xticks': (), 'yticks': ()})
#
# for i, (ind, ax) in enumerate(zip(inds,axes.ravel())):
#     ax.imshow(X_train[ind].reshape(image_shape))
# plt.show()
#
# S = mglearn.datasets.make_signals()
# plt.figure(figsize=(6, 1))
#
# plt.plot(S, '-')
# plt.xlabel("Время")
# plt.ylabel("Сигнал")
# plt.show()
#
# A = np.random.RandomState(0).uniform(size=(100, 3))
# X = np.dot(S, A.T)
#
# print("Форма измерений:{}".format(X.shape))
#
# nmf = NMF(n_components=3, random_state=42)
# S_ = nmf.fit_transform(X)
# print("Форма восстановленного сигнала:{}".format(S_.shape))
#
# pca = PCA(n_components=3)
# H = pca.fit_transform(X)
# models = [X, S, S_, H]
#
# names = ['Наблюдения(первые три измерения)', 'Фактические источники', 'Сигналы, восстановленные NMF', 'Сигналы, восстановленные PCA']
#
# fig, axes = plt.subplots(4, figsize=(8, 4), gridspec_kw={'hspace': .5}, subplot_kw={'xticks': (), 'yticks': ()})
#
# for model, name, ax in zip(models, names, axes):
#     ax.set_title(name)
#     ax.plot(model[:, :3], '-')
# plt.show()
#
# digits = load_digits()
#
# fig, axes = plt.subplots(2, 5, figsize=(10, 5), subplot_kw={'xticks': (), 'yticks': ()})
#
# for ax, img in zip(axes.ravel(), digits.images):
#     ax.imshow(img)
# plt.show()
#
# #строим модель PCA
# pca = PCA(n_components=2)
# pca.fit(digits.data)
#
# #преобразуем данные рукописных цифр к первым двум компонентам
# digits_pca = pca.transform(digits.data)
# colors = ["#476A2A", "#7851B8", "#BD3430", "#4A2D4E", "#875525", "#A83683", "#4E655E", "#853541", "#3A3120", "#535D8E"]
#
# plt.figure(figsize=(10,10))
# plt.xlim(digits_pca[:, 0].min(), digits_pca[:, 0].max())
# plt.ylim(digits_pca[:, 1].min(), digits_pca[:, 1].max())
# for i in range(len(digits.data)):
#     #строим график,где цифры представлены символами вместо точек
#     plt.text(digits_pca[i, 0],digits_pca[i, 1], str(digits.target[i]), color=colors[digits.target[i]], fontdict={'weight': 'bold', 'size': 9})
# plt.xlabel("Первая главная компонента")
# plt.ylabel("Вторая главная компонента")
# plt.show()
#
# tsne = TSNE(random_state=42)
# #используем метод fit_transfor mвместо fit, т.к. класс TSNE не использует метод transform
# digits_tsne = tsne.fit_transform(digits.data)
# plt.figure(figsize=(10, 10))
# plt.xlim(digits_tsne[:, 0].min(),digits_tsne[:, 0].max() + 1)
# plt.ylim(digits_tsne[:, 1].min(),digits_tsne[:, 1].max() + 1)
# for i in range(len(digits.data)):
#     #строим график,где цифры представлены символами вместо точек
#     plt.text(digits_tsne[i, 0], digits_tsne[i, 1], str(digits.target[i]), color=colors[digits.target[i]], fontdict={'weight': 'bold', 'size': 9})
# plt.xlabel("t-SNE признак 0")
# plt.xlabel("t-SNE признак 1")
# plt.show()

# #LAB 16
#
# import mglearn
# import matplotlib.pyplot as plt
# import numpy as np
# from sklearn.datasets import make_blobs
# from sklearn.cluster import KMeans
# from sklearn.datasets import make_moons
#
# mglearn.plots.plot_kmeans_algorithm()
# plt.show()
#
# mglearn.plots.plot_kmeans_boundaries()
# plt.show()
#
# # генерируем синтетические двумерные данные
# X, y = make_blobs(random_state=1)
# kmeans = KMeans(n_clusters=3)
# kmeans.fit(X)
#
# #строим модель кластеризации
# print("Принадлежность ккластерам:\n{}".format(kmeans.labels_))
# mglearn.discrete_scatter(X[:, 0],X[:, 1],kmeans.labels_, markers='o')
# mglearn.discrete_scatter(kmeans.cluster_centers_[:, 0],kmeans.cluster_centers_[:, 1], [0, 1, 2], markers='^', markeredgewidth=2)
# plt.show()
#
# fig, axes = plt.subplots(1, 2, figsize=(10, 5))
# # использование двух центров кластеров:
# kmeans = KMeans(n_clusters=2)
# kmeans.fit(X)
# assignments = kmeans.labels_
#
# mglearn.discrete_scatter(X[:, 0], X[:, 1], assignments, ax=axes[0])
#
# #использование пяти центров кластеров:
# kmeans=KMeans(n_clusters=5)
# kmeans.fit(X)
# assignments = kmeans.labels_
#
# mglearn.discrete_scatter(X[:, 0], X[:, 1],assignments, ax=axes[1])
# plt.show()
# X_varied, y_varied = make_blobs(n_samples=200,cluster_std=[1.0, 2.5, 0.5], random_state=170)
# y_pred = KMeans(n_clusters=3, random_state=0).fit_predict(X_varied)
# mglearn.discrete_scatter(X_varied[:, 0], X_varied[:, 1], y_pred)
#
# plt.legend(["кластер 0", "кластер 1", "кластер 2"], loc='best')
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# #генерируем случайным образом данные для кластеризации
# X, y = make_blobs(random_state=170, n_samples=600)
# rng = np.random.RandomState(74)
# #преобразуем данные так,чтобы они были вытянуты подиагонали
# transformation = rng.normal(size=(2, 2))
# X = np.dot(X, transformation)
#
# #группируем данные в три кластера
# kmeans = KMeans(n_clusters=3)
# kmeans.fit(X)
# y_pred = kmeans.predict(X)
#
# #строим график принадлежности к кластерам и центров кластеров
# plt.scatter(X[:, 0], X[:, 1], c=y_pred, cmap=mglearn.cm3)
# plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], marker='^', c=[0, 1, 2], s=100, linewidth=2, cmap=mglearn.cm3)
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
# #генерируем синтетические данные two_moons (на этот раз с меньшим количеством шума)
# X, y = make_moons(n_samples=200, noise=0.05, random_state=0)
#
# #группируем данные в два кластера
# kmeans = KMeans(n_clusters=2)
# kmeans.fit(X)
# y_pred = kmeans.predict(X)
#
# #строим график принадлежности к кластерам и центров кластеров
# plt.scatter(X[:, 0], X[:, 1], c=y_pred, cmap=mglearn.cm2, s=60)
# plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], marker='^', c=[mglearn.cm2(0), mglearn.cm2(1)], s=100, linewidth=2)
# plt.xlabel("Признак 0")
# plt.ylabel("Признак 1")
# plt.show()
#
