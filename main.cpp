//
//  main.cpp
//  C++ final
//
//  Created by Mariam on 12/11/22.
//

//System Libraries
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
 //functions to genrating key
string generateKey(string pt, string key)
{
    int k = pt.size();
 
    for (int i = 0; ; i++)
    {
        if (k == i)
            i = 0;
        if (key.size() == pt.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
 //function for encryption
string encryption(string pt, string key)
{
    string cipher_text;
 
    for (int i = 0; i < pt.size(); i++)
    {
        char k = (pt[i] + key[i]) %26;
 
        k += 'A';
 
        cipher_text.push_back(k);
        
    }
    return cipher_text;
}
 //function for decryption
string decryption(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        char k = (cipher_text[i] - key[i] + 26) %26;
 
        k += 'A';
        orig_text.push_back(k);
    }
    return orig_text;
}
 //function for getiong input
void input(string &str,string &keyword)
{
     ofstream filelog;
     string cipher_text;
    cout<<"Enter text-";
    cin>>str;
    cout<<"Enter keyword-";
    cin>>keyword;
    cout << "\nPlaintext : " << str;
    cout << "\nKeyword: " << keyword<<"\n";
     //Open File
    filelog.open("filelog.txt", fstream::app);
    filelog<<"\n***ENCRYPTION***";
    filelog<<"\nOriginal Message: "<<str;
    filelog<<"\nKey: "<<keyword;
     filelog.close();
}

//main finction to make selection
int main()
{
    string str;
    string keyword;
     ofstream filelog;
    char a;
    cout<<"Enter E for encryption and D for decryption-";
    cin>>a;
    input(str,keyword);
    string key = generateKey(str, keyword);
    if(a=='E'){
        string cipher_text = encryption(str, key);
        cout << "Ciphertext : "<< cipher_text<< "\n";
         
  }
    else if(a=='D')
    cout << "Decrypted Text : "<< decryption(str, key);
    return 0;
}
