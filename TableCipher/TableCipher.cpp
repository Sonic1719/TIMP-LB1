#include "TableCipher.h"
#include <iostream>
#include <locale>
#include <string>

using namespace std;

TableCipher::TableCipher(int key) : key(key) {}

std::wstring TableCipher::encrypt(const std::wstring& text)
{
    int rows;
    if(text.length() % key != 0) {
        rows = text.length() / key + 1; // Если текст делится с остатком, добавляем еще одну строку
    } else {
        rows = text.length() / key; // Если делится нацело
    }

    wchar_t table[rows][key];

    int index = 0; 
    for(int i = 0; i < rows; i++) {       // Цикл по строкам
        for(int j = 0; j < key; j++) {    // Цикл по столбцам
            if(index < text.length()) {
                table[i][j] = text[index++]; 
            } else {
                table[i][j] = L' '; 
            }
        }
    }

    std::wstring encrypted_text;

    for(int i = key - 1; i >= 0; i--) {
        for(int j = 0; j < rows; j++) { // Внутренний цикл идет по строкам сверху вниз
            encrypted_text += table[j][i]; // Дописываем символ в шифротекст
        }
    }
    return encrypted_text;
}

std::wstring TableCipher::decrypt(const std::wstring& encrypted_text)
{
    int rows;
    if(encrypted_text.length() % key != 0) {
        rows = encrypted_text.length() / key + 1;
    } else {
        rows = encrypted_text.length() / key;
    }

    wchar_t table[rows][key];
    int index = 0;
    for(int i = key - 1; i >= 0; i--) {    // Идем по столбцам с конца
        for(int j = 0; j < rows; j++) {    // Сверху вниз
            if(index < encrypted_text.length()) {
                table[j][i] = encrypted_text[index++]; 
            }
        }
    }

    std::wstring decrypted_text;
    index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            decrypted_text += table[i][j];
        }
    }
    return decrypted_text;
}