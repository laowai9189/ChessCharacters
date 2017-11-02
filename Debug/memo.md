guyz-hmm分析
===
此开源项目实现了若干的HMM，具体分为两类，离散HMM和连续HMM。

当前仅关注离线HMM的实现，之后考虑继续学习连续HMM
# 离散HMM的分析 #
从测试程序开始，其测试程序的入口在examples\tests.py中的test_discrete函数。
首先初始化观测结果向量；随机生成状态转换矩阵A、观测概率矩阵B和初始概率分布PI；
实例化DiscreteHMM类，并调用train函数，生成对应的模型参数lamda(PI,A,B).

## DiscreteHMM类分析 ##
DiscreteHMM初始参数参见代码DiscreteHMM.py
DiscreteHMM继承自_BaseHMM
###从调用过程开始分析###
调用构造函数，\_\_init\_\_,设置A，PI，B，并调用父类的\_\_init\_\_初始化父类。
调用train函数，训练模型。train函数实现在父类_BaseHMM中。
####train函数####
_BaseHMM 201行
参数定义参见源码
调用_mapB,_mapB是基类定义的方法，子类必须实现。此处调用的是DiscreteHMM的实现。
_mapB中，其处理的数据是self.B,为NXM的矩阵，结合observations，生成B_map.
B_map中每一行对应一个状态下，observations各个结果出现的概率，是一个[N*T]的矩阵。
之后启动循环来进行训练，循环结束的两个条件：达到迭代上限或精度已经高于可接受的误差。
for循环中，调用trainier函数，进行单次训练。
#####trainier函数#####
调用_baumwelch函数，生成新的模型。 *//EM algorithm*
调用forwardbackward算法，获得之前的模型
更新_baumwelch生成的模型，调用forwardbackward算法，获得新的模型。
返回新旧两个模型。

###### _baumwelch函数 ######T
**E-step：**
调用_calcstats
在_calcstats，调用_calcalpha计算alpha
调用_calcbeta计算beta
调用_calcxi计算xi
计算gamma

###### _calcalpha函数 ######
alpha为(TXN)的矩阵，其算法与《李航.统计学方法》第176行算法相同。
beta算法与《李航.统计学方法》算法相同



**M-step**
调用_reestimate