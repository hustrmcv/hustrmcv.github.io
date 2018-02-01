import os
import stat
import operator
import random

# 测试函数，把二值图txt读取，依据训练好的预测模型，得出结果
def test():
    weight = []
    weight, bias = training()#train()函数得到每个特征的权值，以及偏置
    w = 0
    while True:

        test_data = []
        data_dir = input("请输入你要判别的32*32的数字图片的路径 ")
        #data_dir = "E:\python程序\感知机0,1图片识别\data\\0_23.txt"
        test_data = img2vector(data_dir)
        for j in range(1024):
            w = w + weight[j] * test_data[j]
        predict = sign(w + bias)  # 过激活函数激活
        print(predict)

        if predict == -1:
            print("这个数是0")
        else:
            print("这个数是1")

#得到文件名函数，在文件夹批量处理时得到路径名，自己的方法
#想知道更简洁的批量处理文件夹中txt文件的方法

def Getfilename( file_name ):
    files_list =[]
    for root, dirs, files in os.walk(file_name):
        files_list = files_list + files
        #print(files)#测试文件名
    return files_list
#定义符号函数
def sign(v):
    if v > 0:
        return 1
    else:
        return -1
#把32*32的二值图,读取为1 * 1025的lst
def img2vector(filename):
    lst = []
    fr = open(filename)
    for i in range(32):
        lineStr = fr.readline()
        for j in range(32):
            lst.append(int(lineStr[j]))
    lst.append(0)#我们让lst变为1 * 1025最后一个位置存标签
    #print(len(lst))
    return lst  # 返回值可以是list类型
#训练函数
def training():

    File_list = Getfilename("E:\python程序\感知机0,1图片识别\data")
    # print(Getfilename("E:\python程序\感知机0,1图片识别\data"))
    train_data_0 = []
    train_data_1 = []
    Temp = []
    for i in range(184):
        if File_list[i].startswith('0'):#如果文件名开头是0
            sfilename = ['E:\python程序\感知机0,1图片识别\data\\']#这次提交，在我电脑上这个文件位置，如果想重现在这里改
            sfilename.append(File_list[i])
            # print(sfilename)
            # ''.join(sfilename) 单引号之间的内容就是变为字符串后每个元素之间用什么隔开
            filename = ''.join(sfilename)#l ist类型的文件名转化为字符串，每个元素之间不加任何东西
            # print(filename)
            Temp = img2vector(filename)# 把文件名传给数据读取函数
            Temp[1024] = -1# 最后一个标签-1代表0图片
            train_data_0.append(Temp)
            # 把标签放在list最后一位
        elif File_list[i].startswith('1'):# 如果文件名的开头是1
            sfilename = ['E:\python程序\感知机0,1图片识别\data\\']  #  注意转义字符
            sfilename.append(File_list[i])
            # print(sfilename)
            filename = ''.join(sfilename)
            # print(filename)
            Temp = img2vector(filename)
            Temp[1024] = 1
            # print(Temp)
            train_data_1.append(Temp)
    train_datas = train_data_0 + train_data_1  # 两类数据相加
    # print(len(train_datas))
    weight = []  # 权重
    for i in range(1024):
        weight.append(0)#每个特征的权重初始化为0
    bias = 0  # 偏置量

    learning_rate = 0.5  # 学习速率
    W = 0
    train_num = 100
    #train_num = int(input("请输入训练次数"))  # 迭代次数
    for i in range(train_num):
        train = train_datas[ random.randrange(0,184) ]
        #print(len(train))
        #下面全要改为1024个特征的
        for j in range(1024):
            W = W + weight[j] * train[j]
        predict = sign(W + bias)  # 过激活函数激
        y = train[1024]
        print("Lable: %d, Predict: %d"%(y, predict))
        if y * predict <=0 :#判断错误的点,我们的标签放在train
            for i in range(1024):
                weight[i] = weight[i] + learning_rate * y * train[i]#权重更新
            bias = bias + learning_rate * y#更新偏置量
            print("Update the weight and bias")
            print(weight, bias)

    #print("stop training: "),
    #print(weight, bias)
    return (weight, bias)
test()