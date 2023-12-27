/** 
* @file Client.h
* @author Демина К.С.
* @version 1.0
* @date 12.12.2023
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля Client
*/
#pragma once
#include <sys/types.h> // Содержит определения основных типов данных, таких как pid_t (идентификатор процесса), size_t (беззнаковое целое число для представления размеров объектов) и других.
#include <iostream> //Используется для ввода/вывода стандартных потоков std::cin и std::cout. Также используется для взаимодействия с консолью.
#include <cstdlib> //Содержит набор стандартных функций для работы с памятью, символами и строками
#include <cstring> //Предоставляет функции для работы с символьными строками, таких как strcpy, strncpy, strlen, strcmp, strcat и других.
#include <unistd.h> // Содержит системные вызовы и константы POSIX для работы с файлами, процессами и сокетами. Например, read, write, close, fork, exec, pipe и другие.
#include <string> //Предоставляет класс std::string для работы со строками. Включает функции для манипуляции строками, такие как substr, find, replace и другие.
#include <locale> //Предоставляет классы и функции для локализации и обработки различных культур.
#include <codecvt> // Содержит функции для конвертирования символов из одной кодировки в другую.
#include <sys/socket.h> //Содержит обьявления функций и структур для работы с сокетами, таких как socket, bind, listen, accept, connect и др.
#include <netinet/in.h> // Содержит определение структуры sockaddr_in и других типов данных, используемых для работы с сетевыми адресами.
#include <arpa/inet.h> //Содержит функции для преобразования сетевых адресов из текстового формата в бинарный и обратно.
#include <fstream> //Содержит классы и функции для работы с файлами, такие как ifstream, ofstream, fstream для чтения, записи и манипуляции с содержимым файлов.
#include <vector> //Предоставляет класс std::vector, реализующий динамический массив, который может изменять свой размер в рантайме. Используется для хранения и манипуляции списком значений.
#include <sstream> //Предоставляет класс std::stringstream, который используется для манипуляции с символьными строками. Часто используется для преобразования чисел в строки и строк в числа.

using namespace std;


/** 
* @brief Класс взаимодействия с сервером
* @param m_serverAddress адрес сервера
* @param m_serverPort порт сервера
* @param m_inputDataFile имя файла с векторами
* @param m_outputDataFile имя файла с результатами вычислений сервером
* @param m_clientCredentialsFile имя файла с логином и паролем клиента
*/
class Client{

    public:
    // Функции для взаимодействия клиента и сервера
    int interactWithServer();
    std::vector<std::vector<uint32_t>> readVectorsFromFile();
    void writeVectorsToFile( const std::vector<uint32_t>& vectors);
    std::pair<std::string, std::string> readLoginAndPasswordFromFile();

    // Гетторы и сетторы атрибутов класса Client
    int getServerAddress() const;
    void setServerAddress(int address);

    int getServerPort() const;
    void setServerPort(int port);

    string getInputDataFile() const;
    void setInputDataFile(const string& filename);

    string getOutputDataFile() const;
    void setOutputDataFile(const string& filename);

    string getClientCredentialsFile() const;
    void setClientCredentialsFile(const string& filename);

    private:
        int m_serverAddress;
        int m_serverPort;
        string m_inputDataFile;
        string m_outputDataFile;
        string m_clientCredentialsFile;

};


/** @brief Класс обработки ошибок ErrorManager
* @details Менеджер вывода сообщений об ошибках
*/
class ErrorManager: public std::invalid_argument
{
public:
	explicit ErrorManager (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit ErrorManager (const char* what_arg):
		std::invalid_argument(what_arg) {}
};


    