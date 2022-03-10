#include <iostream>

int main() 
{	// Переменная uname содержит username
	char uname[50] = "";

	// Получаем uname from потока ввода
	std::cin >> uname;

	//пеачтчаем   выа 
	std::cout << "Hello,World! from  " <<uname << std::endl;
}
