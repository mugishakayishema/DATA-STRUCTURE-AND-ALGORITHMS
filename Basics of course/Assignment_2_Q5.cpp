//reg number: 224003729
//Names: MUGISHA KAYISHEMA 
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    // Stack: undo feature
    stack<string> undoStack;
    undoStack.push("Action1");
    undoStack.push("Action2");
    cout << "Undo top: " << undoStack.top() << endl;

    // Queue: message feed
    queue<string> messages;
    messages.push("Msg1");
    messages.push("Msg2");
    cout << "First message: " << messages.front() << endl;

    // HashSet: unique tags
    unordered_set<string> tags;
    tags.insert("C++");
    tags.insert("DataStructures");
    tags.insert("C++");
    cout << "Tags count: " << tags.size() << endl;

    // HashMap: user profiles
    unordered_map<int,string> users;
    users[101]="Alice";
    users[102]="Bob";
    cout << "User 101: " << users[101] << endl;

    return 0;
}
