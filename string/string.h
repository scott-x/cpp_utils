#ifndef STRING_H
#define STRING_H
//to uupper & lower case
char *toUpper(char *str);
char *toLower(char *str);
char *firstLetterToUpper(char *str);

//counts
int counts(char *str);

//search substr
int index(char *str, char * substr);

//replace
void replace(char *str, std::string from, std::string to);

//concat

#endif // STRING_H


