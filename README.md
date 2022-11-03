# User/Application Settings in c++

###Version 1.2.0

Hello guys i'm Th3Spl and today i am here with a new repository commit 
some time ago i was developing an app that needed an header for handle
the user/application local settings (like the c# vs code's function)
and i noticed that there was not any good library in c++ for do that
so i decided to create it by my own, so here it is!

`Keep in mind that is a free open source made by me nothing more!`

### Languages:

- [x] C++

### How to use it

Firstable you need to drag the file into your main.cpp folder 
after the download from GitHub, then follow the steps: 

```C++
#include "UserSettings.h" //You can also rename the file but you also need to change the name here in this line!
```

### Some Functions:

1. This will return a string value with the value of the variable into the file

```C++
#include <string>
string value = getValueFromFileVar(string fileName, string varName) //varName must be the discriminator in the file like nickaname=
```
2. This will return all the content of the file in order

```C++
#include <string> //(you don't need to include it all the time)
string fullFileText = getFullFileContent(string fileName)
```

3. This will replace the value of a variable into the file

```C++
replaceVarFromFile(string fileName, string varName, string newValue) 
//varName must be the name of the variable into the file like nickname=
//newValue is the new value that will replace the outdated one
```

Keep in mind that i still need to add a lot of new functions.

### If you need to contact ne you can do it on discord.

![Life Style](https://i.imgur.com/2Rn7HYe.png)
