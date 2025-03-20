#include <iostream>
#include <string>
#include <unordered_map>
#include <cstddef>
int main();
using namespace std;
typedef bool (*ScriptFunction)(char [], int (*)());
unordered_map<string, ScriptFunction> commandsMap;
bool test1(char args[], int (*callFunc)()) {
    cout << "test2\n";

    cout << args[0];
    cout << args[1] << "\n";
    return callFunc(); 
}
/*int testRunner(int (*callFunc)()) {
    int a = 2;
    int *pA = &a;
    cout << *pA;
    a++;
    cout << *pA << "\n";
    char arr[] = {'a', 'b'};
    return commandsMap["test"](arr, callFunc);
}*/
int main() {
    cout << "> ";
    string rawCommand;
    cin >> rawCommand;
    string command = rawCommand.substr(0, rawCommand.find_first_of(' '));
    commandsMap["test"] = &test1;
    char arr[] = {'a', 'b'};
    if (commandsMap.count(command) > 0) {
        commandsMap[command](arr, &main);
    }
    return main();
}