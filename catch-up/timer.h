#ifndef UNTITLED_TIMER_H
#define UNTITLED_TIMER_H
#include <sstream>
#include <string>
using namespace std;

string intToString(int a)
{
    std::ostringstream ost;
    ost << a;
    std::string s_num = ost.str();
    return s_num;
}
void timer(int &hour,int &min, int &sec)
{
    if (sec > 0) {
        sec--;
    } else if (sec == 0 && min > 0) {
        sec = 59;
        min--;
    } else if (sec == 0 && min == 0 && hour > 0) {
        sec = 59;
        min = 59;
        hour--;
    } else if (sec == 0 && min == 0 && hour == 0) {
        return;
    }
}


#endif //UNTITLED_TIMER_H