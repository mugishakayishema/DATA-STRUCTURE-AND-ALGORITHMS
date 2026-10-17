//reg number: 224003729
//Names: MUGISHA Kayishema
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

int main() {

    // 1. Friends (HashSet)
    unordered_set<string> friends;
    friends.insert("Alice");
    friends.insert("Bob");
    friends.insert("Charlie");

    cout << "Friends List:\n";
    for(const auto& f : friends)
        cout << "- " << f << endl;


    // 2. Likes on Posts (HashMap)

    unordered_map<string, int> likes;
    likes["Post1"] = 10;
    likes["Post2"] = 5;
    likes["Post3"] = 20;

    cout << "\nLikes on posts:\n";
    for(const auto& p : likes)
        cout << p.first << ": " << p.second << " likes\n";


    // 3. Newsfeed (PriorityQueue)

    // Higher likes = higher priority
    priority_queue<pair<int,string>> newsfeed;
    for(const auto& p : likes) {
        newsfeed.push({p.second, p.first});
    }

    cout << "\nNewsfeed (sorted by priority/likes):\n";
    while(!newsfeed.empty()) {
        cout << newsfeed.top().second
             << " (" << newsfeed.top().first << " likes)\n";
        newsfeed.pop();
    }


    // 4. User Search (HashMap)
    unordered_map<string,string> users; // username -> full name
    users["alice123"] = "Alice Johnson";
    users["bob456"] = "Bob Smith";

    string searchUser;
    cout << "\nEnter username to search: ";
    cin >> searchUser;

    if(users.find(searchUser) != users.end())
        cout << "User found: " << users[searchUser] << endl;
    else
        cout << "User not found." << endl;

    return 0;
}
