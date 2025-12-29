#include <iostream>
#include "queue.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Queue<int> q;
   // q.pop();
    q.insert(5);
    q.insert(3);
    q.insert(4);
    q.insert(1);
    q.insert(8);
    Queue<int> q2(q);

    cout << "q: " << q;
    cout << "q2: " << q2;

    q.pop();
    q.pop();

    cout << "q: " << q;
    cout << "q2: " << q2;

    q2 = q;

    cout << "q: " << q;
    cout << "q2: " << q2;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}