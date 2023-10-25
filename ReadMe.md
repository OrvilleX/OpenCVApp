# OpenCV项目实例

## 开发环境搭建

首先通过[官网](https://opencv.org/)下载对应的4.5.5的Windows安装进行安装，安装完成后在系统环境变量中的
Path中增加对应安装路径下的`\build\x64\vc15\bin`路径到其中，然后通过控制台输入`opencv_version`显示
对应的OpenCV版本记录即可。  

项目属性中对应的`通用属性-> VC++目录 -> 包含目录`中增加对应OpenCV的`\build\include\opencv2`目录以及
`\build\include`目录，以及库目录中增加`build\x64\vc15\lib`目录即可。

对应还需要在`通用属性-链接器-输入-附加依赖项`中填写Debug环境下需要加载的lib文件，这个以笔者的版本对应
需要填写的版本为`opencv_world455d.lib`，对应Release的版本则为`opencv_world455.lib`。  
