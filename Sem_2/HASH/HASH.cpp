#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string get_random_fio();
string get_random_phone();
string get_random_date();
int get_random_number();
int sum_date(string str);

string surnames[10] = { "Ivan","Alexey","Alexander","Dmitry","Maksim","Artyom","Grigoriy","Anton","Anatoliy","Peter" };
string names[10] = { "Ivanov","Sidorov","Borisov","Kozlov","Sevkhanov","Mikheev","Plekheev","Lodkin","Ryzhih","Svatov" };
string patronymic[10] = { "Aleksandrovich","Alexeyevich","Vladimirovich","Olegovych","Denisovich","Sergeevich","Anatolevich","Ivanovich","Danilovich","Yurievich" };
string phones[10] = { "73266480147","71882910822","77421674490","71122061535","72675740681","78921547279","71169111413","77503986701","79929112030","78968605764" };
string dates[10] = { "03.08.1970","11.07.1969","13.08.1967","12.11.1996","14.10.1966","17.12.1985","01.01.1981","14.04.1966","15.08.1965","16.06.1986" };
int collision_count = 0;

struct Human
{
    Human()
    {
        fio = "NULL";
        phone = "NULL";
        date = "NULL";
    }
    string fio;
    string phone;
    string date;
};

struct hash_table
{
    Human* arr;
    hash_table(int size)
    {
        arr = new Human[size];
    }
    bool add(Human tmp, int size);
    void pop(string delete_date, int size);
    void search_index(string date, int size);
};

Human create_random_human()
{
    Human tmp;
    tmp.fio = get_random_fio();
    tmp.phone = get_random_phone();
    tmp.date = get_random_date();
    return tmp;
}

int hash_function(string str, int size)
{
    double f = 0.1337 * sum_date(str);
    double g = (f - int(f)) * size;
    return int(g);
}

bool hash_table::add(Human tmp, int size)
{
    int idx = hash_function(tmp.date, size);
    int originalIdx = idx;
    do {
        if (arr[idx].fio == "NULL")
        {
            arr[idx] = tmp;
            return true;
        }
        collision_count++;
        idx = (idx + 1) % size;
    } while (idx != originalIdx);
    return false; // Table is full
}

void hash_table::pop(string delete_date, int size)
{
    int idx = hash_function(delete_date, size);
    int originalIdx = idx;
    do {
        if (arr[idx].date == delete_date)
        {
            arr[idx] = Human();
            return;
        }
        idx = (idx + 1) % size;
    } while (idx != originalIdx);
}

void hash_table::search_index(string date, int size)
{
    int idx = hash_function(date, size);
    int originalIdx = idx;
    do {
        if (arr[idx].date == date)
        {
            cout << "date: " << date << " index: " << idx << endl;
            return;
        }
        idx = (idx + 1) % size;
    } while (idx != originalIdx);
    cout << "date: " << date << " not found" << endl;
}

void fill_arr_of_random_humans(Human* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = create_random_human();
    }
}

void show(Human tmp)
{
    cout << "------------------------------" << endl;
    cout << "Full name: " << tmp.fio << endl;
    cout << "phone number: " << tmp.phone << endl;
    cout << "date: " << tmp.date << endl;
    cout << "------------------------------" << endl;
}

void print_arr_of_humans(Human* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        show(arr[i]);
    }
}

void show_hash_table(hash_table* table, int size)
{
    for (int i = 0; i < size; i++)
    {
        show(table->arr[i]);
    }
}

int sum_date(string str)
{
    return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}

string get_random_fio()
{
    return (surnames[get_random_number()] + ' ' + names[get_random_number()] + ' ' + patronymic[get_random_number()]);
}

string get_random_phone()
{
    return phones[get_random_number()];
}

string get_random_date()
{
    return dates[get_random_number()];
}

int get_random_number()
{
    return rand() % 10;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int size;
    string date;
    cout << "Enter the size of the hash table: " << endl;
    cin >> size;
    Human* arr = new Human[size];
    hash_table table(size);
    fill_arr_of_random_humans(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (!table.add(arr[i], size))
        {
            cerr << "Hash table is full. Unable to add all elements." << endl;
            break;
        }
    }
    show_hash_table(&table, size);
    cout << endl << endl;
    cout << "Enter a date to search: " << endl;
    cin >> date;
    cout << endl;
    table.search_index(date, size);
    cout << endl << endl;
    show_hash_table(&table, size);
    cout << endl << endl;
    cout << "Enter a date to delete: " << endl;
    cin >> date;
    table.pop(date, size);
    cout << endl << endl;
    show_hash_table(&table, size);
    cout << endl << endl;
    cout << "Collisions: " << collision_count << endl;
    delete[] arr;
    return 0;
}