#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <cstring>
#include <conio.h> 
#include <ctype.h>
#include <stdio.h> 
#include <Windows.h>
using namespace std;


struct VM {
    char NameFilm[250];
    char Rejiser[250];
    char Janr[250];
    char Rank[250];
    char PriceDisk[250];
};
VM* Create(int size) {
    VM* films = new VM[size];
    return films;
}
void DeleteFilms(VM* films) {
    delete[]films;
}
VM Input() {
    VM film;
    cout << "Название фильма:" << endl;
    gets_s(film.NameFilm, 250);
    cout << "Режисёр:" << endl;
    gets_s(film.Rejiser, 250);
    cout << "Жанр:" << endl;
    gets_s(film.Janr, 250);
    cout << "Рейтинг популярности:" << endl;
    gets_s(film.Rank, 250);
    cout << "Цена Диска:" << endl;
    gets_s(film.PriceDisk, 250);
    return film;
}
void PrintFilm(VM film) {
    cout << "Название фильма: " << film.NameFilm << endl;
    cout << "Режисёр: " << film.Rejiser << endl;
    cout << "Жанр: " << film.Janr << endl;
    cout << "Рейтинг популярности: " << film.Rank << endl;
    cout << "Цена Диска: " << film.PriceDisk << endl;
}
void PrintAll(VM* films, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": ";
        PrintFilm(films[i]);
    }
    cout << endl;
}
VM* AddFilm(VM* films, int& size, VM film) {
    VM* tmp = Create(size + 1);
    for (int i = 0; i < size; i++)
    {
        *(tmp + i) = *(films + i);
    }
    *(tmp + size) = film;
    cout << "Вы добавили фильм:" << film.NameFilm << endl;
    DeleteFilms(films);
    size++;
    return tmp;
}
VM* DeleteTitleFilms(VM* films, int& size, char* searchName) {
    VM* tmp = Create(size - 1);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchName, films[i].NameFilm) == 0) {
            continue;
        }
        tmp[k] = films[i];
        k++;
    }
    cout << "Вы удалили фильм:" << searchName << endl;
    DeleteFilms(films);
    size--;
    return tmp;
}
void SearchTitleFilm(VM* films, int& size, char* searchName) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchName, films[i].NameFilm) == 0) {
            PrintFilm(films[i]);
            cout << endl;
        }
    }
}
void SearchFimlJanr(VM* films, int& size, char* searchJanr) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchJanr, films[i].Janr) == 0) {
            PrintFilm(films[i]);
            cout << endl;
        }
    }
}
void SearchRejiser(VM* films, int& size, char* searchRejiser) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchRejiser, films[i].Rejiser) == 0) {
            PrintFilm(films[i]);
            cout << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));

    int size = 10;
    VM* films = Create(size);
    films[0] = { "Пришельцывдоме", "Кристоф_Лауенштейн", "анимация", "9.3" , "99.00" };
    films[1] = { "Звездародилась", "БрэдлиКупер", "драма", "9.2", "99.00" };
    films[2] = { "Веном", "Рубен_Флейшер", "фантастика", "8.9", "99.00" };
    films[3] = { "Мстители:Войнабесконечности", "Энтони_Руссо", "фантастика", "8.8", "99.00" };
    films[4] = { "Книжныйклуб", "БиллХолдермэн", "комедия", "8.8", "99.00" };
    films[5] = { "Суперсемейка2", "БрэдБерд", "анимация", "8.7", "99.00" };
    films[6] = { "Поиск", "Аниш_Чаганти", "триллер", "8.8", "99.00" };
    films[7] = { "Небоскреб", "РоусонМаршаллТербер", "боевик", "8.6", "99.00" };
    films[8] = { "Псыподприкрытием", "Раджа_Госнелл", "комедия", "8.8", "99.00" };
    films[9] = { "Величайшийшоумен", "МайклГрэйси", "музыкальный", "8.8", "99.00" };
    int menu;
    do {
        cout << "Показ всех записей - 1" << endl; //
        cout << "Добавление нового фильма - 2" << endl; //
        cout << "Удаление фильма по названию - 3" << endl; //
        cout << "Поиск по названию - 4" << endl;//
        cout << "Поиск по жанру -5" << endl;//
        cout << "Поиск по режиссеру -6" << endl;//      
        cin >> menu;
        cin.ignore();
        switch (menu) {
        case 1: {
            PrintAll(films, size);
        }
              break;
        case 2: {
            films = AddFilm(films, size, Input());

        }
              break;
        case 3: {
            char searchName[125];
            cout << "Введите Название фильма" << endl;
            gets_s(searchName, 125);
            films = DeleteTitleFilms(films, size, searchName);
        }
              break;
        case 4: {
            char searchName[250];
            cout << "Для поиска введите Название фильма" << endl;
            gets_s(searchName, 250);
            SearchTitleFilm(films, size, searchName);
        }
              break;
        case 5: {
            char searchJanr[250];
            cout << "Введите Жанр для поиска:" << endl;
            cout << "анимация, драма, фантастика, комедия, боевик, триллер, музыкальный" << endl;
            gets_s(searchJanr, 250);
            SearchFimlJanr(films, size, searchJanr);
        }
              break;
        case 6: {
            char searchRejiser[250];
            cout << "Для поиска введите Режисера" << endl;
            gets_s(searchRejiser, 250);
            SearchRejiser(films, size, searchRejiser);
        }
              break;
        }

    } while (menu != 0);


    return 0;
}