#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

int main() {
    // A vector to keep track of participants in order of registration
    std::vector<std::string> participants;
    // A set to ensure uniqueness of participant names
    std::set<std::string> uniqueNames;
    // A map to store name -> score
    std::map<std::string, int> scores;

    // Let's pretend we have some incoming data
    // (In real scenarios, we might read from a file or user input)
    std::vector<std::pair<std::string, int>> incomingData = {
        {"Alice", 95},
        {"Bob", 80},
        {"Alice", 97},   // Intentionally repeated name
        {"Charlie", 100},
        {"Diana", 75}
    };

    for (auto &entry : incomingData) {
        const std::string &name = entry.first;
        int score = entry.second;

        // Record the name in the vector
        participants.push_back(name);

        // Insert the name into the set (duplicates won't be added)
        uniqueNames.insert(name);

        // Update or add the score in the map
        // If name doesn't exist yet, it is created automatically.
        // This will overwrite the old score for "Alice"
        scores[name] = score;
    }

    // Display all participants (including duplicates) using vector
    std::cout << "All participants (in order of registration):\n";
    for (auto it = participants.begin(); it != participants.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // Display unique participants using the set
    std::cout << "Unique participants:\n";
    for (auto it = uniqueNames.begin(); it != uniqueNames.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // Display final scores using the map
    std::cout << "Final scores:\n";
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}
