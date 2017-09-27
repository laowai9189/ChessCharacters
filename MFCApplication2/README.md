# 文件介绍
## 棋盘的类
chessCharacters.h和chessCharacters.cpp
## 棋子的类
pieceCharacters.h和pieceCharaters.cpp
## 局面分析类
wholePieces.h和wholePieces.cpp
## 读取棋谱的类
readXml.h和readXml.cpp
## 将分析的结果写到Excel文件中的类
toExcel.h和toExcel.cpp
# 使用说明
## 说明1：
这是一个MFC窗口程序，请运行前修改MFCApplication2Dlg.cpp，337行的string是生成的excel数据文件的名字，338页的string是生成的excel标签文件的名字。
## 说明2：
MFCApplication2Dlg.cpp的368到371行，可以按照中局和残局进行调整
## 说明3：
建议使用Visual Studio 2015，打开MFCApplication2.sln文件，以Debug x86编译和运行，便可以出现程序窗口
