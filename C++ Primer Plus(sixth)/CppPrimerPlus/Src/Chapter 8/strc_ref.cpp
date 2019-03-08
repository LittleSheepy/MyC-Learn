//strc_ref.cpp -- using structure references
#include <iostream>
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws &target, const free_throws &source);

int main()
{
    free_throws one = {"one Ifelsa Branch", 13, 14};
    free_throws two = {"two Andor Knott", 10, 16};
    free_throws three = {"thr Minnie Max", 7, 9};
    free_throws four = {"for Whily Looper", 5, 9};
    free_throws five = {"fiv Long Long", 6, 14};
    free_throws team = {"team Throwgoods", 13, 14};
    free_throws dup;
    set_pc(one);
    display(one);
	display(team);
    accumulate(team, one);
    display(team);
// use return value as argument
	std::cout << "\n use return value as argument\n";
    display(accumulate(team, two));

    accumulate(accumulate(team, three), four);
    display(team);
// use return value in assignment
    dup = accumulate(team,five);
    std::cout << "Displaying team:\n";
    display(team);
	std::cout << "==============:\n";
	std::cout << &dup << " " << &team << '\n';
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    set_pc(four);
// ill-advised assignment
    accumulate(dup,five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	display(team);
    std::cin.get();
    return 0;
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}
void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f *float(ft.made)/float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}