#include "NumericBox.h"
#include <iostream>

using namespace std;


NumericBox::NumericBox(int minValue, int maxValue):
        minVal_(minValue),
        maxVal_(maxValue),
        inc_("+"),
        dec_("-"),
        value_(minValue),
        textValue_(to_string(minValue))
{
    inc_.add(this);
    dec_.add(this);
}

void NumericBox::setMaxValue(int value) {
    maxVal_ = value;
    if (value_ > maxVal_)
        value_ = maxVal_;
}

void NumericBox::setMinValue(int value) {
    minVal_ = value;
    if (value_ > minVal_)
        value_ = minVal_;
}

void NumericBox::setValue(int value) {
    if(value <= maxVal_ && value >= minVal_)
        value_ = value;
}


int NumericBox::getValue() {
    return value_;
}


void NumericBox::inc() {

    if (maxVal_ >= value_+1){
        value_ += 1;
        textValue_.setText(to_string(value_));
    }
}

void NumericBox::dec() {
    if (value_ - 1 >= minVal_) {
        value_ -= 1;
        textValue_.setText(to_string(value_));
    }
}

void NumericBox::action(IObservable* iObservable) {
    if((((Button*)iObservable)->getText().compare ("INC")) == 0){
        inc();
    } else if (!(((Button*)iObservable)->getText().compare("DEC"))) {
        dec();
    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {

};


void NumericBox::draw(Graphics& g, int x, int y, size_t z){
    if(!z){
        inc_.draw(g, 0, 0, 0);
        textValue_.draw(g, 5, 0, 0);
        dec_.draw(g, 0, 7, 0);
    }
}