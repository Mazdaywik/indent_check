#include <stdio.h>
#include <string.h>

void del_space(char *s) 
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) //перебираем элементы строки
        //если тек элемент не пробел и следующий не пробел или конец строки, то
        if (!(s[i] == ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0')))
            s[j++] = s[i]; //присваиваем след по счет текущий
    s[j] = '\0'; //добавляем в конце пустой элемент
}


int wcount(char *s) 
{
    int count = 0;
    del_space(s); //убираем лишние пробелы в строке
    if(s[0] == ' ' || strlen(s) == 0) //если в начале будет пробел или строка пустая, то
        count = -1; //не будем считать его
    for (int i = 0; s[i] != '\0'; i++) //перебираем символы в строке
        if (s[i] == ' ') //если текущий элемент пробел
            count++; //увелич счетчик
    return count + 1;
}


int main()
{
    char s[1000];
    gets(s);
    int res = wcount(s);
    printf("%d", res);
    return 0;
}