// thrtry.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <list>
#include <stdlib.h>

using namespace std;

int main() {
    list<int> q;

    thread pump([&] {
        for ( auto i = 0; i < 32; i++ ) {
            q.push_back(rand() % 256);
            this_thread::sleep_for(chrono::milliseconds(512));
        }
    });

    thread feed([&] {
        while ( 42 ) {
            cout << q.front() << endl;
            q.pop_front();

            while (q.empty())
                this_thread::sleep_for(chrono::milliseconds(128));
        }
    });

    pump.join();
    feed.detach();

    return 0;
}



