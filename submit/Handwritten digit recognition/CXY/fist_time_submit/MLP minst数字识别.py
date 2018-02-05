# MLP(Multilayer perceptron)多层感知机-全连接神经网络
# Date：2018/2/4
# MNIST数据集，手写数字识别
# 调用sklearn库
import time
import numpy as np # 科学计算库，使用ndarrary这个对象
from os import listdir # 采用listdir模块，便于访问本地文件
from sklearn.neural_network import MLPClassifier #sklearn导入相关包

# 针对32*32的二值图，将32*32的图片矩阵栈开成一维的
def img2vector(file_name):
    retMat =np.zeros([1024],int)#定义矩阵
    fr = open(file_name)
    lines = fr.readlines()# 读取文件所有行
    for i in range(32) :
        for j in range(32):
            retMat[i*32+j] = lines[i][j]
    return  retMat

#训练数据的加载
def readData(path):
    filelist = listdir(path) # 这一句可以都全路径文件夹下所有文件,返回文件夹下包含文件的名字的列表
    numFiles = len(filelist)#需要读取文件的数目
    dataSet = np.zeros([numFiles,1024],int)
    hwLables= np.zeros([numFiles,10])
    for i in range(numFiles):
        filepath =filelist[i]
        digit = int(filepath.split('_')[0])#把路径通过_分开，并取第一个，为标签
        hwLables[i][digit] = 1.0
        dataSet[i] = img2vector(path+'/'+filepath)
    print(hwLables)

    return dataSet,hwLables

start = time.clock()

# 读取训练数据
train_datas,train_hwLables = readData("E:\\python程序\\MLP手写数字识别sklearn\\training_txt")

learning_rate = 0.01
layer = 100
# 搭建网络

clf = MLPClassifier(hidden_layer_sizes=(layer,),activation="relu",solver="adam",learning_rate_init = learning_rate,max_iter=2000)

# 使用训练数据，根据训练集以及对应标签自动设置MLP的输入输出层
clf.fit(train_datas, train_hwLables)


# 读取测试数据数据
test_datas,test_lables = readData("E:\\python程序\\MLP手写数字识别sklearn\\test_txt")

res = clf.predict(test_datas)#对测试集预测
error_num = 0
num = len(test_datas)

end = time.clock()
for i in range(num) :
    if np.sum(res[i] == test_lables[i]) < 10 :# 说明与真实结果不同
        error_num +=1
print("layer",layer,"learning_rate",learning_rate,"Total num",num,"Wrong num",error_num, "CorretRate",1-float(error_num)/float(num),"RunningTime",end-start )