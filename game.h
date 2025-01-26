#include "readfile.h"
#include "linkedlist.h"

class Game {
public:
    Game();
    ~Game();

    void loadCommands(const std::string& filePath);
    void displayMenu();
    void play();
    void addCommand(const Record& record);
    void removeCommand(const std::string& command);
    void displayCommands() const;
    void saveGame(const std::string& filePath) const;

private:
    LinkedList<Record> commandList;
    Node<Record>* findCommand(const std::string& command) const;
};
