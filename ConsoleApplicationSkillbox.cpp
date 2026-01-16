#include <iostream>
#include <cstring>

class Player {
private:
    char* name;
    int score;

public:
    Player() : name(nullptr), score(0) {}

    Player(const char* playerName, int playerScore) : score(playerScore) {
        name = new char[strlen(playerName) + 1];
        strcpy_s(name, strlen(playerName) + 1, playerName);
    }

    ~Player() {
        delete[] name;
    }

    const char* getName() const { return name; }
    int getScore() const { return score; }

    void setName(const char* playerName) {
        delete[] name;
        name = new char[strlen(playerName) + 1];
        strcpy_s(name, strlen(playerName) + 1, playerName);
    }

    void setScore(int playerScore) { score = playerScore; }

    void copyFrom(const Player& other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
        score = other.score;
    }
};

int main() {
    int numPlayers;

    std::cout << "Enter number of players: ";
    std::cin >> numPlayers;
    std::cin.ignore();

    if (numPlayers <= 0) {
        std::cout << "Number of players must be positive!" << std::endl;
        return 1;
    }

    Player* players = new Player[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        char buffer[100];
        int score;

        std::cout << "\nPlayer #" << i + 1 << std::endl;

        std::cout << "Enter player name: ";
        std::cin.getline(buffer, 100);

        std::cout << "Enter score: ";
        std::cin >> score;
        std::cin.ignore();

        players[i].setName(buffer);
        players[i].setScore(score);
    }

    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].getScore() < players[j + 1].getScore()) {
                Player temp;
                temp.copyFrom(players[j]);
                players[j].copyFrom(players[j + 1]);
                players[j + 1].copyFrom(temp);
            }
        }
    }

    std::cout << "\n=== RESULTS (sorted by score) ===" << std::endl;
    for (int i = 0; i < numPlayers; i++) {
        std::cout << i + 1 << ". " << players[i].getName()
            << " - " << players[i].getScore() << " points" << std::endl;
    }

    delete[] players;

    return 0;
}