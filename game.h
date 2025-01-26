#include "readfile.h"
#include "linkedlist.h"
#include <random>

class Game {
private:
    LinkedList<Data> commandList;
    Node<Data>* findCommand(const std::string& command) const;
    std::string playerName;
    int currentScore;
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

    void displayMenu() {
        std::cout << "1. Play Game" << std::endl;
        std::cout << "2. Load Previous Game" << std::endl;
        std::cout << "3. Add Command to Game" << std::endl;
        std::cout << "4. Save Current Game Progress" << std::endl;
        std::cout << "5. View All Commands" << std::endl;
        std::cout << "6. Remove Command" << std::endl;
        std::cout << "7. Exit" << std::endl;
    };
    void menuSelection() {
    int choice = 0;
    do {
        displayMenu();
        std::cin >> choice;

        while (std::cin.fail() || choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                std::cout << "Play Game" << std::endl;
                play();
                break;
            case 2:
                std::cout << "Loading previous instance" << std::endl;
                loadPreviousGame();
                break;
            case 3:
                std::cout << "Adding command" << std::endl;
                promptAddCommand();
                break;
            case 4:
                std::cout << "Saving game" << std::endl;
                saveGame("commands.csv", "profiles.csv", currentScore);
                break;
            case 5:
                std::cout << "View all commands" << std::endl;
                displayCommands();
                break;
            case 6:
                std::cout << "Removing command" << std::endl;
                promptRemoveCommand();
                break;
            case 7:
                std::cout << "Exiting game" << std::endl;
                break;
            default:
                std::cout << "Error" << std::endl;
        }
        std::cout << std::endl;

    } while (choice != 6);
}

    void play() {
    int choice = 0;
    std::cout << "Enter your name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, playerName);

    std::cout << "How many commands would you like to play with, " << playerName << "?" << std::endl;
    std::cout << "1. 5 Commands" << std::endl;
    std::cout << "2. 10 Commands" << std::endl;
    std::cout << "3. 15 Commands" << std::endl;
    

    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please select 1, 2, or 3: ";
        std::cin >> choice;
    }

    int numCommands = (choice == 1) ? 5 : (choice == 2) ? 10 : 15;
    if (commandList.getHead() == nullptr) {
        std::cout << "No commands available to play." << std::endl;
        return;
    }

    std::vector<Data> commands;
    Node<Data>* current = commandList.getHead();
    while (current != nullptr) {
        commands.push_back(current->getData());
        current = current->getNext();
    }

    if (commands.size() < numCommands) {
        std::cout << "Not enough commands to play with " << numCommands << " commands." << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(commands.begin(), commands.end(), gen);
    std::vector<Data> selectedCommands(commands.begin(), commands.begin() + numCommands);

    std::vector<std::string> descriptions;
    for (const auto& cmd : selectedCommands) {
        descriptions.push_back(cmd.description);
    }
    std::shuffle(descriptions.begin(), descriptions.end(), gen);

    std::cout << "Match the commands with their descriptions:" << std::endl;
    for (size_t i = 0; i < selectedCommands.size(); ++i) {
        std::cout << i + 1 << ". " << selectedCommands[i].command << std::endl;
    }
    std::cout << "\nDescriptions:" << std::endl;
    for (size_t i = 0; i < descriptions.size(); ++i) {
        std::cout << i + 1 << ". " << descriptions[i] << std::endl;
    }

    int score = 0;
    for (size_t i = 0; i < selectedCommands.size(); ++i) {
        int descChoice;
        std::cout << "Match command " << selectedCommands[i].command << " to a description (enter number): ";
        std::cin >> descChoice;

        while (std::cin.fail() || descChoice < 1 || descChoice > static_cast<int>(descriptions.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please select a valid description number: ";
            std::cin >> descChoice;
        }

        if (descriptions[descChoice - 1] == selectedCommands[i].description) {
            score += std::stoi(selectedCommands[i].points);
        }
    }

    std::cout << "Final score: " << score << std::endl;
    currentScore = score;
}
    void promptAddCommand() {
    std::string command, description, points;

    std::cout << "Enter the new command: ";
    std::cin.ignore();
    std::getline(std::cin, command);

    std::cout << "Enter the description for the command: ";
    std::getline(std::cin, description);

    std::cout << "Enter the point value for the command: ";
    std::getline(std::cin, points);

    Data newCommand{command, description, points};
    addCommand(newCommand);
}

    void addCommand(const Data& data) {
    Node<Data>* current = commandList.getHead();
    while (current != nullptr) {
        if (current->getData().command == data.command) {
            std::cout << "Error: Command \"" << data.command << "\" already exists in the list." << std::endl;
            return;
        }
        current = current->getNext();
    }

    commandList.insertAtFront(data);
    std::cout << "Command \"" << data.command << "\" added successfully." << std::endl;
    };
    



    void promptRemoveCommand() {
    std::string command;
    std::cout << "Enter the command to remove: ";
    std::cin.ignore();
    std::getline(std::cin, command);

    removeCommand(command);
}

    void removeCommand(const std::string& command) {
    if (commandList.getHead() == nullptr) {
        std::cout << "The command list is empty. Nothing to remove." << std::endl;
        return;
    }

    Node<Data>* current = commandList.getHead();
    Node<Data>* previous = nullptr;

    while (current != nullptr) {
        if (current->getData().command == command) {
            if (previous == nullptr) {
                // Removing the head
                commandList.setHead(current->getNext());
            } else {
                // Removing a node in the middle or end
                previous->setNext(current->getNext());
            }
            delete current;
            std::cout << "Command \"" << command << "\" removed successfully." << std::endl;
            return;
        }
        previous = current;
        current = current->getNext();
    }

    std::cout << "Error: Command \"" << command << "\" not found in the list." << std::endl;
}



    void displayCommands() const {
        commandList.display();
    };

    void saveGame(const std::string& commandsFile, const std::string& profilesFile, int score) {
    std::ofstream commandsOut(commandsFile);
    if (!commandsOut) {
        std::cout << "Error: Unable to open " << commandsFile << " for saving commands." << std::endl;
        return;
    }

    Node<Data>* current = commandList.getHead();
    while (current != nullptr) {
        const Data& data = current->getData();
        commandsOut << data.command << ',' << data.description << ',' << data.points << '\n';
        current = current->getNext();
    }
    commandsOut.close();
    std::cout << "Commands saved to " << commandsFile << "." << std::endl;

    std::ofstream profilesOut(profilesFile, std::ios::app);
    if (!profilesOut) {
        std::cout << "Error: Unable to open " << profilesFile << " for saving player profile." << std::endl;
        return;
    }
    profilesOut << playerName << ',' << score << '\n';
    profilesOut.close();
    std::cout << "Profile saved to " << profilesFile << "." << std::endl;
}

void loadPreviousGame() {
    std::cout << "Enter your name to load your previous game: ";
    std::cin.ignore();
    std::getline(std::cin, playerName);

    std::ifstream profilesIn("profiles.csv");
    if (!profilesIn) {
        std::cout << "Error: profiles.csv not found." << std::endl;
        return;
    }

    bool profileFound = false;
    std::string line;
    while (std::getline(profilesIn, line)) {
        std::istringstream stream(line);
        std::string name, scoreStr;

        if (std::getline(stream, name, ',') && std::getline(stream, scoreStr)) {
            if (name == playerName) {
                currentScore = std::stoi(scoreStr);
                profileFound = true;
                break;
            }
        }
    }
    profilesIn.close();

    if (!profileFound) {
        std::cout << "No profile found for " << playerName << "." << std::endl;
        return;
    }

    std::ifstream commandsIn("commands.csv");
    if (!commandsIn) {
        std::cout << "Error: commands.csv not found." << std::endl;
        return;
    }

    commandList = LinkedList<Data>();
    while (std::getline(commandsIn, line)) {
        std::istringstream stream(line);
        std::string command, description, points;

        if (std::getline(stream, command, ',') && std::getline(stream, description, ',') && std::getline(stream, points)) {
            commandList.insertAtFront(Data{command, description, points});
        }
    }
    commandsIn.close();

    std::cout << "Game successfully loaded for " << playerName << " with score: " << currentScore << "." << std::endl;
}
};
