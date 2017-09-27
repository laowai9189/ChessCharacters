# 中国象棋局面特征提取
对中国象棋进行局面特征提取，就是针对中国象棋中所有的棋子进行特征提取，每一个棋子可以提取8个特征，一共32个棋子，就是256个特征。
## 特征1：存在性
在象棋局面中，并不一定是所有的棋子都存在，有些已经在前面的对弈中被对面棋子吃掉。如果棋子A已经被吃掉，那么A的存在性被赋值为0，否则被赋值为1
## 特征2：位置信息
中国象棋的棋盘可以近似看作一个10乘9的矩阵，棋盘上的每一个棋子都有一个独立的位置信息。位置信息被表示为一个自然数坐标(X,Y)，坐标X按照棋盘的10条水平线进行取值，按照从上往下的顺序，从0到9进行赋值；坐标Y按照棋盘的9条竖直线进行取值，按照从左到右的顺序，从1到9进行赋值。我们认为，坐标X表示的棋子水平线位置的重要程度要大于坐标Y表示的棋子竖直线位置的重要程度，因为水平线位置代表棋子在对弈中进攻和防守的程度，所以将X放在十位上，Y放在个位上，组成十进制二位数。再者，为了突出棋子“河界”上下两区域的区别，设定一个区域位置值，棋子在“河界”上方，设定该值为2，棋子在“河界”下方，设定该值为1，并且将区域位置值放到十进制的百位上，因此棋子的位置信息是一个十进制3位数。如果棋子不存在，该棋子的位置信息取0。
## 特征3：基于位置的价值
中国象棋棋子的价值是根据棋子的位置变化而变化的。MFCApplication2/pieceCharacters.h的position_value数组，包括了所有棋子的基于位置的信息，根据相应位置取值即可
## 特征4：
在当前的局面中，遵照游戏规则的情况下，每一个棋子都有可数的走法数，不管走法的策略的优劣，只要遵照游戏规则，都需要被计算在内
## 特征5：机动性
一个棋子的走法数越多，它的机动性越强。不同的棋子，其机动性的权重不相同，下表为每种棋子的权重

#|车|马|象（相）|士（仕）|将（帅）|炮|卒（兵）
----|-----|-----|-----|-----|-----|-----|-----
机动性权重|6|12|1|1|0|6|15
## 特征6：受到的威胁值
在象棋局面中，一个棋子可能会在对方的下一步行棋中被吃子。每一棋子被赋予一个唯一数字来辨别。一个棋子受到的威胁值等于攻击它的棋子的唯一值与其基于位置的价值的乘积。如果受到多个对方棋子的攻击，那么受到的威胁值等于这几个棋子的威胁值的加和，棋子的唯一值如下表所示

棋子|黑方|红方
----|-----|-----
车|114|82
马|110|78
象（相）|98|66
士（仕）|97|65
将（帅）|107|75
炮|99|67
卒（兵）|112|80
# 特征7：受到的保护值
在象棋局面中，如果一个棋子在己方棋子的正当走法路径上，那么棋子就受到己方棋子的保护。棋子受到的保护值等于保护它的棋子的唯一值与其基于位置的价值的乘积。
# 特征8：攻击力
在象棋局面中，如果一个棋子在下一步行棋中会吃掉对方的棋子，那么这个棋子具有攻击性。棋子的攻击力等于被攻击的棋子的唯一值与基于位置的价值的乘积。
