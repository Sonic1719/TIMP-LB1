#include "TableCipher.h"
#include <iostream>
#include <locale>
#include <string>

using namespace std;

// Конструктор просто запоминает ключ
TableCipher::TableCipher(int key) : key(key) {}

// ЗАШИФРОВАНИЕ
std::wstring TableCipher::encrypt(const std::wstring& text)
{
    // Рассчитываем, сколько строк нам понадобится в таблице
    int rows;
    if(text.length() % key != 0) {
        rows = text.length() / key + 1; // Если текст делится с остатком, добавляем еще одну строку
    } else {
        rows = text.length() / key; // Если делится нацело
    }

    // Создаем двумерный массив (матрицу) нужного размера
    wchar_t table[rows][key];

    // Шаг 1: Заполняем таблицу исходным текстом (слева направо, сверху вниз)
    int index = 0; 
    for(int i = 0; i < rows; i++) {       // Цикл по строкам
        for(int j = 0; j < key; j++) {    // Цикл по столбцам
            if(index < text.length()) {
                table[i][j] = text[index++]; // Кладем букву из текста в ячейку
            } else {
                table[i][j] = L' '; // Если текст закончился, забиваем оставшиеся ячейки пробелами
            }
        }
    }

    std::wstring encrypted_text; // Сюда соберем зашифрованный результат

    // Шаг 2: Считываем данные из таблицы "сверху вниз, справа налево"
    // Внешний цикл `i` идет с ПОСЛЕДНЕГО столбца (key - 1) до нулевого (i--)
    for(int i = key - 1; i >= 0; i--) {
        for(int j = 0; j < rows; j++) { // Внутренний цикл идет по строкам сверху вниз
            encrypted_text += table[j][i]; // Дописываем символ в шифротекст
        }
    }
    return encrypted_text;
}

// РАСШИФРОВАНИЕ
std::wstring TableCipher::decrypt(const std::wstring& encrypted_text)
{
    // Снова высчитываем количество строк по той же логике
    int rows;
    if(encrypted_text.length() % key != 0) {
        rows = encrypted_text.length() / key + 1;
    } else {
        rows = encrypted_text.length() / key;
    }

    wchar_t table[rows][key];
    int index = 0;

    // Шаг 1: Восстанавливаем таблицу из зашифрованной строки. 
    // Поскольку шифротекст записывался по столбцам справа налево, мы раскладываем его обратно по тому же пути!
    for(int i = key - 1; i >= 0; i--) {    // Идем по столбцам с конца
        for(int j = 0; j < rows; j++) {    // Сверху вниз
            if(index < encrypted_text.length()) {
                table[j][i] = encrypted_text[index++]; // Возвращаем буквы в ячейки таблицы
            }
        }
    }

    std::wstring decrypted_text;
    
    // Шаг 2: Теперь просто читаем получившуюся таблицу обычным текстом (слева направо, строка за строкой)
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            decrypted_text += table[i][j];
        }
    }
    return decrypted_text;
}