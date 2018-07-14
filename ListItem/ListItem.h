
#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "../Label/Label.h"
#include "../IBorder/IBorderStyle.h"
#include "../IBorder/NoneBorder.h"

using namespace std;


class ListItem : public Control {

	public:
		// C'tors & D'tors
		ListItem(string description);
        ~ListItem(){};

        // Setters & Getters
		string get_text(){return description_label_.get_text();}
        short get_line_length() { return line_length_; }
        void set_parent(Control* parent){parent_ = parent;}
        Control* get_parent(){ return parent_;}
        void set_width(int width){width_ = width;}
        void set_checked_bullet_symbol(string bullet){checked_bullet_symbol_ = bullet;}
        void set_unchecked_bullet_symbol(string bullet){unchecked_bullet_symbol_ = bullet;}
        void set_clickable(bool clickable){is_clickable_ = clickable;}


    // Methods
		void focus();
		void unfocus();
		bool is_focus() { return is_focused_; }
		bool is_checked() { return is_checked_; }
	    void draw(Graphics& g, int x, int y, size_t z);
        void MarkAsUnchecked();
        void MarkAsChecked();
		bool CanGetFocus() { return true; };

        // Event handlers
		bool MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
		bool KeyDown(int keyCode, char character);


    private:
        // Atrributes
        Label description_label_;
        string checked_bullet_symbol_;
        string unchecked_bullet_symbol_;
        short line_length_;
        bool is_checked_;
        bool is_focused_;
        Control* parent_;
        bool is_clickable_;

};