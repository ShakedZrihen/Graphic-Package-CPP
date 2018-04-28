//
// Created by Shaked Zrihen on 28/04/2018.
//

# pragma once

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;


class ListItem {

    private:
        HANDLE _stdoutHandle;
        COORD _position;
        string _descriptionLabel;



    public:
        // C'tors
        ListItem(short positionX, short positionY, string description);

        // functions
        void draw();

        //D'tors
        ~ListItem();

};