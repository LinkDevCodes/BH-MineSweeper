#include <map>
#include <string>
#include "include/headers.hpp"
using namespace std;

void fun();
Map m;
string order;
bool MapExist = false;
map<string, long double> variables;

int main()
{
    variables["difficulty"] = 0.8;
    variables["author"] = 0;
    while (true)
    {
        fun();
        cin >> order;
        if (order == "start")
        {
            int length, width, mines;
            try
            {
                cin >> length >> width >> mines;
                if (length > 1000 || width > 1000 || mines >= (int)(variables["difficulty"] * length * width))
                {
                    cout << "ValueError: Your data is error.\n";
                    continue;
                }
                m = generate(length, width, mines);
                MapExist = true;
            }
            catch (...)
            {
                cout << "ValueError: Your data is with some wrong.\n";
            }
        }
        else if (order == "set")
        {
            try
            {
                string param;
                long double value;
                cin >> param >> value;
                if (variables.find(param) == variables.end())
                {
                    cout << "SetKeyError: There isn't a option called \"" << param << "\"\n";
                    continue;
                }
                variables[param] = value;
                cout << "[Info] Set \"" << param << "\" to " << value << " successfully.\n";
            }
            catch (...)
            {
                cout << "ValueError: Your data is with some wrong.\n";
            }
        }
        else if (order == "show")
        {
            try
            {
                string param;
                cin >> param;
                if (variables.find(param) == variables.end())
                {
                    cout << "[Info] Show \"" << param << "\" as " << variables[param] << " successfully.\n";
                    continue;
                }
                cout << "[Info] There is no such a key called \"" << param << "\"\n";
            }
            catch (...)
            {
                cout << "ValueError: Your data is with some wrong.\n";
            }
        }
        else if (order == "exit")
            break;
        else if (order == "display")
        {
            if (!MapExist)
            {
                cout << "MapError: The map has not been created.\n";
                continue;
            }
            display(&m);
        }
        else if (order == "sweep")
        {
            int x, y;
            try
            {
                cin >> x >> y;
                if (!MapExist)
                {
                    cout << "MapError: The map has not been created.\n";
                    continue;
                }
                if (!check(x, y, &m))
                {
                    cout << "ValueError: Your data is out of range.\n";
                    continue;
                }
                int k = sweep(x, y, &m);
                if (k == 0)
                {
                    cout << "You lose the game!\n";
                    MapExist = false;
                    continue;
                }
                else if (k == 2)
                {
                    cout << "You win the game!\n";
                    MapExist = false;
                    continue;
                }
            }
            catch (...)
            {
                cout << "ValueError: Your data is wrong.\n";
            }
        }
        else if (order == "flag")
        {
            int x, y;
            try
            {
                cin >> x >> y;
                if (!MapExist)
                {
                    cout << "MapError: The map has not been created.\n";
                    continue;
                }
                flag(x, y, &m);
            }
            catch (...)
            {
                cout << "ValueError: Your data is wrong.\n";
            }
        }
        else if (order == "help")
        {
            cout << "order::display() -> None -> [To display your map]\n"
                 << "order::exit() -> None [Exit game]\n"
                 << "order::flag(int coordination-X, int coordination-Y) -> None [To help you mark the mines or cancel mark ]\n"
                 << "order::set(string variable, long double value) -> [Set your game]\n"
                 << "order::show(string variable) -> [To show your variables]\n"
                 << "order::start(int LENGTH, int WIDTH, int MINES) -> None [Start your game]\n"
                 << "order::sweep(int coordination-X, int coordination-Y) -> int sweep one area you choose without mines\n";
        }
        else
            cout << "KeyError: There isn't a command called \"" << order << "\"\n";
    }
    return 0;
}

void fun()
{
    if (variables["author"] == 250)
        cout << "[WARNING] Fuck You!\n";
}