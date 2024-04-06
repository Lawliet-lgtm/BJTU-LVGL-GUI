1.运行环境
软件需在linux系统下借助Framebuffer运行。可在ubuntu22.04.2虚拟机进行线上测试，再移植到arm架构的linux系统的开发板上，开发板上需要连接一个外置独立显示屏，配置环境后运行软件程序。
 
2.软件概述
1)	我们的软件调用了LVGL图形库，因此是在官方提供的lv_port_linux_framebuffer工程框架下编写我们自己的图形界面代码的。本项目组编写的代码模块在lvgl/demos/widgets/lv_demo_widgets.c&lv_demo_widgets.h中，代码量在2000行左右。
其余属于LVGL官方提供的图形库。
 
2)	调用我们设计的图形界面代码的接口是在官方所给的LVGL-main函数框架中调用lv_demo_widgets.h中声明，lv_demo_widgets.c定义的函数lv_bjtu_achive();
 
3)	本项目在官方提供的工程框架下引入了一个新的第三方库avilib，增加了原Makefile文件中的内容。
 
3.使用说明
1)	将软件压缩包中的lv_port_linux_frame_buffer解压在ubuntu虚拟机的选定目录下。
2)	打开terminal，cd 到 lv_port_linux_frame_buffer下一级，与Makefile同一目录。输入make指令进行编译。
 
3)	编译完成后，跳转到build/bin目录下，可以看到生成的可执行文件demo。
 
4)	输入指令： systemctl set-default multi-user.target
              reboot
关闭ubuntu图形界面，重启虚拟机。
 
5)	在命令行界面跳转到bin目录下，输入sudo ./demo即可观察到设计的界面。

由于虚拟机上命令行会干扰基于Framebuffer显示的图形界面，且无法用鼠标进行交互，所以只用作测试设计的界面能否基于Framebuffer显示以及程序运行时有无bug。具体的演示效果请移植到开发板上，用外置独立显示屏观看（见后文）。
 
6)	使用指令： systemctl set-default graphical.target
              reboot
打开ubuntu图形界面，下载gcc-arm-8.2-2018.08-x86_64-arm-linux-gnueabihf交叉编译器，将lv_port_linux_frame_buffer下一级的Makefile中的CC  :=   gcc改成下载的gcc-arm-8.2-2018.08-x86_64-arm-linux-gnueabihf下bin中的arm-linux-gnueabihf-gcc编译器的绝对路径，也就是对代码进行交叉编译，以移植到arm架构的开发板。
 
7)	打开terminal 输入 make clean清除先前的编译结果，再次make即可得到arm架构的可执行文件demo。
 
8)	将得到的demo移植到开发板上，可通过winscp工具或者移动存储介质。用putty连接开发板的终端，输入以下指令进行环境配置：
#鼠标驱动使能
cd /root/mouse
insmod hid.ko
insmod hid-generic.ko
insmod usbhid.ko
insmod uhid.ko
#显示屏内存初始化
cd /root/tools
gpio-set 5 1
export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
./dispinit &
 
9)	运行移植的demo程序，可在显示屏上看到设计的嵌入式图形界面，用鼠标可与其进行交互。demo程序中包括了设计的播放视频、显示时钟、显示图片、定时器、二维码、页面切换等一系列功能。
 
 
4.使用指令合集
#关闭ubuntu图形界面
systemctl set-default multi-user.target
reboot
#打开ubuntu图形界面
systemctl set-default graphical.target
reboot
#编译
make
#清除编译文件
make clean
#鼠标驱动使能
cd /root/mouse
insmod hid.ko
insmod hid-generic.ko
insmod usbhid.ko
insmod uhid.ko
#显示屏内存初始化
cd /root/tools
gpio-set 5 1
export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
./dispinit &
