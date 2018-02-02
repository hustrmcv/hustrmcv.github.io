# 符号函数
import numpy as np
import random
import matplotlib.pyplot as plt


def sign(v):
    if v > 0:
        return 1
    else:
        return -1
'''
def test():
    (weight, bias) = training()
    while True:
        test_data = []
        data = input('enter test data (x1, x2): ')
        if data == 'q': break
        test_data += [int(n) for n in data.split(',')]
        predict = sign(weight[0] * test_data[0] + weight[1] * test_data[1] + bias)
        print("predict ==> %d" % predict)
'''
def training():
    train_data1 = [[1.3921580628585293, 5.769666993554058, 1], [2.499661088313367, 8.396334701243362, 1], [2.4142589928332896, 8.552105679626603, 1], [2.227200004317689, 5.547475513544993, 1], [3.9824887225256154, 7.662672397746207, 1], [1.142393481586386, 4.264603754215791, 1], [2.185447419325291, 4.866232268514939, 1], [2.3786455113712854, 6.007708987001357, 1]]  # 正样本
    train_data2 = [[6.143508481595929, 5.932365979411299, -1], [8.74522012025588, 6.632077766531511, -1], [4.056645130936839, 1.509746572717006, -1], [5.343836074600894, 2.9093735720634992, -1], [4.165590481709283, 2.589084921855357, -1], [4.953291496224722, 4.62487754867853, -1], [5.786745055859802, 1.7382039291757279, -1], [7.301302268070938, 6.649050896117497, -1]]  # 负样本
    train_datas = train_data1 + train_data2  # 样本集
    train_show =np.array(train_datas)
    print(train_datas)
    weight = [0, 0]  # 权重
    bias = 0  # 偏置量
    learning_rate = 0.5  # 学习速率
    train_num = 10000
    # train_num = int(input("train num: "))  # 迭代次数

    for i in range(train_num):
        train = train_datas[ random.randrange(0,12) ]
        x1, x2, y = train
        predict = sign(weight[0] * x1 + weight[1] * x2 + bias)  # 输出
        print("train data: x: (%f, %f) y: %d  ==> predict: %d" % (x1, x2, y, predict))
        if y * predict <= 0:  # 判断误分类点
            weight[0] = weight[0] + learning_rate * y * x1  # 更新权重
            weight[1] = weight[1] + learning_rate * y * x2
            bias = bias + learning_rate * y  # 更新偏置量
            print("update weight and bias: "),
            print(weight[0], weight[1], bias)

    x = np.linspace(1, 9, 50)
    y = -weight[0] / weight[1] * x - bias / weight[1]
    plt.title(train_num)
    plt.plot(x,y)
    plt.scatter(train_show[:,0], train_show[:,1])
    plt.show()
    print("stop training: "),
    print(weight[0], weight[1], bias)

    return weight, bias

training()