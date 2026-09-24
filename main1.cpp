#include "TableCipher.h"
#include <iostream>
#include <limits>
#include <locale>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Локаль для работы русского языка
    int key;
    wstring text;
    unsigned op;

    // Вечный цикл ввода ключа. Он завершится (`break`) только когда введут нормальное число > 0
    while(true) { 
        wcout << L"Введите ключ (число столбцов): ";
        if(wcin >> key) { // Если ввели именно число
            if(key == 0) { // Ключ 0 создаст ошибку деления в алгоритме
                wcout << L"Ключ не должен быть равен 0. Попробуйте снова.\n";
                continue; 
            }
            // Очищаем буфер ввода, чтобы убрать символ перевода строки '\n'
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); 
            break; // Все ок, выходим из цикла валидации ключа
        } else {
            // Срабатывает, если вместо числа ввели буквы (например "привет")
            wcout << L"Неверный ввод ключа. Ключ - число больше нуля.\n";
            wcin.clear(); // Сбрасываем флаг ошибки ввода
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); // Полностью чистим буфер
        }
    }

    TableCipher cipher(key); // Инициализируем класс ключом
    wcout << L"Ключ загружен\n";

    do {
        wcout << L"Шифр готов. Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать, 3-сменить ключ): ";
        if(wcin >> op) {
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            
            if(op > 3) {
                wcout << L"Неправильная операция\n";
            } 
            else if(op == 3) { // Функция быстрой смены ключа прямо во время работы программы
                while(true) {
                    wcout << L"Введите новый ключ: ";
                    if(wcin >> key && key != 0) {
                        wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); 
                        cipher = TableCipher(key); // Перезаписываем объект шифратора новым ключом
                        wcout << L"Ключ успешно изменён\n";
                        break;
                    } else {
                        wcout << L"Неверный ввод ключа. Попробуйте снова.\n";
                        wcin.clear();
                        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
                    }
                }
            } 
            else if(op > 0) { // Если выбрали 1 или 2
                wcout << L"Введите текст: ";
                // Используем getline вместо wcin >> text, чтобы можно было вводить строки С ПРОБЕЛАМИ
                getline(wcin, text); 
                
                if(op == 1) {
                    wcout << L"Зашифрованный текст:\n" << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст:\n" << cipher.decrypt(text) << endl;
                }
            }
        } else {
            wcout << L"Неверный ввод операции. Попробуйте снова.\n";
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        }
    } while(op != 0);

    return 0;
}