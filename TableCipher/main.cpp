#include "TableCipher.h"
#include <iostream>
#include <limits>
#include <locale>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int key;
    wstring text;
    unsigned op;

    while(true) { 
        wcout << L"Введите ключ (число столбцов): ";
        if(wcin >> key) {
            if(key == 0) { 
                wcout << L"Ключ не должен быть равен 0. Попробуйте снова.\n";
                continue; 
            }
            // Очищаем буфер ввода, чтобы убрать символ перевода строки '\n'
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); 
            break;
        } else {
            wcout << L"Неверный ввод ключа. Ключ - число больше нуля.\n";
            wcin.clear(); // Сбрасываем флаг ошибки ввода
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); 
        }
    }

    TableCipher cipher(key);
    wcout << L"Ключ загружен\n";

    do {
        wcout << L"Шифр готов. Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать, 3-сменить ключ): ";
        if(wcin >> op) {
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            
            if(op > 3) {
                wcout << L"Неправильная операция\n";
            } 
            else if(op == 3) {
                while(true) {
                    wcout << L"Введите новый ключ: ";
                    if(wcin >> key && key != 0) {
                        wcin.ignore(numeric_limits<streamsize>::max(), L'\n'); 
                        cipher = TableCipher(key);
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