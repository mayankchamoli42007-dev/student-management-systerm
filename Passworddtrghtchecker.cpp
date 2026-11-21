#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool checkUpper(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool checkLower(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (islower(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool checkNumber(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (isdigit(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool checkSpecial(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (!isalnum(password[i]))
        {
            return true;
        }
    }
    return false;
}

int checkStrength(string password)
{
    int score = 0;

    if (password.length() >= 8)
    {
        score++;
    }

    if (checkUpper(password))
    {
        score++;
    }

    if (checkLower(password))
    {
        score++;
    }

    if (checkNumber(password))
    {
        score++;
    }

    if (checkSpecial(password))
    {
        score++;
    }

    return score;
}

void showResult(int score)
{
    if (score <= 2)
    {
        cout << "Password is weak";
    }
    else if (score == 3)
    {
        cout << "Password is medium";
    }
    else if (score == 4)
    {
        cout << "Password is strong";
    }
    else
    {
        cout << "Password is very strong";
    }
}

int main()
{
    string password;
    int score;

    cout << "Enter password: ";
    getline(cin, password);

    score = checkStrength(password);

    cout << "\nPassword length: " << password.length() << endl;

    if (checkUpper(password))
    {
        cout << "Uppercase letter: Yes" << endl;
    }
    else
    {
        cout << "Uppercase letter: No" << endl;
    }

    if (checkLower(password))
    {
        cout << "Lowercase letter: Yes" << endl;
    }
    else
    {
        cout << "Lowercase letter: No" << endl;
    }

    if (checkNumber(password))
    {
        cout << "Number: Yes" << endl;
    }
    else
    {
        cout << "Number: No" << endl;
    }

    if (checkSpecial(password))
    {
        cout << "Special character: Yes" << endl;
    }
    else
    {
        cout << "Special character: No" << endl;
    }

    cout << "\nScore: " << score << "/5" << endl;

    showResult(score);

    return 0;
}