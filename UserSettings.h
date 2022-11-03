/*
* Author: Th3Spl
* Date: 10/2/2022
* Language: c++
* GitHub Repo: https://bit.ly/3T2zB2Y
* Discord: https://bit.ly/3OkuXMT
* LinkTree: https://linktr.ee/th3spl
* Purpose: User/Application settings :) kinda useful for game or application with local saving things fully coded in c++
*/

//Pragama section
#pragma once
#pragma warning( suppress : C4267) //Boring

//Libs
#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <regex>

//Namespaces
using namespace std;

//Coding Part :)

//I can suggest you to enjoy a coffe while reading this beautiful code ù_ù

//Notes:
//1. Your file must have a discriminator like name$Username123, name=Username123 or something like that
//2. You always need to close the file 'cause sometimes it can cause runtime errors
//3. Before you rewrite the file you should use clearfile() function 'cause sometimes if you don't do that it will have some extra text into the file
//4. idk the interaction with strange situation if you need something add it by yourself :)
//For any type of problem you can text me on discord (you can find my server/username on my home page on GitHub [my github is linked in the top of the document!])

//This class contain only provate functions that i need for the other commands
class PrivateFunction
{
public:
    static string getFullVarFromFile(string fileName, string varName)
    {
        fstream file;
        string result;
        string line;

        file.open(fileName);

        for (line; getline(file, line);)
        {
            if (line.rfind(varName) == 0)
            {
                result = line;
                break;
            }
            else {
                continue;
            }
        }

        return result;
    }
};


//This will fully clear your file (we need it here 'cause is used in a lot of functions)
int clearFile(string fileName)
{
    fstream file;
    file.open(fileName, ios::out);

    file << "";

    file.close();

    return 0;
}

//This function is used to get a variable from a file
string getValueFromFileVar(string fileName, string varName)
{
    //Vars
    fstream file;
    string result;
    string line;
    int varNameLenght;
    int lineLength;

    file.open(fileName);

    for (line; getline(file, line);)
    {
        if (line.rfind(varName) == 0)
        {
            result = line;
            break;
        }
        else {
            continue;
        }
    }

    varNameLenght = varName.length();
    lineLength = result.length();
    result = line.substr(varNameLenght, lineLength);

    file.close();

    return result;
};


string getFullFileContent(string fileName)
{
    //Vars
    fstream file;
    string result;
    bool firstTime = true;

    file.open(fileName);

    for (string line; getline(file, line);)
    {
        if (firstTime == true)
        {
            result = result + line;
            firstTime = false;
        }
        else
        {
            result = result + "\n" + line;
        };
    }

    file.close();

    return result;
}


//This will replace the variable with the new value
int replaceVarFromFile(string fileName, string varName, string newValue)
{
    /*
    * Note this won't change the varibleName= 
    * it will only change the part after the variableName without changing the var name
    */

    string fullText = getFullFileContent(fileName);
    string lineToChange = getValueFromFileVar(fileName, varName);

    if (lineToChange == varName) // This can cause errors that's why you should handle that
    {
        return 0;
    }

    int index;

    while ((index = fullText.find(lineToChange)) != string::npos) {    //for each location where Hello is found
        fullText.replace(index, lineToChange.length(), newValue); //remove and replace from that position
    };

    fstream file;

    file.open(fileName);

    clearFile(fileName);

    file << fullText;

    string newFull = getFullFileContent(fileName);

    file.close();

    return 0;
}


//This will erase the value of a variable (the var will not be avaible if not defined)
int eraseValueFromFile(string fileName, string varName)
{

    //THIS WILL ONLY ERASE THE VALUE NOT THE VARIABLE

    string fullText = getFullFileContent(fileName);
    string lineToChange = getValueFromFileVar(fileName, varName);

    int index = fullText.find(lineToChange);
    fullText.replace(index, lineToChange.length(), "");

    fstream file;

    file.open(fileName);

    clearFile(fileName);

    file << fullText;

    string newFull = getFullFileContent(fileName);

    file.close();

    return 0;
}


int eraseVarFromFile(string fileName, string varName)
{

    //THIS WILL FULLY ERASE THE VARIABLE FROM THE FILE

    string fullText = getFullFileContent(fileName);
    string fullLineVariable = PrivateFunction::getFullVarFromFile(fileName, varName);

    int index = fullText.find(fullLineVariable);
    fullText.replace(index, fullLineVariable.length(), "");

    fstream file;

    file.open(fileName);

    clearFile(fileName);

    cout << fullText << "\n\n";

    file << fullText;

    file.close();

    return 0;
}
