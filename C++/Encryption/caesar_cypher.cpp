#include <iostream>
using namespace std;

int i, n, t, x, y, flag;
char str[100];
long int e[50], d[50], temp[50], j;
char en[50], m[50];
char msg[100];

void caesar_cypher()
{
   cout << "Please enter a string:\t";
   cin >> str;

   cout << "\nPlease choose following options:\n";
   cout << "1 = Encrypt the string.\n";
   cout << "2 = Decrypt the string.\n";
   cin >> x;


   switch(x)
   {
      
      case 1:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2; 

         cout << "\nEncrypted string: " << str << endl;
         break;

      
      case 2:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
         str[i] = str[i] - 2; 

      cout << "\nDecrypted string: " << str << endl;
      break;

      default:
         cout << "\nInvalid Input !!!\n";
   }
}




int main()
{
   caesar_cypher();

   return 0;
}