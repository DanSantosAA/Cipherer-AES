#include "Cipher.h"

#include <iostream>

int main(int argc, char const *argv[])
{
	string key = "\x002b\x007e\x0015\x0016\x0028\x00ae\x00d2\x00a6\x00ab\x00f7\x0015\x0088\x0009\x00cf\x004f\x003c";
	
	Cipher *cipher = Cipher::getInstance();

	string text;
	string texto_cifrado;

	cout << "Ingrese la cadena a cifrar: ";
	getline(cin, text);

	texto_cifrado = cipher->cifrate(text, &key);

	cout << "Texto inicial: " << text << endl;

	cout << "Texto cifrado: " << texto_cifrado << endl;

	cout << "Texto final  : " << cipher->decifrate(texto_cifrado) << endl;

	return 0;
}
