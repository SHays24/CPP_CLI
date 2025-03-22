#include <iostream>
#include <string>
#include <unordered_map>
#include <cstddef>
using namespace std;
typedef bool (*ScriptFunction)(string, int (*)());


class command_processor {
    public:
        void addCmd(string name, ScriptFunction function, int argNum) {
            this->commandsMap[name] = *function;
            this->argsMap[name] = argNum;
        }
        ScriptFunction getCommandMap(string name) {
            return this->commandsMap[name];
        }
        int getArgsMap(string name) {
            return this->argsMap[name];
        }
        bool checkCommandExists(string name) {
            return (this->commandsMap.count(name) > 0);
        }
    private:
        unordered_map<string, ScriptFunction> commandsMap;
        unordered_map<string, int> argsMap;
};

int main();

bool test1(string args, int (*callFunc)()) {
    char argsArr[2];
    //cin >> args[0];
    //cin >> args[1];
    const int argsNum = 2;
    //int iterator = 0;
    char arr[argsNum];
    //int argCnt = 0;
    argsArr[0] = args.at(args.find_first_of(' ')+1);
    argsArr[1] = args.at(args.find_first_of(' ', 1)+1);
    cout << "test2\n";
    cout << argsArr[0];
    cout << argsArr[1] << "\n";
    return callFunc();
}

int main() {
    command_processor commProcess;
    cout << "> ";
    string rawCommand;
    getline(cin, rawCommand);
    if (rawCommand.length() <= 1) {
        return main();
    }
    commProcess.addCmd("test", &test1, 2);
    string command = rawCommand.substr(0, rawCommand.find_first_of(' '));
    string args = "";
    if (rawCommand.find_first_of(' ') <= rawCommand.length() && (rawCommand.length() - command.length()) > commProcess.getArgsMap(command)) {
        args = rawCommand.substr(rawCommand.find_first_of(' '));
    } else {
        return main();
    }
    if (commProcess.checkCommandExists(command)) {
        commProcess.getCommandMap(command)(args, &main);
    }
}