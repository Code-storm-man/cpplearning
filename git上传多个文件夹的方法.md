1、生成SSH-Key：在需要上传的文件夹根目录下打开终端(如果已经生成过这个设备的SSH-key就跳过这步)

输入指令：

```c++
ssh-keygen -t ed25519 -C "你的邮箱"
```

生成一个ssh-key

2、复制SSH-Key：复制刚刚生成的SSH-Key

输入指令：

```c++
cat ~/.ssh/id_ed25519.pub
```
如果进入了./ssh 文件或者没有进入，请记住从.ssh 文件夹开始就是用 \ 而不是 /
```c++
PS C:\ ... \.ssh> cat .\id_rsa.pub  # 这里是.\ 噢
```


3、将上述SSH-Key代码复制到Github的SSH-Key管理中

4、用SSH链接需要推送的远端库

进入需要推送的远端仓库，然后点击"clone" -> "ssh"

复制这个仓库的SSH链接

然后回到需要推送代码文件夹对应的终端

输入指令：（以cpplearning为例）

```cpp
git remote set-url origin git@github.com:Code-storm-man/cpplearning.git
```

这样，当前文件夹根目录就整体与远端仓库链接起来了。