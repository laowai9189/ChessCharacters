# 中国象棋局面特征提取
对中国象棋进行局面特征提取，就是针对中国象棋中所有的棋子进行特征提取，每一个棋子可以提取8个特征，一共32个棋子，就是256个特征。
# 特征1：存在性
在象棋局面中，并不一定是所有的棋子都存在，有些已经在前面的对弈中被对面棋子吃掉。如果棋子A已经被吃掉，那么A的存在性被赋值为0，否则被赋值为1；在图3.1的局面中，黑方有9个棋子，而红方有8个棋子，这些棋子的存在性的值都是1，棋子的总数一共是32个，那其他15个棋子的存在性都是0。
# 特征2：

