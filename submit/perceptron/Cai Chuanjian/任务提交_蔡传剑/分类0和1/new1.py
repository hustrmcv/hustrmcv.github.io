# 图片矢量化函数
def img2vector(filename):
    return_vector=[]
    fr=open(filename)
    for i in range(32):
        lineStr=fr.readline()
        for j in range(32):
            return_vector.append(int(lineStr[j]))
    return return_vector
    

# 简单循环函数,以便初始化后面的weight
def loop(num,element):
    object=[]
    for i in range(num):
        object.append(element)
    return object
    
# 加载文件函数
def load_file():
    print('下面进行文件加载:')
    print('注意：下面将两类文件分类加载！')
    print('在本例中第一类的标签0,为第二类的标签为1')
    
    file_number_a=input('请输入要加载的第一类文件个数：')
    
    train_data_a=[]
    i=0
    
    while(i<int(file_number_a)):
        filename_a=input('data_a filename:')
        
        temp_a=img2vector(filename_a)
        temp_a.append(-1)
        train_data_a.append(temp_a)
        
        i=i+1
    
    
    file_number_b=input('请输入要加载的第二类文件个数：')
    
    train_data_b=[]
    j=0
    
    while(j<int(file_number_b)):
        filename_b=input('data_b filename:')
        
        temp_b=img2vector(filename_b)
        temp_b.append(1)
        train_data_b.append(temp_b)
        
        
        j=j+1
        
    return train_data_a,train_data_b
    
# 符号函数
def sign(v):
    if v > 0:
        return 1
    else:
        return -1
        
# 训练函数
def training():  
    train_data_a,train_data_b=load_file() #提取样本
    train_datas = train_data_a +  train_data_b  # 样本集

    weight = loop(1024,0)  # 权重
    bias = 0  # 偏置量
    learning_rate = 0.5  # 学习速率

    train_num = int(input("train num: "))  # 迭代次数

    for i in range(train_num):
        train = random.choice(train_datas)
        
        sum=0
        for j in range(1024):
            sum=sum+weight[j]*train[j]
        
        y=train[1024]#y是实际值，值域为{-1，1}，正实例点（1）对应标签1，负实例点（-1）对应标签-1
        if y==1:
            sign_y=1
        else:
            sign_y=0
        
        predict = sign(sum+ bias)  # 输出，predict为预测值，其余内容同上
        if predict==1:
            sign_predict=1
        else:
            sign_predict=0
        
        
        print("train data:  sign_y: %d ==> sign_predict: %d" % (sign_y,sign_predict))
        
        if sign_y != sign_predict :  # 判断误分类点
            for k in range(1024):
                weight[k] = weight[k] + learning_rate * y * train[k]  # 更新权重
      
            bias = bias + learning_rate * y  # 更新偏置量
            
            print("update weight and bias: ")
            print('weight=')
            for p in range(1024):
                print(weight[p],end='') 
            print('')
            print('bias=',bias)
            
    print("stop training: ")
    print('weight=')
    for p in range(1024):
        print(weight[p],end='') 
    print('')
    print('bias=',bias)

    return weight, bias
    
# 测试函数
def test():
    weight, bias = training()
    while True:
        print("注：输入'q'可退出测试")
        test_filename=input('test filename:')
        
        
        if test_filename == 'q': break
        
        test_data=img2vector(test_filename)
        
        sum=0
        for i in range(1024):
            sum=sum+weight[i]*test_data[i]
        predict = sign(sum + bias)
        
        if predict==1:
            sign_predict=1
        else:
            sign_predict=0
        
        print("sign_predict ==> %d" % sign_predict)



import random

test()

