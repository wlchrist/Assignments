#include "readfile.h"
#include "linkedlist.h"

class Game {
private:
    LinkedList<Data> commandList;
    Node<Data>* findCommand(const std::string& command) const;
public:
    Game() : commandList() {};
    ~Game(){};

    void loadCommands() {
        auto optionalList = readAndStore();
        if (optionalList.has_value()){
            commandList = optionalList.value();
        } else {
            std::cout << "Cannot open commands file" << std::endl;
        }
    };

    void displayMenu();
    void play();
    void addCommand(const Data& data);
    void removeCommand(const std::string& command);
    void displayCommands() const {
        commandList.display();
    };
    void saveGame(const std::string& filePath) const;


};
