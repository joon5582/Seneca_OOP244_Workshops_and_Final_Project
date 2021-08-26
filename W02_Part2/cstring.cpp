#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds{

int strLen(const char* s){
    int counter = 0;
    while (s[counter] != '\0'){
        counter++;
    }
    return counter;
};

void strCpy(char* des, const char* src){
    int i;
    for (i = 0; i < strLen(src); i++){
        des[i] = src[i];
    }
    des[strLen(src)] = '\0';
};

void strnCpy(char* des, const char* src, int len){
    int i;
for (i = 0; i < len; i++){
    des[i] = src[i];
}
    if (strLen(src) < len){
        des[strLen(src) + 1] = '\0';
    }
};

int strCmp(const char* s1, const char* s2){
    
    if (strLen(s1) == strLen(s2)) {
        int cmp = 0;
        int i;
        for (i = 0; i < strLen(s1); i++){
            if (s1[i] == s2[i]){
                cmp++;
            }
        }
    if (cmp == strLen(s1) && cmp == strLen(s2)){
            return 0;
        }
    }
    int i;
    for (i = 0; i < strLen(s1); i++){
        if (s1[i] > s2[i]) {
            return 1;
        }
    }
    
    return -1;
};

int strnCmp(const char* s1, const char* s2, int len){
    int i;
        int cmp = 0;
        for (i = 0; i < len; i++){
            if (s1[i] == s2[i]){
                cmp++;
            }
            if (cmp == len) { return 0;}
        }
    for (i = 0; i < len; i++){
        if (s1[i] > s2[i]) {
            return 1;
        }
    }
    return -1;
};

const char* strStr(const char* str1, const char* str2){
    
    int a = 0;
    int x;
    int counter = 0;
    for (x = 0; x < strLen(str1); x++){
        if (str1[x] == str2[a]){
            int x1 = x;
            
            for(a = 0; a < strLen(str2); a++){
                if (str1[x1] == str2[a]){
                    x1++;
                    counter++;
                }
                
                    else{
                        counter = 0;
                    }
                
                if (counter == strLen(str2)){
                    return &str1[x];
                }
            }
        }
        }
    
    return nullptr;
};

void strCat(char* des, const char* src){
    int i = 0, a = 0;
    while (des[i] != '\0'){
        i++;
        
    }
    while ((des[i++] = src[a++]) != '\0');
};
}
