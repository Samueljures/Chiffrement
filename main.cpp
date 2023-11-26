#include <iostream>
#include <string>
using namespace std;

string chiffrement(const string &phrase) {
    int a = 3;
    int b = 5;
    string chiffre = "";

    for (char lettre : phrase) {
        if (isalpha(lettre)) {
            char base = (isupper(lettre)) ? 'A' : 'a';
            int index = lettre - base;
            int new_index = (a * index + b) % 26;
            char new_lettre = base + new_index;
            chiffre += new_lettre;
        } else {
            chiffre += lettre;
        }
    }

    return chiffre;
}

string dechiffrement(const string &phrase) {
    int a = 3;
    int b = 5;
    string dechiffre = "";

    for (char lettre : phrase) {
        if (isalpha(lettre)) {
            char base = (isupper(lettre)) ? 'A' : 'a';
            int index = lettre - base;
            int new_index = (a * index - b) % 26;
            char new_lettre = base + new_index;
            dechiffre += new_lettre;
        } else {
            dechiffre += lettre;
        }
    }

    return dechiffre;
}

int main() {
    int choix;
    string phrase;

    cout << "Que voulez-vous faire? 1-Criptage, 2-Decriptage" << endl;
    cin >> choix;

    cout << "Ecrivez la phrase" << endl;
    cin.ignore();
    getline(cin, phrase);

    if (choix == 1) {
        string code = chiffrement(phrase);
        cout << "La phrase cryptee est : " << code << endl;
    } else if (choix == 2) {
        string decode = dechiffrement(phrase);
        cout << "La phrase décryptee est : " << decode << endl;
    } else {
        cout << "Choix invalide." << endl;
    }

    return 0;
}
