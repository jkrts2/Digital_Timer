# LCD_ShowTemperature
 单片机学习代码备份  
 `请搭配普中51A6开发板使用，并将P3_0接J9的C,P0_0接J6的Dp，P2_0接J4的SC，LP1_0接JP1的K1`
# 使用模块
基于AT24C02模块储存数据，数码管模块显示计时，DS1302模块实现计时
# 基本介绍
Nixie文件为数码管驱动，AT24C02文件实现EEPOROM储存数据，I2C文件实现与AT24C02实现通讯，Key文件实现读取按下按键，Timer0文件为定时读取按键状态提供计时
# 成果图片
* 程序初始化
![](./Pic/程序初始化.jpg  "程序初始化")  
- 开始计时
![](./Pic/开始计时.jpg  "开始计时")
* 储存后清除计时
![](./Pic/储存后清除计时.jpg  "储存后清除计时")
- 读储存计时并恢复 
![](./Pic/读取储存计时并恢复.jpg  "读取储存计时并恢复")

# 参考教程
[江协科技](https://b23.tv/Pr9ubVy)
